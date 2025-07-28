#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class Search
{
    private:
    std::string s1;
    std::string s2;
    char        *fileName;

    public:
    void setS1(std::string s1);
    void setS2(std::string s2);
    void setFileName(char *file);
    void replace();
};