#include <iostream>
#include <vector>
#include "file.h"
#include <unistd.h>
#include <limits.h>

int print_current_directory() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working dir: " << cwd << std::endl;
    } else {
        std::cerr << "getcwd() error" << std::endl;
        return 1;
    }
    return 0;
}

int  read_data_from_file(std::string file_name, std::vector<uint64_t>& data) {
    std::cout << std::endl << "Reading from  " << file_name << std::endl;

    std::ifstream file(file_name);
    if (!file)
    {
        print_current_directory();
        std::cerr << "Unable to open " << file_name << std::endl;
        return -1;
    }

    uint32_t value;
    while (file >> value)
    {
        // Push each value into the vector
        data.push_back(value);
    }

    file.close();
    return 0;
}
