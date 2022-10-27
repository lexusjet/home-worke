#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

class File
{
    public:
        File(std::string path);
        File(const char* path);
        ~File();

        operator std::ifstream&();
        bool is_open() const;

    protected:
        bool open_ = false;
        std::ifstream stream_ ;
};

#endif // FILE_H
