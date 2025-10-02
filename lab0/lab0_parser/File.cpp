#include "File.hpp"

File::File(int argc, char* argv[]) {
    openInput(argv[1]);
    openOutput(argv[2]);
    if (file.is_open() && out.is_open()) {
        IsValid = true;
    } else {
        std::cerr << "Error opening file\n";
    }
}

void File::openInput(const std::string& filename) {
    file.open(filename);
}

void File::openOutput(const std::string& filename) {
        out.open(filename);
    }

File::~File() {
    if (file.is_open()) {
        file.close();
    }
    if (out.is_open()) {
        out.close();
    }
}
