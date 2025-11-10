#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <array>
#include <cstddef>
#include <algorithm>

// ___________________________ HELPERS ______________________________//

template <typename T, size_t n>
void swap_elements(std::array<T, n>& arr, ssize_t s1, ssize_t s2)
{
    T tmp = arr[s1];
    arr[s1] = arr[s2];
    arr[s2] = tmp;
}

inline ssize_t left(ssize_t i) { return 2 * i + 1; }
inline ssize_t right(ssize_t i) { return 2 * i + 2; }

// _____________________________ HEAPIFY ______________________________//

template <typename T, size_t n>
void max_heapify(std::array<T, n>& arr, ssize_t i, ssize_t heap_size)
{
    ssize_t l = left(i);
    ssize_t r = right(i);
    ssize_t largest = i;

    if (l < heap_size && arr[l] > arr[largest])
        largest = l;
    if (r < heap_size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap_elements(arr, i, largest);
        max_heapify(arr, largest, heap_size);
    }
}

template <typename T, size_t n>
void build_max_heap(std::array<T, n>& arr, ssize_t& heap_size)
{
    heap_size = static_cast<ssize_t>(arr.size());
    for (ssize_t i = heap_size / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, heap_size);
}

// ___________________________ HEAP SORT ______________________________//

template <typename T, size_t n>
void heap_sort(std::array<T, n>& arr)
{
    ssize_t heap_size;
    build_max_heap(arr, heap_size);

    for (ssize_t i = heap_size - 1; i > 0; i--)
    {
        swap_elements(arr, 0, i);
        heap_size--;
        max_heapify(arr, 0, heap_size);
    }
}

#endif
