//
// Created by maruf on 3/26/21.
//

#ifndef SPMVMICROBENCHMARK_FMA_ON_SKYLAKE_HPP
#define SPMVMICROBENCHMARK_FMA_ON_SKYLAKE_HPP

#include "utill.hpp"

class fma_on_skylake : utill{
public:
    fma_on_skylake();
    int _fma_(int argc, char *argv[]);
};

#endif //SPMVMICROBENCHMARK_FMA_ON_SKYLAKE_HPP
