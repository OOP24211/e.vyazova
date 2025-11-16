#include "ICache.hpp"
#include "GeneralClass.hpp"

#include <iostream>

void GeneralClass::RunConsole() {
    std::cout << "Type 'esc' to exit\n" << std::endl;
    while (true) {
        int num;
        std::cin >> num;
        if (num != 0) {
            int res = FibCalculator(num);
            std::cout << res << "\n" << std::endl;
        }
    }
}
int GeneralClass::FibCalculator(int num) {
    int value = cache[num];
    if (value != -1) {
        return value;
    }
    if (num == 0) {
        return 0;
    }
    if (num == 1 || num == 2) {
        return 1;
    }

    int res = FibCalculator(num - 1) + FibCalculator(num - 2);
    cache.put(num, res);
    return res;
}