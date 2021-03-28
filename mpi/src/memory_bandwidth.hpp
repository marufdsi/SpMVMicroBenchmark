//
// Created by Hossain, Md Maruf on 3/27/21.
//

#ifndef SPMVMICROBENCHMARK_MEMORY_BANDWIDTH_HPP
#define SPMVMICROBENCHMARK_MEMORY_BANDWIDTH_HPP

#include <iostream>
#include <immintrin.h>
#include <limits>
#include <random>

#include "util.hpp"

class memory_bandwidth {
private:
    int nRanks;
    int rank;
    int procs;
public:
    uint32_t iterations;
    uint32_t skip;
    uint32_t mem_size;
    memory_bandwidth(int procs, size_t mem_size=1000000, uint32_t iterations=10, uint32_t skip=5):procs(procs), mem_size(mem_size), iterations(iterations), skip(skip){}
    memory_bandwidth(){
        procs=1;
        mem_size=1000000;
        iterations=10;
        skip=5;
    }
    void test_memory_bandwidth(int argc, char* argv[], int argi);

    std::pair<double, double> sequential_read(char* arr, size_t size);
    std::vector<std::pair<double, double> > random_read(char* arr, size_t size);
    std::vector<std::pair<double, double> > sequential_write(char* arr, size_t size);
    std::vector<std::pair<double, double> > random_write(char* arr, size_t size);

};


#endif //SPMVMICROBENCHMARK_MEMORY_BANDWIDTH_HPP
