//
// Created by Hossain, Md Maruf on 3/27/21.
//

#include "memory_bandwidth.hpp"

void memory_bandwidth::test_memory_bandwidth() {
    const size_t align_bytes = 16;
    const size_t align_alloc_size = mem_size + align_bytes;
    char* dram_array = new char[align_alloc_size];
    char* dram_array_aligned = dram_array + ((uintptr_t)dram_array % align_bytes);

    for (size_t i = 0; i < mem_size; i++) {
        dram_array_aligned[i] = 0;
    }
    std::vector<double> seq_mem_bandwidth = sequential_read(dram_array_aligned, mem_size);
    delete seq_mem_bandwidth;
}

std::vector<double> memory_bandwidth::sequential_read(char *arr, size_t size) {
    std::vector<double> bandwidth;
    __m256i s;
    for (uint32_t iter = 1; iter <= iterations; iter++) {
        const double t0 = MPI_Wtime();
        s = _mm256_setzero_si256();
        __m256i* test_mem = reinterpret_cast<__m256i*>(arr);
        const size_t test_mem_size = size / sizeof(__m256i);

        for (size_t i = 0; i < test_mem_size; i++) {
            s += _mm256_load_si256(test_mem + i);
        }
        const double t1 = MPI_Wtime();
        double time_elapsed = t1 - t0;
        bandwidth.push_back((double)size / time_elapsed);
        std::cout<< iter << " " << time_elapsed << " " << bandwidth.back() << std::endl;
    }
    printf("IGNORE(%llu)\n", _mm256_extract_epi64(s, 0));
    return data;
}