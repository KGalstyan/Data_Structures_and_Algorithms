#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include "merge_sort.tpp"

template <typename T, size_t N>
void printArray(const std::array<T, N>& arr) {
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}


int main(){

    std::array<int, 12> arr1 = {12, 5, 7, 3, 19, 1, 8, 14, 6, 2, 11, 4};
    std::array<double, 10> arr2 = {45.2, -12.3, 7.1, 0.5, 99.9, -55.6, 23.4, 3.3, -7.7, 10.0};
    std::array<std::string, 8> arr3 = {"Ararat", "Davit", "Bagrat", "Gevorg", "Karen", "Ani", "Lilit", "Sona"};

    printArray(arr1);
    merge_sort(arr1);
    printArray(arr1);
    std::cout << "\n";

    printArray(arr2);
    merge_sort(arr2);
    printArray(arr2);
    std::cout << "\n";

    printArray(arr3);
    merge_sort(arr3);
    printArray(arr3);
    std::cout << "\n";

    return 0;
}
