#ifndef FibonachhiCacheLRU_hpp
#define FibonachhiCacheLRU_hpp

#include "ICache.hpp"
#include <list>
#include <map>

class FibonachhiCacheLRU : public  ICache{
private:
    std::list<std::pair<int, int>> KeyList;
    std::map<int, std::list<std::pair<int, int>>::iterator> Cache;
    size_t size;
public:
    FibonachhiCacheLRU(size_t size) : size(size) {}
    int get(int key);
    void put(int key, int value);
    int operator[](int key);
};
#endif
