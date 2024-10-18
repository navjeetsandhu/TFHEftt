#pragma once
#include "mult_ntt_hexl.hpp"

namespace hexl {

    inline void compute_inverse(uint64_t *result,
                                const uint64_t *operand,
                                intel::hexl::NTT& ntt){
        ntt.ComputeInverse(result, operand, 1, 1);
    }

    inline void compute_forward(uint64_t *result,
                                const uint64_t *operand,
                                intel::hexl::NTT& ntt) {
        ntt.ComputeForward(result, operand, 1, 1);
    }

    inline void eltwise_mult_mod(uint64_t *result,
                                 const uint64_t *p1,
                                 const uint64_t *p2,
                                 uint64_t degree,
                                 uint64_t modulus) {
        intel::hexl::EltwiseMultMod(result, p1, p2, degree, modulus,1);
    }
}
