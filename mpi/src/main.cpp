//
// Created by maruf on 3/26/21.
//
#include <iostream>

#include "fma_on_skylake.hpp"
#include "util.hpp"
#include "memory_bandwidth.hpp"

int main(int argc, char *argv[]){
    int argi=1;
    util my_util;
    if(atoi(argv[argi]) == my_util.FUSED_MULTIPLY_ADDITION) {
        argi++;
        fma_on_skylake fma_obj;
        fma_obj._fma_(argc, argv, argi);
    } else if(atoi(argv[argi]) == my_util.MEMORY_BANDWIDTH) {
        argi++;
        memory_bandwidth memoryBandwidth(10);
        memoryBandwidth.test_memory_bandwidth(argc, argv, argi);
    }
    return 0;
}