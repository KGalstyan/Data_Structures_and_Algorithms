#include <iostream>
#include "vector.hpp"
#include "vector.tpp"

int main()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Original vector: ";
    v.print_vector(); // 10 20 30

    v[1] = 50;
    std::cout << "After changing index 1: ";
    v.print_vector(); // 10 50 30

    Vector<int> v2 = v; // copy constructor
    v2.push_back(100);

    std::cout << "Copied vector: ";
    v2.print_vector(); // 10 50 30 100

    std::cout << "Original vector unchanged: ";
    v.print_vector(); // 10 50 30
}
