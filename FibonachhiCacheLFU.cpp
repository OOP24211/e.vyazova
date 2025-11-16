#include "FibonachhiCacheLFU.hpp"
#include "ICache.hpp"

#include <iostream>
#include <list>
#include <unordered_map>

int FibonachhiCacheLFU::get(int key) {
    auto it = Cache.find(key);
    if (it == Cache.end()) {
        return -1;
    }
    Node& value = Cache[key];
    int f = value.freq;
    FreqKey[f].erase(value.it);
    value.freq++;
    FreqKey[f+1].push_back(key);
    value.it = --FreqKey[f+1].end();
    return value.value;
}

void FibonachhiCacheLFU::put(int key, int value) {
    auto it = Cache.find(key);
    if (it != Cache.end()) {
        Cache[key].value = value;
        get(key);
        return;
    }
    else {
        if (Cache.size() == size ) {
            int KeyRemove = FreqKey[minFreq].front();
            FreqKey[minFreq].pop_front();
            Cache.erase(KeyRemove);
        }
    }
    Node newNode;
    newNode.value = value;
    newNode.freq = 1;
    FreqKey[1].push_back(key);
    newNode.it = --FreqKey[1].end();
    Cache[key] = newNode;
    minFreq = 1;
}

int FibonachhiCacheLFU::operator[](int key) {
    return get(key);
}


