#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <array>
#include <cstddef>
#include <algorithm>

template <typename T, size_t n>
void swap(std::array<T, n>& arr, size_t s1, size_t s2)
{
    T tmp;
    tmp = arr[s1];
    arr[s1] = arr[s2];
    arr[s2] = tmp;
}

template <typename T, size_t n>
void bubble_sort(std::array<T, n>& arr)
{
    bool swaped;

    for(size_t i=0; i < arr.size(); i++)
    {
        swaped = false;
        for(size_t j=0; j < arr.size() - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr, j, j+1);
                swaped = true;
            }
        }
        if(swaped == false)
            break;
    }
}
#endif
