#include "Frequency.hpp"

std::string Frequency::replacePunctuation(std::string line) {
    for (int i = 0; i < line.length(); ++i) {
        char ch = line[i];
        if (std::ispunct(ch)) {
            line[i] = ' ';
        }
    }
    return line;
}
Frequency::Frequency(std::istream& in) {
    while (std:: getline(in, line)) {
        std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){return std::tolower(c); });
        std::string processed_line = replacePunctuation(line);
        std::istringstream ss(processed_line);
        std::string word;
        
        while (ss >> word) {
            frequency_word[word]++;
            count_word++;
        }
    }
}
