#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <array>
#include <cstddef>
#include <algorithm>

template <typename T, size_t n>
size_t partition(std::array<T, n>& arr, size_t low, size_t high)
{
    T pivot = arr[high];
    size_t i = low - 1;

    for (size_t j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T, size_t n>
void quick_sort(std::array<T, n>& arr, size_t low, size_t high)
{
    if (low < high)
    {
        size_t pi = partition(arr, low, high);

        if (pi > 0)
            quick_sort(arr, low, pi - 1);

        quick_sort(arr, pi + 1, high);
    }
}

template <typename T, size_t n>
void quick_sort(std::array<T, n>& arr)
{
    if (n > 1)
        quick_sort(arr, 0, n - 1);
}

#endif
