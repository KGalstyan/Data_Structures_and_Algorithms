#include "single_linked_list.hpp"
#include <algorithm>
#include <vector>

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

//____________________ Basic operations ____________________

template <typename T>
std::size_t single_linked_list<T>::size() const
{
    std::size_t count = 0;
    Node<T>* curr = head;
    while (curr)
    {
        ++count;
        curr = curr->next;
    }
    return count;
}

template <typename T>
bool single_linked_list<T>::is_empty() const
{
    return head == nullptr;
}

template <typename T>
Node<T>* single_linked_list<T>::first()
{
    return head;
}

template <typename T>
Node<T>* single_linked_list<T>::last()
{
    if (!head) return nullptr;
    Node<T>* curr = head;
    while (curr->next)
        curr = curr->next;
    return curr;
}

//____________________ Const versions ____________________

template <typename T>
const Node<T>* single_linked_list<T>::first() const
{
    return head;
}

template <typename T>
const Node<T>* single_linked_list<T>::last() const
{
    if (!head)
        return nullptr;
    const Node<T>* curr = head;
    while (curr->next)
        curr = curr->next;
    return curr;
}

//____________________ Insertions ____________________

template <typename T>
template <typename... Args>
void single_linked_list<T>::insert(Node<T> *position, Args&&... values)
{
    if (!position)
    {
        push_front(std::forward<Args>(values)...);
        return;
    }
    Node<T>* p_newNode = new Node<T>(std::forward<Args>(values)...);
    p_newNode->next = position->next;
    position->next = p_newNode;
}

template <typename T>
template <typename... Args>
void single_linked_list<T>::push_front(Args&&... values)
{
    Node<T>* p_newNode = new Node<T>(std::forward<Args>(values)...);
    p_newNode->next = head;
    head = p_newNode;
}

template <typename T>
template <typename... Args>
void single_linked_list<T>::push_back(Args&&... values)
{
    Node<T>* p_newNode = new Node<T>(std::forward<Args>(values)...);
    p_newNode->next = nullptr;
    if(head == nullptr)
    {
        head = p_newNode;
        return;
    }
    Node<T>* tail = last();
    tail->next = p_newNode;
}

template <typename T>
void single_linked_list<T>::pop_front()
{
    if(head)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void single_linked_list<T>::pop_back()
{
    if(head)
    {
        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T>* curr = head;
            while(curr->next->next)
                curr = curr->next;
            delete curr->next;
            curr->next = nullptr;
        }
    }
}

//____________________ Splice / Reverse / Unique / Sort ____________________

template <typename T>
void single_linked_list<T>::splice(single_linked_list<T>& other)
{
    if(head == nullptr)
        head = other.head;
    else
    {
        Node<T>* tail = last();
        tail->next = other.head;
    }
    other.head = nullptr;
}

template <typename T>
void single_linked_list<T>::reverse()
{
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}
template <typename T>
void single_linked_list<T>::unique()
{
    Node<T>* curr = head;
    T data;
    while(curr)
    {
        data = curr->data;
        Node<T>* runner = curr;
        while(runner->next)
        {
            if(runner->next->data == data)
            {
                Node<T>* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            }
            else
                runner = runner->next;
        }
        curr = curr->next;
    }
}


template <typename T>
void single_linked_list<T>::sort()
{
}

//____________________ Clear & Remove  ____________________

template <typename T>
void single_linked_list<T>::clear()
{
    while (head)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void single_linked_list<T>::remove(const T& value)
{
    while(head && head->data == value)
    {
        Node<T>* tmp = head->next;
        delete head;
        head = tmp;
    }
    Node<T>*curr = head;
    while(curr && curr->next)
    {
        if(curr->next->data == value)
        {
            Node<T>* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        }
        else
            curr = curr->next;
    }
}

template <typename T>
template <typename... Args> void single_linked_list<T>::remove_by_values(Args&&... values) // will fix
{
    Node<T>* p_newNode = new Node<T>(std::forward<Args>(values)...);
    remove(p_newNode->data);
    remove(T(std::forward<Args>(values)...));
}
