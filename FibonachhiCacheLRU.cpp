#include "FibonachhiCacheLRU.hpp"
#include "ICache.hpp"

int FibonachhiCacheLRU::get(int key) {
    auto it = Cache.find(key);
    if (it == Cache.end()) {
        return -1;
    }
    KeyList.splice(KeyList.begin(), KeyList, it->second );
    return it->second->second;
}

void FibonachhiCacheLRU::put(int key, int value) {
    auto it = Cache.find(key);
    if (it != Cache.end()) {
        KeyList.erase(it->second);
        Cache.erase(it);
    }
    if (Cache.size() == size) {
        Cache.erase(KeyList.back().first);
        KeyList.pop_back();
    }
    KeyList.push_front({key, value});
    Cache[key] = KeyList.begin();
}

int FibonachhiCacheLRU::operator[](int key) {
    return get(key);
}