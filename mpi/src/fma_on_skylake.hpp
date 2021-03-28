//
// Created by maruf on 3/26/21.
//

#ifndef SPMVMICROBENCHMARK_FMA_ON_SKYLAKE_HPP
#define SPMVMICROBENCHMARK_FMA_ON_SKYLAKE_HPP

#include "util.hpp"

#define VAL(X) (X)
#ifndef N_CHAINED_FMAS
N_CHAINED_FMAS = 8
#endif

class fma_on_skylake {
public:
    const int n_trials = 1000000000; // Enough to keep cores busy for a while and observe a steady state
    const int flops_per_calc = 2; // Multiply + add = 2 instructions
    const int n_chained_fmas = VAL(N_CHAINED_FMAS); // Must be tuned for architectures here and in blocks (R) and in (E)

    int _fma_(int argc, char *argv[], int argi);
};

#endif //SPMVMICROBENCHMARK_FMA_ON_SKYLAKE_HPP
