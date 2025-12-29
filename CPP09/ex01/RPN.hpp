#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN
{
    private:
        std::stack<int> s;
        bool isOperator(const std::string& token);
        int performOperation(int a, int b, char op);
    public:
        bool evaluate(const std::string& expression);
};

#endif