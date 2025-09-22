#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <array>
#include <cstddef>
#include <algorithm>

template <typename T, size_t n>
void merge(std::array<T, n>& arr, size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (size_t i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (size_t j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    size_t i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


template <typename T, size_t n>
void merge_sort(std::array<T, n>& arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

template <typename T, size_t n>
void merge_sort(std::array<T, n>& arr)
{
    if constexpr (n > 1)
        merge_sort(arr, 0, n - 1);
}
#endif
