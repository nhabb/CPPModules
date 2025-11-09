#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
class Span
{
    private:
        unsigned int N;
        unsigned int size;
        std::vector<int> data;
    public:
    Span();
    Span(int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    
    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    
    template<typename T>
    void addRange(T begin, T end)
    {
        while (begin != end)
        {
            if (size == N)
                throw SizeExceededException();
            data.push_back(*begin);
            size++;
            ++begin;
        }
    }

    class SizeExceededException : public std::exception
    {
        public:
        virtual const char * what() const throw();
    };
    class NoSpanFoundException : public std::exception
    {
        public:
        virtual const char * what() const throw();
    };
};

#endif