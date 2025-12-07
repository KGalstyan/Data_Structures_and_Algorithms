#pragma once

#include <iostream>

template <typename T>
class Node
{
    public:
        T data;
        Node* next;  
        Node(T value) : data(std::move(value)), next(nullptr) {}
};