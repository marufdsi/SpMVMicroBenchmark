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
public:
    uint32_t iterations;
    uint32_t skip;
    uint32_t mem_size;
    memory_bandwidth(size_t mem_size, uint32_t iterations, uint32_t skip=5):mem_size(mem_size), iterations(iterations), skip(skip){}
    memory_bandwidth(uint32_t iterations):iterations(iterations){
        mem_size = 1000000 ;
        skip = 5;
    }
    memory_bandwidth(){
        mem_size = 1000000 ;
        iterations = 10 ;
        skip = 5;
    }

    void test_memory_bandwidth(int argc, char* argv[], int argi);

    std::vector<std::pair<double, double> > sequential_read(char* arr, size_t size);
    std::vector<std::pair<double, double> > random_read(char* arr, size_t size);
    std::vector<std::pair<double, double> > sequential_write(char* arr, size_t size);
    std::vector<std::pair<double, double> > random_write(char* arr, size_t size);

};


#endif //SPMVMICROBENCHMARK_MEMORY_BANDWIDTH_HPP
