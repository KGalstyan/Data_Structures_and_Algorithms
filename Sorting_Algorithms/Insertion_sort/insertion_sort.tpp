#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <array>
#include <cstddef>

////// time complexity n^2

template <typename T, size_t n>
void insertion_sort(std::array<T, n>& arr){

    int i = 0;

    for(int j = 1; j < (int)arr.size(); j++)    // n
    {                      
        T key = arr[j];                         // n-1
        i = j - 1;                              // n-1
        while(i >= 0 && arr[i] > key){          // sun (t[j])
            arr[i+1] = arr[i];                  // sum (t[j-1])
            i = i - 1;                          // sum (t[j-1]) 
        }
        arr[i+1] = key;                         // n-1
    }
    return ;
}

#endif