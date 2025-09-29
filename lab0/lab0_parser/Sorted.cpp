#include "Sorted.hpp"

static bool Sorted::compare(const Word& a, const Word& b) {
    return a.frequency > b.frequency;
}

double Sorted::percentForWord(int total_word, int frequency) {
    double percent = 0;
    return percent = std::round((frequency * 100.0 / total_word)*10.0) / 10.0;
}
Sorted::Sorted(std::unordered_map<std::string, int> frequency, int count_word) {
    for(const auto& pair: frequency) {
        sorted_words.push_back({pair.first, pair.second, 0.0});
    }
    std::sort(sorted_words.begin(), sorted_words.end(), compare);
    for (auto& pair : sorted_words) {
        pair.percent = percentForWord(count_word, pair.frequency);
    }
}
