#ifndef File_h
#define File_h

#include <string>
#include <fstream>
#include <iostream>

class File {
private:
    void openInput(const std::string& filename);
    void openOutput(const std::string& filename);
public:
    std::ifstream file;
    std::ofstream out;
    bool IsValid = false;
    File(int argc, char* argv[]);
    
    ~File();
};

#endif
