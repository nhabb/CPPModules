#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
#include <climits>

class BitcoinExchnage
{
    private:
        const char *fileName;
        std::map<std::string, float> database;
        
        bool loadDatabase();
        bool isValidDate(const std::string& date);
        bool isLeapYear(int year);
        bool parseInput();
        std::string trim(const std::string& str);
        float findRate(const std::string& date);
    public:
        void setFileName(const char *fileName);
        void exchange();
};

#endif