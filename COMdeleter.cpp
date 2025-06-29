#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Cant find filename" << std::endl;
        return 1;
    }

    std::string filename;
    filename = argv[1];

    std::ifstream file1(filename);

    std::string line;
    if (!file1)
    {
        std::cerr << "file not open" << std::endl;
        return 1;
    }
    
    std::string file2_name = filename.substr(0, filename.find('.')) + "_formatted" + filename.substr(filename.find('.'), filename.size());
    std::ofstream file2(file2_name);

    std::string mod_line;
    int fl = 1, k = 0;
    bool is_comment_now = false;

    while (std::getline(file1, line))
    {
        mod_line = line.substr(0, line.find("//"));
        if (line.find("/*") != std::string::npos)
        {
            mod_line = line.substr(0, line.find("/*"));
            is_comment_now = true;
            k++;
        }
        if (line.find("*/") != std::string::npos && is_comment_now == true)
        {
            mod_line = line.substr(line.find("*/") + 2, line.size());
            is_comment_now = false;
        }
        if (is_comment_now == true)
        {
            if (k != 1)
            {
                mod_line = "";
            }
            else
            {
                k = 0;
            }
        }
        if (mod_line != line)
        {
            fl = 0;
        }
        file2 << mod_line << std::endl;
    }

    if (fl == 1)
    {
        std::remove(file2_name.c_str());
    }

    return 0;
}
