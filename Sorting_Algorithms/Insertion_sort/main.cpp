#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include "insertion_sort.tpp"

template <typename T, size_t N>
void printArray(const std::array<T, N>& arr) {
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}


int main(){

    std::array<int, 4> arr1 = {5, 4, 3, 2};
    std::array<double, 6> arr2 = {10.2, 15.9, -95.6, 12, -5.4, -5.2};
    std::array<std::string, 4> arr3 = {"Ararat", "Davit", "Bagrat", "Gevorg"};

    printArray(arr1);
    insertion_sort(arr1);
    printArray(arr1);

    std::cout << "\n";
    printArray(arr2);
    insertion_sort(arr2);
    printArray(arr2);

    std::cout << "\n";
    printArray(arr3);
    insertion_sort(arr3);
    printArray(arr3);

    std::cout << "\n";
    return(0);
}