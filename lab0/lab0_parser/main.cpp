#include <string>
#include <vector>
#include <unordered_map>

#include "Frequency.hpp"
#include "Sorted.hpp"
#include "Word.hpp"
#include "Write.hpp"
#include "File.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Incorrect number of parameters\n";
        return 1;
    }
    File f(argc, argv);
    if (!f.IsValid) {
        return 1;
    }
    
    Frequency freq(f.file);
    std::unordered_map<std::string, int> frequency = freq.frequency_word;
    int count = freq.count_word;
    
    Sorted srt(frequency, count);
    std::vector<Word> sorted = srt.sorted_words;

    Write writer(f.out, sorted);
    
    return 0;
}
