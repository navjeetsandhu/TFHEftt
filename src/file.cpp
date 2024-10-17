#include <iostream>
#include <vector>
#include <unistd.h>

int print_current_directory() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working dir: " << cwd << std::endl;
    } else {
        std::cerr << "getcwd() error" << std::endl;
        return 1;
    }
    return 0;
}

