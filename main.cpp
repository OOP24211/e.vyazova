#include <iostream>
#include "ICache.hpp"
#include "GeneralClass.hpp"
#include "FibonachhiCacheLFU.hpp"
#include "FibonachhiCacheLRU.hpp"

int main() {
    std::cout << "Please enter a size for cahce:\n" << std::endl;
    size_t size;
    std::cin >> size;

    std::cout << "Please choose type cache:\n" << std::endl;
    std::cout << "LRU - press '0' \t LFU - press '1' \n" << std::endl;
    int type;
    std::cin >> type;

    if (type == 0) {
        FibonachhiCacheLRU cache(size);
        GeneralClass program(cache);
        program.RunConsole();
    }
    else {
        FibonachhiCacheLFU cache(size);
        GeneralClass program(cache);
        program.RunConsole();
    }
    return 0;
}