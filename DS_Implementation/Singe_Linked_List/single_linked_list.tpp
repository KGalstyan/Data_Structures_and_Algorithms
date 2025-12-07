#include "single_linked_list.hpp"

//____________________ Constructors & Destructor ____________________

template <typename T>
single_linked_list<T>::single_linked_list(const single_linked_list& other) : head(nullptr)
{
    Node<T>* curr = other.head;
    Node<T>* tail = nullptr;
    while (curr)
    {
        Node<T>* node = new Node<T>(curr->data);
        if (!head) head = node;
        else tail->next = node;
        tail = node;
        curr = curr->next;
    }
}

template <typename T>
single_linked_list<T>& single_linked_list<T>::operator=(const single_linked_list& other)
{
    if (this != &other)
    {
        clear();
        Node<T>* curr = other.head;
        Node<T>* tail = nullptr;
        while (curr)
        {
            Node<T>* node = new Node<T>(curr->data);
            if (!head) head = node;
            else tail->next = node;
            tail = node;
            curr = curr->next;
        }
    }
    return *this;
}

template <typename T>
single_linked_list<T>::single_linked_list(single_linked_list&& other) noexcept : head(other.head)
{
    other.head = nullptr;
}

template <typename T>
single_linked_list<T>& single_linked_list<T>::operator=(single_linked_list&& other) noexcept
{
    if (this != &other)
    {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

//____________________ Remove ____________________

template <typename T>
void single_linked_list<T>::clear()
{
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
