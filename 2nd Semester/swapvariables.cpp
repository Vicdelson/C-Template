#include <iostream>

int main()
{
    int first = 10;
    int second = 20;
    int third;
    third = first;
    first = second;
    second = third;
    std::cout << first;
    std::cout << "\n";
    std::cout << second;

    return 0;
}