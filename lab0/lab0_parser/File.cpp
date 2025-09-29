#include "File.hpp"

File::File(int argc, char* argv[]) {
    openInput(argv[1]);
    openOutput(argv[2]);
}

void File::openInput(const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file\n";
    }
}

void File::openOutput(const std::string& filename) {
        out.open(filename);
        if (!out.is_open()) {
            std::cout << "Error opening file\n";
        }
    }

File::~File() {
    if (file.is_open()) {
        file.close();
    }
    if (out.is_open()) {
        out.close();
    }
}
