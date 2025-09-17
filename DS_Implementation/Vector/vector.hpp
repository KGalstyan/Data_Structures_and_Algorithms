#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector 
{
    public:
        Vector();
        Vector(const Vector<T>& other);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        ~Vector();

        size_t size() const;
        bool empty() const;
        void push_back(const T& elem);
        void print_vector() const;
        
    private:
        size_t sz;  // size
        size_t cap; // capacity
        T * data;

        void copy_data(T* dst, T* src, size_t d_size);
        void reallocate(size_t newCap);
};

#endif
