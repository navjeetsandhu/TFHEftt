#pragma once
#include "INTorus.hpp"
#include "hexl/hexl.hpp"
#include "utils.hpp"

namespace hexl {

    // Biggest prime number less than 2^30 and satisfies 1 mod 2N.
    //constexpr uint64_t moduli = 1073707009;
    //constexpr uint64_t moduli = 136314881;
    // Biggest prime number less than 2^62 and satisfies 1 mod 2N.
    constexpr uint64_t moduli = 4611686018427365377ULL;


    template<class T, int N>
    inline void TwistNTT(std::array<T, N> &res, std::array<cuHEpp::INTorus, N> &a) {
        std::array<uint64_t, N> temp{};
        static intel::hexl::NTT nttlvl1(N, moduli);
        nttlvl1.ComputeInverse(temp.data(), &(a[0].value), 1, 1);
        for (int i = 0; i < N; i++) res[i] = temp[i];
    }

    template<class T, int N>
    inline void TwistINTT(std::array<cuHEpp::INTorus, N> &res,
                          const std::array<T, N> &a) {
        std::array<uint64_t, N> temp{};
        for (int i = 0; i < N; i++) temp[i] = a[i];
        static intel::hexl::NTT nttlvl1(N, moduli);
        nttlvl1.ComputeForward(&(res[0].value), temp.data(), 1, 1);
    }

    template<class T, int N>
    void PolyMulNTT(std::array<T, N> &res, const std::array<T, N> &a,
                    const std::array<T, N> &b) {

        std::array<cuHEpp::INTorus, N> ntta, nttb;
        TwistINTT<T, N>(ntta, a);
        TwistINTT<T, N>(nttb, b);

        for (int i = 0; i < N; i++) ntta[i] *= nttb[i];
        TwistNTT<T, N>(res, ntta);
    }
}
