#include "Span.hpp"

const char* Span::SizeExceededException::what() const throw()
{
    return "Container is at full capacity";
}
const char* Span::NoSpanFoundException::what() const throw()
{
    return "No span can be found";
}

Span::Span() : N(0), size(0)
{
}

Span::Span(int n) : N(n), size(0)
{
}

Span::Span(const Span& other) : N(other.N), size(other.size), data(other.data)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->size = other.size;
        this->data = other.data;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (size == N)
        throw SizeExceededException();
    else
    {
        data.push_back(n);
        size++;
    }
}

int Span::longestSpan()
{
    if (size == 0 || size ==1)
        throw NoSpanFoundException();
    int min = data[0];
    int max = data[0];
    for (int i = 0; i < (int)data.size(); i++)
    {
        if (data[i] > max)
            max = data[i];
        if (data[i] < min)
            min = data[i];
    }
    return (max - min);
}

int Span::shortestSpan()
{
    if (size == 0 || size ==1)
        throw NoSpanFoundException();
    std::vector<int> tmp =data;
    int n = (int)tmp.size();
    int min = 9999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < i; j++)
        {
            if (tmp[j] > tmp[i])
            {
                if ((tmp[j] - tmp[i]) < min)
                    min = tmp[j] - tmp[i];
            }
            else
            {
                if ((tmp[i] - tmp[j]) < min)
                    min = tmp[i] - tmp[j];
            }
        }
    }
    return (min);
}
