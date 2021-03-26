#include <stdio.h>
#include <iostream>
#include <omp.h>

#include <math.h>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <unordered_map>
#include "mpi.h"


#define VAL(X) (X)
const int n_trials = 1000000000; // Enough to keep cores busy for a while and observe a steady state
const int flops_per_calc = 2; // Multiply + add = 2 instructions
#ifndef N_CHAINED_FMAS
N_CHAINED_FMAS = 8
#endif
const int n_chained_fmas = VAL(N_CHAINED_FMAS); // Must be tuned for architectures here and in blocks (R) and in (E)
const int MASTER = 0;

int _fma_(int argc, char *argv[]) {
    int nRanks, rank;
    /* Initialize MPI */
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nRanks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int procs = 1;
    if (argc > 1)
        procs = atoi(argv[1]);
    MPI_Barrier(MPI_COMM_WORLD);
    const double t0 = MPI_Wtime();  // start timer
//    const double t0 = omp_get_wtime();  // start timer
    // Benchmark in all threads
    double fa[VECTOR_WIDTH * n_chained_fmas], fb[VECTOR_WIDTH], fc[VECTOR_WIDTH];

    fa[0:VECTOR_WIDTH * n_chained_fmas] = 0.0; // prototype of a memory-based array
    fb[0:VECTOR_WIDTH] = 0.5; // fixed
    fc[0:VECTOR_WIDTH] = 1.0; // fixed

# if N_CHAINED_FMAS >= 1
    register double *fa01 = fa + 0 * VECTOR_WIDTH; // This is block (R)
#endif
# if N_CHAINED_FMAS >= 2
    register double *fa02 = fa + 1 * VECTOR_WIDTH; // To tune for a specific architecture,
#endif
# if N_CHAINED_FMAS >= 3
    register double *fa03 = fa + 2 * VECTOR_WIDTH; // more or fewer fa* variables
#endif
# if N_CHAINED_FMAS >= 4
    register double *fa04 = fa + 3 * VECTOR_WIDTH; // must be used
#endif
# if N_CHAINED_FMAS >= 5
    register double *fa05 = fa + 4 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 6
    register double *fa06 = fa + 5 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 7
    register double *fa07 = fa + 6 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 8
    register double *fa08 = fa + 7 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 9
    register double *fa09 = fa + 8 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 10
    register double *fa10 = fa + 9 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 11
    register double *fa11 = fa + 10 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 12
    register double *fa12 = fa + 11 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 13
    register double *fa13 = fa + 12 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 14
    register double *fa14 = fa + 13 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 15
    register double *fa15 = fa + 14 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 16
    register double *fa16 = fa + 15 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 17
    register double *fa17 = fa + 16 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 18
    register double *fa18 = fa + 17 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 19
    register double *fa19 = fa + 18 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 20
    register double *fa20 = fa + 19 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 21
    register double *fa21 = fa + 20 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 22
    register double *fa22 = fa + 21 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 23
    register double *fa23 = fa + 22 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 24
    register double *fa24 = fa + 23 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 25
    register double *fa25 = fa + 24 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 26
    register double *fa26 = fa + 25 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 27
    register double *fa27 = fa + 26 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 28
    register double *fa28 = fa + 27 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 29
    register double *fa29 = fa + 28 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 30
    register double *fa30 = fa + 29 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 31
    register double *fa31 = fa + 30 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 32
    register double *fa32 = fa + 31 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 33
    register double *fa33 = fa + 32 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 34
    register double *fa34 = fa + 33 * VECTOR_WIDTH;
#endif
# if N_CHAINED_FMAS >= 35
    register double *fa35 = fa + 34 * VECTOR_WIDTH;
#endif

    int i, j;
#pragma nounroll // Prevents automatic unrolling by compiler to avoid skewed benchmarks
    for (i = 0; i < n_trials; i++) {
#pragma omp simd // Ensures that vectorization does occur
        for (j = 0; j < VECTOR_WIDTH; j++) { // VECTOR_WIDTH=4 for AVX2, =8 for AVX-512
# if N_CHAINED_FMAS >= 1
            fa01[j] = fa01[j] * fb[j] + fc[j]; // This is block (E)
#endif
# if N_CHAINED_FMAS >= 2
            fa02[j] = fa02[j] * fb[j] + fc[j]; // To tune for a specific architecture,
#endif
# if N_CHAINED_FMAS >= 3
            fa03[j] = fa03[j] * fb[j] + fc[j]; // more or fewer such FMA constructs
#endif
# if N_CHAINED_FMAS >= 4
            fa04[j] = fa04[j] * fb[j] + fc[j]; // must be used
#endif
# if N_CHAINED_FMAS >= 5
            fa05[j] = fa05[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 6
            fa06[j] = fa06[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 7
            fa07[j] = fa07[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 8
            fa08[j] = fa08[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 9
            fa09[j] = fa09[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 10
            fa10[j] = fa10[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 11
            fa11[j] = fa11[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 12
            fa12[j] = fa12[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 13
            fa13[j] = fa13[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 14
            fa14[j] = fa14[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 15
            fa15[j] = fa15[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 16
            fa16[j] = fa16[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 17
            fa17[j] = fa17[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 18
            fa18[j] = fa18[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 19
            fa19[j] = fa19[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 20
            fa20[j] = fa20[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 21
            fa21[j] = fa21[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 22
            fa22[j] = fa22[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 23
            fa23[j] = fa23[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 24
            fa24[j] = fa24[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 25
            fa25[j] = fa25[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 26
            fa26[j] = fa26[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 27
            fa27[j] = fa27[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 28
            fa28[j] = fa28[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 29
            fa29[j] = fa29[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 30
            fa30[j] = fa30[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 31
            fa31[j] = fa31[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 32
            fa32[j] = fa32[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 33
            fa33[j] = fa33[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 34
            fa34[j] = fa34[j] * fb[j] + fc[j];
#endif
# if N_CHAINED_FMAS >= 35
            fa35[j] = fa35[j] * fb[j] + fc[j];
#endif
        }
    }
    fa[0:VECTOR_WIDTH * n_chained_fmas] *= 2.0; // Prevent dead code elimination
    const double t1 = MPI_Wtime();
//    const double t1 = omp_get_wtime();
    MPI_Barrier(MPI_COMM_WORLD);

    const double gflops = 1.0e-9 * (double) VECTOR_WIDTH * (double) n_trials * (double) flops_per_calc *
                          (double) n_chained_fmas;
    double time = (t1 - t0);
    double bandwidth = gflops / time;
    double avg_time = 0, max_time, avg_gflops = 0, max_gflops = 0, avg_bandwidth = 0, max_bandwidth = 0;
    MPI_Reduce(&time, &avg_time, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
    MPI_Reduce(&time, &max_time, 1, MPI_DOUBLE, MPI_MAX, MASTER, MPI_COMM_WORLD);
    avg_time /= nRanks;

    MPI_Reduce(&gflops, &avg_gflops, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
    MPI_Reduce(&gflops, &max_gflops, 1, MPI_DOUBLE, MPI_MAX, MASTER, MPI_COMM_WORLD);
    avg_gflops /= nRanks;

    MPI_Reduce(&bandwidth, &avg_bandwidth, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
    MPI_Reduce(&bandwidth, &max_bandwidth, 1, MPI_DOUBLE, MPI_MAX, MASTER, MPI_COMM_WORLD);
    avg_bandwidth /= nRanks;
    printf("Rank=%d, Chained FMAs=%d, vector width=%d, GFLOPs=%.1f, time=%.6f s, performance=%.1f GFLOP/s\n", rank,
           n_chained_fmas, VECTOR_WIDTH, gflops, t1 - t0, gflops / (t1 - t0));

    if (rank == MASTER) {
        std::ofstream resultCSV;
        std::string folderName = "Results/";
        std::string fileName = procs == 2 ? "FMA_ON_CASCADE_LAKE.csv" : "FMA_ON_SKYLAKE.csv";
        if (mkdir(folderName.c_str(), 0777) == -1)
            std::cout << "Directory " << folderName << " is already exist" << std::endl;
        else
            std::cout << "Directory " << folderName << " created" << std::endl;
        std::ifstream infile(folderName + fileName);
        resultCSV.open(folderName + fileName, std::ios_base::out | std::ios_base::app | std::ios_base::ate);

        if (!infile.good()) {
            resultCSV
                    << "ChainedFMAs,VectorWidth,AvgGFLOPs,MaxGFLOPs,AvgTime,MaxTime,AvgGFLOPSPerSec,MaxGFLOPSPerSec,Processes"
                    << std::endl;
        }
        infile.close();
        resultCSV << n_chained_fmas << "," << VECTOR_WIDTH << "," << avg_gflops << "," << max_gflops << "," << avg_time
                  << "," << max_time << "," << avg_bandwidth << "," << max_bandwidth << "," << nRanks << std::endl;
        resultCSV.close();
    }
    MPI_Finalize();
    return 0;
}
