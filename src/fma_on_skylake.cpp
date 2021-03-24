#include <stdio.h>
#include <iostream>
#include <omp.h>

#include <math.h>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <unordered_map>

//#include "mpi.h"

const int n_trials = 1000000000; // Enough to keep cores busy for a while and observe a steady state
const int flops_per_calc = 2; // Multiply + add = 2 instructions
const int n_chained_fmas = 9; // Must be tuned for architectures here and in blocks (R) and in (E)

int main(int argc, char *argv[]) {
    int procs = 1;
    if (argc > 1)
        procs = atoi(argv[1]);
#pragma omp parallel
    {} // Warm up the threads

    const double t0 = omp_get_wtime(); // start timer
#pragma omp parallel
    { // Benchmark in all threads
        double fa[VECTOR_WIDTH * n_chained_fmas], fb[VECTOR_WIDTH], fc[VECTOR_WIDTH];

        fa[0:VECTOR_WIDTH * n_chained_fmas] = 0.0; // prototype of a memory-based array
        fb[0:VECTOR_WIDTH] = 0.5; // fixed
        fc[0:VECTOR_WIDTH] = 1.0; // fixed


        register double *fa01 = fa + 0 * VECTOR_WIDTH; // This is block (R)
        register double *fa02 = fa + 1 * VECTOR_WIDTH; // To tune for a specific architecture,
        register double *fa03 = fa + 2 * VECTOR_WIDTH; // more or fewer fa* variables
        register double *fa04 = fa + 3 * VECTOR_WIDTH; // must be used
        register double *fa05 = fa + 4 * VECTOR_WIDTH;
        register double *fa06 = fa + 5 * VECTOR_WIDTH;
        register double *fa07 = fa + 6 * VECTOR_WIDTH;
        register double *fa08 = fa + 7 * VECTOR_WIDTH;
        register double *fa09 = fa + 8 * VECTOR_WIDTH;
//        register double *fa10 = fa + 9 * VECTOR_WIDTH;
//        register double *fa11 = fa + 10 * VECTOR_WIDTH;
//        register double *fa12 = fa + 11 * VECTOR_WIDTH;
//        register double *fa13 = fa + 12 * VECTOR_WIDTH;
//        register double *fa14 = fa + 13 * VECTOR_WIDTH;
//        register double *fa15 = fa + 14 * VECTOR_WIDTH;
//        register double *fa16 = fa + 15 * VECTOR_WIDTH;
//        register double *fa17 = fa + 16 * VECTOR_WIDTH;
//        register double *fa18 = fa + 17 * VECTOR_WIDTH;
//        register double *fa19 = fa + 18 * VECTOR_WIDTH;
//        register double *fa20 = fa + 19 * VECTOR_WIDTH;
//        register double *fa21 = fa + 20 * VECTOR_WIDTH;
//        register double *fa22 = fa + 21 * VECTOR_WIDTH;
//        register double *fa23 = fa + 22 * VECTOR_WIDTH;
//        register double *fa24 = fa + 23 * VECTOR_WIDTH;
//        register double *fa25 = fa + 24 * VECTOR_WIDTH;
//        register double *fa26 = fa + 25 * VECTOR_WIDTH;
//        register double *fa27 = fa + 26 * VECTOR_WIDTH;
//        register double *fa28 = fa + 27 * VECTOR_WIDTH;
//        register double *fa29 = fa + 28 * VECTOR_WIDTH;
//        register double *fa30 = fa + 29 * VECTOR_WIDTH;
//        register double *fa31 = fa + 30 * VECTOR_WIDTH;
//        register double *fa32 = fa + 31 * VECTOR_WIDTH;
//        register double *fa33 = fa + 32 * VECTOR_WIDTH;
//        register double *fa34 = fa + 33 * VECTOR_WIDTH;
//        register double *fa35 = fa + 34 * VECTOR_WIDTH;

        int i, j;
#pragma nounroll // Prevents automatic unrolling by compiler to avoid skewed benchmarks
        for (i = 0; i < n_trials; i++)
#pragma omp simd // Ensures that vectorization does occur
                for (j = 0; j < VECTOR_WIDTH; j++) { // VECTOR_WIDTH=4 for AVX2, =8 for AVX-512
                    fa01[j] = fa01[j] * fb[j] + fc[j]; // This is block (E)
                    fa02[j] = fa02[j] * fb[j] + fc[j]; // To tune for a specific architecture,
                    fa03[j] = fa03[j] * fb[j] + fc[j]; // more or fewer such FMA constructs
                    fa04[j] = fa04[j] * fb[j] + fc[j]; // must be used
                    fa05[j] = fa05[j] * fb[j] + fc[j];
                    fa06[j] = fa06[j] * fb[j] + fc[j];
                    fa07[j] = fa07[j] * fb[j] + fc[j];
                    fa08[j] = fa08[j] * fb[j] + fc[j];
                    fa09[j] = fa09[j] * fb[j] + fc[j];
//                    fa10[j] = fa10[j] * fb[j] + fc[j];
//                    fa11[j] = fa11[j] * fb[j] + fc[j];
//                    fa12[j] = fa12[j] * fb[j] + fc[j];
//                    fa13[j] = fa13[j] * fb[j] + fc[j];
//                    fa14[j] = fa14[j] * fb[j] + fc[j];
//                    fa15[j] = fa15[j] * fb[j] + fc[j];
//                    fa16[j] = fa16[j] * fb[j] + fc[j];
//                    fa17[j] = fa17[j] * fb[j] + fc[j];
//                    fa18[j] = fa18[j] * fb[j] + fc[j];
//                    fa19[j] = fa19[j] * fb[j] + fc[j];
//                    fa20[j] = fa20[j] * fb[j] + fc[j];
//                    fa21[j] = fa21[j] * fb[j] + fc[j];
//                    fa22[j] = fa22[j] * fb[j] + fc[j];
//                    fa23[j] = fa23[j] * fb[j] + fc[j];
//                    fa24[j] = fa24[j] * fb[j] + fc[j];
//                    fa25[j] = fa25[j] * fb[j] + fc[j];
//                    fa26[j] = fa26[j] * fb[j] + fc[j];
//                    fa27[j] = fa27[j] * fb[j] + fc[j];
//                    fa28[j] = fa28[j] * fb[j] + fc[j];
//                    fa29[j] = fa29[j] * fb[j] + fc[j];
//                    fa30[j] = fa30[j] * fb[j] + fc[j];
//                    fa31[j] = fa31[j] * fb[j] + fc[j];
//                    fa32[j] = fa32[j] * fb[j] + fc[j];
//                    fa33[j] = fa33[j] * fb[j] + fc[j];
//                    fa34[j] = fa34[j] * fb[j] + fc[j];
//                    fa35[j] = fa35[j] * fb[j] + fc[j];
                }
        fa[0:VECTOR_WIDTH * n_chained_fmas] *= 2.0; // Prevent dead code elimination
    }
    const double t1 = omp_get_wtime();

    const double gflops = 1.0e-9 * (double) VECTOR_WIDTH * (double) n_trials * (double) flops_per_calc *
                          (double) omp_get_max_threads() * (double) n_chained_fmas;
    printf("Chained FMAs=%d, vector width=%d, GFLOPs=%.1f, time=%.6f s, performance=%.1f GFLOP/s\n",
           n_chained_fmas, VECTOR_WIDTH, gflops, t1 - t0, gflops / (t1 - t0));
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
                << "ChainedFMAs,VectorWidth,GFLOPs,Time,GFLOPSPerSec" << std::endl;
    }
    infile.close();
    resultCSV << n_chained_fmas << "," << VECTOR_WIDTH << "," << gflops << "," << (t1 - t0) << "," << gflops / (t1 - t0)
              << std::endl;
    resultCSV.close();
}
