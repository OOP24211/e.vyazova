#ifndef File_h
#define File_h

#include <string>
#include <fstream>
#include <iostream>

class File {
public:
    std::ifstream file;
    std::ofstream out;
    
    File(int argc, char* argv[]);
    void openInput(const std::string& filename);
    void openOutput(const std::string& filename);
    
    ~File();
}

#endif
