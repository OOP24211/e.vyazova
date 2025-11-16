#include "ICache.hpp"
#ifndef GeneralClass_h
#define GeneralClass_h

class GeneralClass {
private: ICache& cache;
    int FibCalculator(int num);
public:
    GeneralClass(ICache& c) : cache(c) {}
    void RunConsole();
};

#endif