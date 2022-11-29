#include "File.h"

File::File(std::string path): stream_(path){
    if(!stream_.is_open()) return;
    open_ = true;
}

File::File(const char* path): stream_(path){
    std::ifstream stream_ (path);
    if(!stream_.is_open()) return;
    open_ = true;
}
File::~File(){
    stream_.close();
    open_ = false;
}

File::operator std::ifstream&(){
    return stream_;
}

bool File::is_open() const {return open_;}
