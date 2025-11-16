#ifndef FibonachhiCacheLFU_hpp
#define FibonachhiCacheLFU_hpp

#include "ICache.hpp"
#include <list>
#include <unordered_map>

class FibonachhiCacheLFU : public ICache {
private:
    struct Node {
        int value;
        int freq;
        std::list<int>::iterator it;
    };
    std::unordered_map<int, Node> Cache;
    std::unordered_map<int, std::list<int>> FreqKey;
    int size;
    int minFreq;

public:
    FibonachhiCacheLFU(size_t size) : size(size), minFreq(0) {}
    int get(int key);
    void put(int key, int value);
    int operator[](int key);
};

#endif
