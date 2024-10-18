#include<iostream>
#include "mult_ntt_hexl.hpp"


std::unique_ptr<intel::hexl::NTT> create_ntt(uint64_t N, uint64_t modulus) {
    auto ntt = std::make_unique<intel::hexl::NTT>(N, modulus);
    return ntt;
}

void poly_mult_ntt(uint64_t *result, const uint64_t *p1, const uint64_t *p2,
                       uint64_t degree, uint64_t modulus) {
    auto ntt = create_ntt(degree, modulus);
    std::vector<uint64_t> output(degree), p1_output(degree), p2_output(degree);
    hexl::compute_forward(p1_output.data(), p1, *ntt);
    hexl::compute_forward(p2_output.data(), p2, *ntt);
    hexl::eltwise_mult_mod(output.data(), p1_output.data(),
                     p2_output.data(), degree, modulus);
    hexl::compute_inverse(result, output.data(), *ntt);
}


