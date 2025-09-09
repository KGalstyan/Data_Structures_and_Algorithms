#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <array>
#include <cstddef>
#include <algorithm>
#include "../Insertion_sort/insertion_sort.tpp"

template <typename T, size_t n>
void merge_sort(std::array<T, n>& arr) {
    if (arr.size() <= 1) return;

    size_t len1, len2;
    if (arr.size() % 2 == 0) {
        len1 = len2 = arr.size() / 2;
    } else {
        len1 = arr.size() / 2;
        len2 = arr.size() - len1;
    }

    std::array<T, (n+1)/2> arr1{};
    std::array<T, n/2>     arr2{};

    std::copy(arr.begin(), arr.begin() + len1, arr1.begin());
    std::copy(arr.begin() + len1, arr.end(), arr2.begin());

    insertion_sort(arr1);
    insertion_sort(arr2);

    size_t i = 0, j = 0, k = 0;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j]){
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < len1) arr[k++] = arr1[i++];
    while (j < len2) arr[k++] = arr2[j++];
}

#endif
