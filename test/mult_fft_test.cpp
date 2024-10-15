#include "mult_fft.hpp"
#include"utils.hpp"


template <int N>
void test_mult_fft(const std::array<uint64_t, N>& p1, const std::array<uint64_t, N>& p2)
{

    std::string string_msg = "Naive 64 bit Multiplication";
    print_results<uint64_t>("Input p1", p1.data(), p1.size());
    print_results<uint64_t>("Input p2", p2.data(), p1.size());
    std::array<uint64_t, N> result = {0,0,0,0};
    PolyMulNaive<uint64_t, N>(result, p1, p2);
    print_results<int64_t>(string_msg,  reinterpret_cast<int64_t*>(result.data()), result.size());


    std::fill(result.begin(), result.end(), 0);
    PolyMulFFT<uint64_t, N>(result, p1, p2);
    string_msg = "FFT 64 bit Multiplication";
    print_results<int64_t>(string_msg,  reinterpret_cast<int64_t*>(result.data()), result.size());
}

template <int N>
void test_mult_fft(const std::array<uint32_t, N>& p1, const std::array<uint32_t, N>& p2)
{

    std::string string_msg = "Naive 32 bit Multiplication";
    print_results<uint32_t>("Input p1", p1.data(), p1.size());
    print_results<uint32_t>("Input p2", p2.data(), p1.size());
    std::array<uint32_t, N> result = {0,0,0,0};
    PolyMulNaive<uint32_t, N>(result, p1, p2);
    print_results<int32_t>(string_msg,  reinterpret_cast<int32_t*>(result.data()), result.size());

    std::fill(result.begin(), result.end(), 0);
    PolyMulFFT<uint32_t, N>(result, p1, p2);
    string_msg = "FFT 32 bit Multiplication";
    print_results<int32_t>(string_msg,  reinterpret_cast<int32_t*>(result.data()), result.size());
}


template <class P, int N>
void test_mult_fft()
{
    // make sure set N_FFT to 16 before testing
    std::array<P,  N> p1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    std::array<P,  N> p2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 21, 22, 23, 24, 25, 26};
    test_mult_fft<N>(p1, p2);
}

int main()
{
    // make sure set N_FFT to 16 before testing
    test_mult_fft<uint32_t, N_FFT>();
    test_mult_fft<uint64_t, N_FFT>();
    return 0;
}