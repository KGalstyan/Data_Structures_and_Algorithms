#pragma once
#include "node.tpp"

template<typename T>
class iterator
{
        Node<T>* current;
    public:
        iterator(Node<T>* ptr) : current(ptr) {}
        T& operator*() { return current->data; }
        iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const iterator& other) const { return current != other.current; }
};
