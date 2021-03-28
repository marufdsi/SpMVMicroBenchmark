//
// Created by Hossain, Md Maruf on 3/27/21.
//

#ifndef SPMVMICROBENCHMARK_MEMORY_BANDWIDTH_HPP
#define SPMVMICROBENCHMARK_MEMORY_BANDWIDTH_HPP

#include <immintrin.h>
#include <limits>
#include <random>

#include "utill.hpp"

class memory_bandwidth {
private:
public:
    uint32_t iterations;
    uint32_t mem_size;
    memory_bandwidth(size_t mem_size = 1000000, uint32_t iterations=10):mem_size(mem_size), iterations(iterations);
    memory_bandwidth(uint32_t iterations=10):mem_size(1000000), iterations(iterations);

    void test_memory_bandwidth();

    std::vector<double> sequential_read(char* arr, size_t size);
    std::vector<double> random_read(char* arr, size_t size);
    std::vector<double> sequential_write(char* arr, size_t size);
    std::vector<double> random_write(char* arr, size_t size);

};


#endif //SPMVMICROBENCHMARK_MEMORY_BANDWIDTH_HPP
