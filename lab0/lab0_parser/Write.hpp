#ifndef Write_h
#define Write_h

#include <fstream>
#include <vector>
#include "Word.hpp"

class Write {
public:
    Write(std::ofstream& out, const std::vector<Word>& sorted_words);
};

#endif
