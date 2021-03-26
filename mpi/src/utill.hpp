//
// Created by maruf on 3/26/21.
//

#ifndef SPMVMICROBENCHMARK_UTILL_H
#define SPMVMICROBENCHMARK_UTILL_H

#define VAL(X) (X)
#ifndef N_CHAINED_FMAS
N_CHAINED_FMAS = 8
#endif
class utill {

public:
    const int n_trials = 1000000000; // Enough to keep cores busy for a while and observe a steady state
    const int flops_per_calc = 2; // Multiply + add = 2 instructions
    const int n_chained_fmas = VAL(N_CHAINED_FMAS); // Must be tuned for architectures here and in blocks (R) and in (E)
    const int MASTER = 0;
};


#endif //SPMVMICROBENCHMARK_UTILL_H
