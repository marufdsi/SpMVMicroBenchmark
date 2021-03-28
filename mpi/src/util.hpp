//
// Created by maruf on 3/26/21.
//

#ifndef SPMVMICROBENCHMARK_UTIL_HPP
#define SPMVMICROBENCHMARK_UTIL_HPP

#include <unordered_map>
#include <string>

#define MASTER 0

class util {

public:
//    std::unordered_map<std::string, int> ALGORITHMS = std::unordered_map<std::string, int>{
//        { "FMA", 1 },
//        { "SEQUENTIAL_READ", 2 },
//        { "RANDOM_READ", 3 }
//    };

    enum TESTS{
        FUSED_MULTIPLY_ADDITION = 1,
        MEMORY_BANDWIDTH = 2 ,
    };
};


#endif //SPMVMICROBENCHMARK_UTIL_HPP
