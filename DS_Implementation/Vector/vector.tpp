#pragma once
#include "vector.hpp"

template <typename T>
Vector<T>::Vector(){
    sz = 0;
    cap = 4;
    data = new T[cap];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other){
    sz = other.sz;
    cap = other.cap;
    data = new T[cap];
    copy_data(this->data, other.data, other.sz);
}

template <typename T>
T& Vector<T>::operator[](size_t index){
    if (index >= sz) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const{
    if (index >= sz) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

//________________________________________________________________________________________//

template <typename T>
void Vector<T>::copy_data(T* dst, T* src, size_t d_size){
    for(size_t i = 0; i < d_size; i++)
        dst[i] = src[i];
}

template <typename T>
void Vector<T>::reallocate(size_t new_cap){
    T* new_data = new T[new_cap];
    copy_data(new_data, data, sz);
    delete[] data;
    data = new_data;
    cap = new_cap;
}

template <typename T>
void Vector<T>::push_back(const T& elem)
{
    size_t new_cap;
    if(sz == cap)
    {
        new_cap = (cap == 0) ? 1 : cap * 2;
        reallocate(new_cap);
    }
    data[sz] = elem;
    sz++;
}

template <typename T>
void Vector<T>::print_vector() const
    {
    for (size_t i = 0; i < sz; i++)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

template <typename T>
size_t Vector<T>::size() const{
    return(sz);
}

template <typename T>
bool Vector<T>::empty() const{
    return(sz == 0);
}