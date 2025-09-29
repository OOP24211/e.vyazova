#include "Write.hpp"

#include <iomanip>

Write::Write(std::ofstream& out, const std::vector<Word> sorted_words) {
    out << "Слово, Частота, %\n";
    for (const auto& pair : sorted_words) {
        out << pair.words;
        out << ",";
        out << pair.frequency;
        out << ",";
        out << std::fixed << std::setprecision(1) << pair.percent;
        out << "\n";
    }
}
