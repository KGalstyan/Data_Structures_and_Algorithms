#pragma once

#include <iostream>
#include "iterator.tpp"
#include "node.tpp"

template <typename T>
class single_linked_list
{
    public:

        // ---- Constructors & Destructor ----

        single_linked_list() : head(nullptr) {}
        single_linked_list(const single_linked_list& other);
        single_linked_list& operator=(const single_linked_list& other);
        single_linked_list(single_linked_list&& other) noexcept;
        single_linked_list& operator=(single_linked_list&& other) noexcept;
        ~single_linked_list() { clear(); }

        // ---- Basic operations ----

        std::size_t size() const;    
        bool is_empty() const;

        Node<T>* first();
        Node<T>* last();
        const Node<T>* first() const;
        const Node<T>* last() const;

        // ---- Insertions ----

        template <typename... Args> void insert(Node<T> *position, Args&&... values);
        template <typename... Args> void push_front(Args&&... values);
        template <typename... Args> void push_back(Args&&... values);

        void pop_front();
        void pop_back();

        // ---- Reverse / Unique / Sort / Splice ----

        void splice(single_linked_list<T>& other);
        void reverse();
        void unique();
        void sort();

        // ---- Remove ----

        template <typename... Args> void remove_by_values(Args&&... values);
        void remove(const T& value);
        void clear();

        // ---- Iterator ----

        using iterator_type = iterator<T>;
        iterator_type begin() { return iterator_type(head); }
        iterator_type end() { return iterator_type(nullptr); }

    private:
       Node<T>* head = nullptr;
};

#include "Single_linked_list.tpp"