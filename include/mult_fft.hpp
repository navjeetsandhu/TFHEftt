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
void PolyMulNaive(std::array<uint64_t, N_FFT> &res, const std::array<uint64_t, N_FFT>  &a,
                            const std::array<uint64_t, N_FFT>  &b);
void PolyMulNaive(std::array<uint32_t, N_FFT> &res, const std::array<uint32_t, N_FFT>  &a,
                     const std::array<uint32_t, N_FFT>  &b);
