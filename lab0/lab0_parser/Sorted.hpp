#ifndef Sorted_hpp
#define Sorted_hpp

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
#include "Word.hpp"

class Sorted {
public:
    std::vector<Word> sorted_words;
    static bool compare(const Word& a, const Word& b);
    double percentForWord(int total_word, int frequency);
    Sorted(std::unordered_map<std::string, int> frequency, int count_word);
};

#endif
