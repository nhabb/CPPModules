#include "BitcoinExchange.hpp"

void BitcoinExchnage::setFileName(const char *fileName)
{
    this->fileName = fileName;
}

std::string BitcoinExchnage::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

bool BitcoinExchnage::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchnage::isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || year > 2022)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    
    if (day > daysInMonth[month - 1])
        return false;
    
    return true;
}

bool BitcoinExchnage::loadDatabase()
{
    std::ifstream reader("data.csv");
    if (!reader.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }
    
    std::string line;
    std::getline(reader, line);
    
    while(std::getline(reader, line))
    {
        size_t pos = line.find(',');
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            std::string rateStr = line.substr(pos + 1);
            float rate = atof(rateStr.c_str());
            database[date] = rate;
        }
    }
    reader.close();
    return true;
}

float BitcoinExchnage::findRate(const std::string& date)
{
    std::map<std::string, float>::iterator it = database.lower_bound(date);
    
    if (it != database.end() && it->first == date)
        return it->second;
    
    if (it == database.begin())
        return database.begin()->second;
    
    --it;
    return it->second;
}

bool BitcoinExchnage::parseInput()
{
    std::ifstream reader(fileName);
    if (!reader.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    
    std::string line;
    std::getline(reader, line); // Skip header
    
    while(std::getline(reader, line))
    {
        size_t pos = line.find(" | ");
        if (pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 3));
        
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        char* endptr;
        double value = strtod(valueStr.c_str(), &endptr);
        
        if (*endptr != '\0' && *endptr != '\n')
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        float rate = findRate(date);
        float result = value * rate;
        
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    reader.close();
    return true;
}

void BitcoinExchnage::exchange()
{
    if (!loadDatabase())
        return;
    parseInput();
}