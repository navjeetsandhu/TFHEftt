#include <array>
#include <fft_processor_spqlios.h>

inline void TwistFFT(std::array<uint64_t, N_FFT> &res, const std::array<double, N_FFT> &a);

inline void TwistFFT(std::array<uint32_t, N_FFT> &res, const std::array<double, N_FFT> &a);

inline void TwistIFFT(std::array<double, N_FFT> &res, const std::array<uint64_t, N_FFT> &a);

inline void TwistIFFT(std::array<double, N_FFT> &res, const std::array<uint32_t, N_FFT> &a);

inline void MulInFD(std::array<double, N_FFT> &res, const std::array<double, N_FFT> &b);

void PolyMulFFT(std::array<uint64_t, N_FFT> &res, const std::array<uint64_t, N_FFT>  &a,
                  const std::array<uint64_t, N_FFT>  &b);
void PolyMulFFT(std::array<uint32_t, N_FFT>& res, const std::array<uint32_t,N_FFT> &a,
                       const std::array<uint32_t, N_FFT> &b);


template <class P, int N>
void PolyMulNaive(std::array<P, N> &res, const std::array<P, N>  &a,
                     const std::array<P, N>  &b){
    for (int i = 0; i < N; i++) {
        P ri = 0;
        for (int j = 0; j <= i; j++)
            ri += static_cast<typename std::make_signed<P>::type>(
                          a[j]) *
                  b[i - j];
        for (int j = i + 1; j < N; j++)
            ri -= static_cast<typename std::make_signed<P>::type>(
                          a[j]) *
                  b[N + i - j];
        res[i] = ri;
    }
}
