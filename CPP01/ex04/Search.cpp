#include "Search.hpp"
#include <fstream>

void Search::setS1(std::string s1)
{
    this->s1 = s1;
}

void Search::setS2(std::string s2)
{
    this->s2 = s2;
}

void Search::setFileName(char *file)
{
    this->fileName = file;
}

void Search::replace()
{
    std::ifstream reader(fileName);
    std::ofstream writer(strcat(fileName,".replace"));
    bool at_word_boundary;
    bool at_end_boundary;
    bool full_match;
    int j = 0;
    int i = 0;
    int size;
    int match_start;
    std::string line;
    if (!reader || !writer)
    {
        std::cout << "failed to open file" << std::endl;
        return;
    }

    while (getline(reader, line)) 
    {
        i = 0;
        size = (int)line.size();
        
        while (i < size)
        {
            at_word_boundary = (i == 0 || line[i-1] == ' ' || line[i-1] == '\t');
            full_match = true;
            j = 0;
            match_start = i;
            
            while (j < (int)s1.length() && i < size)
            {
                if (line[i] != s1[j]) 
                {
                    full_match = false;
                    break;
                }
                i++;
                j++;
            }            
            at_end_boundary = (i >= size || line[i] == ' ' || line[i] == '\t');
            if (full_match && j == (int)s1.length() && at_word_boundary && at_end_boundary) 
                writer << s2;
            else 
            {
                i = match_start;
                writer << line[i];
                i++;
            }
        }
        writer << '\n';
    }
    reader.close();
    writer.close();
}