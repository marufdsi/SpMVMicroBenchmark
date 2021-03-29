//
// Created by Hossain, Md Maruf on 3/27/21.
//

#include "memory_bandwidth.hpp"
#include "mpi.h"
#include <omp.h>
#include <math.h>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

void memory_bandwidth::test_memory_bandwidth(int argc, char* argv[], int argi) {

    /* Initialize MPI */
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nRanks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const size_t align_bytes = 16;
    const size_t align_alloc_size = mem_size + align_bytes;
    char* dram_array = new char[align_alloc_size];
    char* dram_array_aligned = dram_array + ((uintptr_t)dram_array % align_bytes);

    for (size_t i = 0; i < mem_size; i++) {
        dram_array_aligned[i] = i%20;
    }
    MPI_Barrier(MPI_COMM_WORLD);
    std::pair<double, double> seq_mem_bandwidth = sequential_read(dram_array_aligned, mem_size);
    MPI_Barrier(MPI_COMM_WORLD);
    if(rank == MASTER){
        std::ofstream resultCSV;
        std::string folderName = "Results/";
        std::string fileName = procs == 2 ? "SEQ_READ_ON_CASCADE_LAKE.csv" : "SEQ_READ_ON_SKYLAKE.csv";
        if (mkdir(folderName.c_str(), 0777) == -1)
            std::cout << "Directory " << folderName << " is already exist" << std::endl;
        else
            std::cout << "Directory " << folderName << " created" << std::endl;
        std::ifstream infile(folderName + fileName);
        resultCSV.open(folderName + fileName, std::ios_base::out | std::ios_base::app | std::ios_base::ate);

        if (!infile.good()) {
            resultCSV << "Size,AvgTime,AvgBandwidth,Processes" << std::endl;
        }
        infile.close();
        resultCSV << mem_size << "," << seq_mem_bandwidth.first << "," << seq_mem_bandwidth.second << "," << nRanks << std::endl;

        resultCSV.close();
    }
    delete dram_array;
    MPI_Finalize();
}

std::pair<double, double> memory_bandwidth::sequential_read(char *arr, size_t size) {
    std::pair<double, double> results;
    __m256i s = _mm256_setzero_si256();
    double avg_time = 0, avg_bandwidth = 0;
    double t_start=0, t_end=0;
    const size_t test_mem_size = size / sizeof(__m256i);
    __m256i* test_mem = reinterpret_cast<__m256i*>(arr);
    for (uint32_t iter = 1; iter <= iterations+skip; iter++) {
        if (iter == skip) {
            t_start = MPI_Wtime ();
        }
        for (size_t i = 0; i < test_mem_size; i++) {
            s += _mm256_load_si256(test_mem + i);
        }
    }
    t_end = MPI_Wtime();
    double time_elapsed = (t1 - t0);
    double bandwidth = ((double) size * iterations) / time_elapsed;

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&time_elapsed, &avg_time, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
    avg_time /= nRanks;

    MPI_Reduce(&bandwidth, &avg_bandwidth, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
    avg_bandwidth /= nRanks;
    results = std::make_pair(avg_time, avg_bandwidth);
    if(rank == MASTER)
        std::cout << avg_time << " " << avg_bandwidth << std::endl;

    unsigned long long sum = _mm256_extract_epi64(s, 0);
    std::cout<< "IGNORE( " << sum << " )" << std::endl;
    return results;
}