#include "mult_fft.hpp"

inline void TwistFFT(std::array<uint64_t, N_FFT> &res, const std::array<double, N_FFT> &a)
{
    fftp.execute_direct_torus64(res.data(), a.data());
}

inline void TwistFFT(std::array<uint32_t, N_FFT> &res, const std::array<double, N_FFT> &a)
{
    fftp.execute_direct_torus32(res.data(), a.data());
}

inline void TwistIFFT(std::array<double, N_FFT> &res, const std::array<uint64_t, N_FFT> &a)
{
    fftp.execute_reverse_torus64(res.data(), a.data());
}

inline void TwistIFFT(std::array<double, N_FFT> &res, const std::array<uint32_t, N_FFT> &a)
{
    fftp.execute_reverse_torus32(res.data(), a.data());
}

inline void MulInFD(std::array<double, N_FFT> &res, const std::array<double, N_FFT> &b)
{
    for (int i = 0; i < N_FFT / 2; i++) {
        double aimbim = res[i + N_FFT / 2] * b[i + N_FFT / 2];
        double arebim = res[i] * b[i + N_FFT / 2];
        res[i] = std::fma(res[i], b[i], -aimbim);
        res[i + N_FFT / 2] = std::fma(res[i + N_FFT / 2], b[i], arebim);
    }
}

void PolyMulFFT(std::array<uint64_t, N_FFT> &res, const std::array<uint64_t, N_FFT>  &a,
                const std::array<uint64_t, N_FFT>  &b)
{
    alignas(64) std::array<double, N_FFT> ffta{};
    TwistIFFT(ffta, a);
    alignas(64) std::array<double, N_FFT> fftb{};
    TwistIFFT(fftb, b);
    MulInFD(ffta, fftb);
    TwistFFT(res, ffta);
}

void PolyMulFFT(std::array<uint32_t, N_FFT>& res, const std::array<uint32_t,N_FFT> &a,
                       const std::array<uint32_t, N_FFT> & b)
{
    alignas(64) std::array<double, N_FFT> ffta{};
    TwistIFFT(ffta, a);
    alignas(64) std::array<double, N_FFT> fftb{};
    TwistIFFT(fftb, b);
    MulInFD(ffta, fftb);
    TwistFFT(res, ffta);
}




