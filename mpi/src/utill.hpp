//
// Created by maruf on 3/26/21.
//

#ifndef SPMVMICROBENCHMARK_UTILL_HPP
#define SPMVMICROBENCHMARK_UTILL_HPP

#include <unordered_map>
#include <string>

#define MASTER 0

class utill {
    std::unordered_map<std::string, int> ALGORITHMS( {
        { "FMA", 1 },
        { "SEQUENTIAL_READ", 2 },
        { "RANDOM_READ", 3 }
    }
    );

//    std::enum ALGO_NAMES{
//        FMA,
//        SEQUENTIAL_READ,
//        RANDOM_READ
//    };
};


#endif //SPMVMICROBENCHMARK_UTILL_HPP
