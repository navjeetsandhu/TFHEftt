#pragma once

#include<iostream>
#include <vector>

template <class P>
void print_results(const std::string& msg, const P* result, P size){
    std::cout << msg << ": " << std::endl;
    for (int i = 0; i < size; ++i)
        std::cout <<  result[i] << ' ';

    std::cout << std::endl << std::endl;
}