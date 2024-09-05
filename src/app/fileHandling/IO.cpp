#include <iostream>
#include "IO.hpp"
using namespace std;
#include <fstream>

IO::IO(const string &file_path)
{
    file_stream.open(file_path, std::ios::in | std::ios::out | std::ios::binary);

    if (!file_stream.is_open())
    {
        cout << "Unable to Open the File Path " << file_path << endl;
    }
}

fstream IO::getFileStream()
{
    return move(file_stream);
}


IO::~IO(){
   if (file_stream.is_open())
   {
    file_stream.close();
   }
   
}