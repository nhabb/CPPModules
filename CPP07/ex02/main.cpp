#include <iostream>
// #include <string>
#include "iter.hpp"

template <typename T>
void printElem(T const &x) {
    std::cout << x << " ";
}

template <typename T>
void incrementElem(T &x) {
    x++;
}

int main() {
    // --------- int array ----------
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "int array before increment: ";
    iter(arr, 5, printElem<int>);
    std::cout << "\n";

    iter(arr, 5, incrementElem<int>);
    std::cout << "int array after increment:  ";
    iter(arr, 5, printElem<int>);
    std::cout << "\n\n";

    // --------- const int array ----------
    const int cArr[] = {10, 20, 30, 40};
    std::cout << "const int array: ";
    iter(cArr, 4, printElem<const int>);
    std::cout << "\n\n";

    // --------- string array ----------
    std::string strs[] = {"one", "two", "three"};
    std::cout << "string array: ";
    iter(strs, 3, printElem<std::string>);
    std::cout << "\n\n";

    // --------- const string array ----------
    const std::string cStrs[] = {"alpha", "beta", "gamma"};
    std::cout << "const string array: ";
    iter(cStrs, 3, printElem<const std::string>);
    std::cout << "\n";

    return 0;
}
