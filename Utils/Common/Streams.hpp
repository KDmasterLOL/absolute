#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <streambuf>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::iostream;
using std::ofstream;
using std::ostream;
using std::streambuf;
using std::streamsize;
using std::stringstream;

namespace StreamHelp
{
    void ReadFile(string path_to_file, string &file_content)
    {
        ifstream file(path_to_file);
        if (file.is_open())
        {
            stringstream str_buff_stream;
            str_buff_stream << file.rdbuf();
            file_content = str_buff_stream.str();
        }
    }
}