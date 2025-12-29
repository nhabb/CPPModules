#include "RPN.hpp"

bool RPN::isOperator(const std::string& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::performOperation(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
            {
                std::cerr << "Error" << std::endl;
                return 0;
            }
            return a / b;
        default:
            return 0;
    }
}

bool RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
        {
            s.push(token[0] - '0');
        }
        else if (token.length() == 1 && isOperator(token))
        {
            if (s.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return false;
            }
            
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            
            if (token[0] == '/' && b == 0)
            {
                std::cerr << "Error" << std::endl;
                return false;
            }
            
            int result = performOperation(a, b, token[0]);
            s.push(result);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
    }
    
    if (s.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    std::cout << s.top() << std::endl;
    return true;
}