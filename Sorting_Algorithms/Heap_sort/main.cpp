#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include "heap_sort.tpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"


template <typename T, size_t N>
void printArray(const std::array<T, N>& arr)
{
    for (const auto& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
    
template <typename T, size_t N>
void Checker(const std::array<T, N>& arr)
{
    bool sorted = true;

    for (size_t k = 0; k + 1 < arr.size(); k++)
    {
        if (arr[k] > arr[k + 1])
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
        std::cout << GREEN << "Sorted array" << RESET << std::endl;
    else
        std::cout << RED << "Unsorted array" << RESET << std::endl;
}


    
template <typename T, size_t N>
void fillRandom(std::array<T, N>& arr)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<T> dist(-100000, 100000);

    for (auto& x : arr){
        x = dist(rng);
    }
}

template <typename T, size_t N>
void measureSort(std::array<T, N>& arr, const std::string& name)
{
    auto start = std::chrono::high_resolution_clock::now();

    heap_sort(arr);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << BLUE << name << " (" << YELLOW << N << BLUE << " elements) " << "took " << 
            YELLOW << duration.count() << " ns\n" << RESET;
    Checker(arr);
}

int main()
{

    std::array<int, 4> a1 = {5, 4, 3, 2};
    std::array<double, 6> a2 = {10.2, 15.9, -95.6, 12, -5.4, -5.2};
    std::array<std::string, 4> a3 = {"Ararat", "Davit", "Bagrat", "Gevorg"};

    printArray(a1);
    measureSort(a1, "Int array");
    printArray(a1);

    std::cout << "\n";
    printArray(a2);
    measureSort(a2, "Double array");
    printArray(a2);

    std::cout << "\n";
    printArray(a3);
    measureSort(a3, "String array");
    printArray(a3);

    std::cout << "\n";

    std::array<int, 100> arr1;
    std::array<int, 1000> arr2;
    std::array<int, 5000> arr3;
    std::array<int, 10000> arr4;
    std::array<int, 20000> arr5;
    std::array<int, 50000> arr6;

    fillRandom(arr1);
    fillRandom(arr2);
    fillRandom(arr3);
    fillRandom(arr4);
    fillRandom(arr5);
    fillRandom(arr6);

    measureSort(arr1, "Array 1");
    measureSort(arr2, "Array 2");
    measureSort(arr3, "Array 3");
    measureSort(arr4, "Array 4");
    measureSort(arr5, "Array 5");

    measureSort(arr6, "Array_for_compare_with_merge");

    return(0);
}