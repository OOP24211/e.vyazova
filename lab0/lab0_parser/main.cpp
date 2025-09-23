#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <cmath>
#include <vector>

struct Word {
    std::string words;
    int frequency;
    double percent;
};

class File {
public:
    std::fstream file;
    std::ofstream out;
    File(const std::string& infile, const std::string& outfile) {
        file.open(infile);
        out.open(outfile);
        if (!file || !out) {
            std::cout << "Error opening file\n";
        }
    }
    void close() {
        if (file.is_open()) {
            file.close();
        }
        if (out.is_open()) {
            out.close();
        }
    }
};

class Frequency {
private:
    std::string line;
public:
    std::unordered_map<std::string, int> frequency_word;
    int count_word = 0;
    std::string replacePunctuation(std::string line) {
        for (int i = 0; i < line.length(); ++i) {
            char ch = line[i];
            if (std::ispunct(ch)) {
                line[i] = ' ';
            }
        }
        return line;
    }
    Frequency(const std::string& infile) {
        std::ifstream f(infile);
        while (std:: getline(f, line)) {
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
};

class Sorted {
public:
    std::vector<Word> sorted_words;
    static bool compare(const Word& a, const Word& b) {
        return a.frequency > b.frequency;
    }
    double percentForWord(int total_word, int frequency) {
        double percent = 0;
        return percent = std::round((frequency * 100.0 / total_word)*10.0) / 10.0;
    }
    Sorted(std::unordered_map<std::string, int> frequency, int count_word) {
        for(const auto& pair: frequency) {
            sorted_words.push_back({pair.first, pair.second, 0.0});
        }
        std::sort(sorted_words.begin(), sorted_words.end(), compare);
        for (auto& pair : sorted_words) {
            pair.percent = percentForWord(count_word, pair.frequency);
        }
    }
};

class Write {
public:
    Write(std::ofstream& out, const std::vector<Word> sorted_words) {
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
    
};

int main() {
    File f("input.txt", "output.csv");
    std::ofstream& fout = f.out;
    
    Frequency freq("input.txt");
    std::unordered_map<std::string, int> frequency = freq.frequency_word;
    int count = freq.count_word;
    
    Sorted srt(frequency, count);
    std::vector<Word> sorted = srt.sorted_words;
    
    Write writer(fout, sorted);
    
    f.close();
    return 0;
}
