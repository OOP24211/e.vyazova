#ifndef Frequency_hpp
#define Frequency_hpp

#include <unordered_map>
#include <string>
#include <istream>
#include <sstream>
#include <cctype>
#include <algorithm>

class Frequency {
private:
    std::string line;
public:
    std::unordered_map<std::string, int> frequency_word;
    int count_word = 0;
    std::string replacePunctuation(std::string line);
    Frequency(std::istream& in);
};

#endif
