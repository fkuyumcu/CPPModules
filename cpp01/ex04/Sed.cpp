#include <iostream>
#include <string>
#include "fstream"
#include <sstream>

std::string ft_replace(std::string content, std::string s1, std::string s2)
{
    std::string result;

    size_t pos = 0;
    size_t found_char = 0;

    if(content.find(s1) == std::string::npos)
    {
        std::cerr << "No matches found for \"" << s1 << "\"" << std::endl;
        return content;
    }

    while((found_char = content.find(s1,pos)) != std::string::npos)//search loop
    {
        result += content.substr(pos, found_char - pos);//add part before s1
        result += s2;//add s2 to result isntead of s1
        pos = found_char + s1.length(); //position is changed from start to end of s2
    }
    result += content.substr(pos);//add part after the last find element
    return (result);
}