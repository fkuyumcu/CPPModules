#include <iostream>
#include <string>
#include "fstream"
#include <sstream>

std::string ft_replace(std::string content, std::string s1, std::string s2)
{
    std::string res;

    size_t pos = 0;
    size_t found_char = 0;

    if(content.find(s1) == std::string::npos)
    {
        std::cerr << "No matches found for \"" << s1 << "\"" << std::endl;
        return content;
    }

    while((found_char = content.find(s1,pos)) != std::string::npos)
    {
        res += content.substr(pos, found_char - pos);
        res += s2;
        pos = found_char + s1.length();
    }
    res += content.substr(pos);
    return (res);
}