#include <iostream>
#include "single_linked_list.hpp"

int main()
{
    std::cout << "===== BASIC INSERTION TESTS =====\n";
    single_linked_list<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_back(5);
    list.push_back(1);

    std::cout << "List after push_front/push_back: ";
    for (auto* n = list.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n";

    std::cout << "Size: " << list.size() << "\n";
    std::cout << "Is empty: " << std::boolalpha << list.is_empty() << "\n\n";


    std::cout << "===== INSERT AFTER NODE TEST =====\n";
    Node<int>* first = list.first(); // 20
    list.insert(first, 99);

    std::cout << "List after insert(99 after first): ";
    for (auto* n = list.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n\n";


    std::cout << "===== POP OPERATIONS TEST =====\n";
    list.pop_front(); // removes 20
    list.pop_back();  // removes 1

    std::cout << "List after pop_front & pop_back: ";
    for (auto* n = list.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n\n";


    std::cout << "===== COPY CONSTRUCTOR TEST =====\n";
    single_linked_list<int> copy_list(list);

    std::cout << "Copy list: ";
    for (auto* n = copy_list.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n";

    // Modify original to ensure deep copy
    list.push_front(777);

    std::cout << "Original after modification: ";
    for (auto* n = list.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n";

    std::cout << "Copy must not change: ";
    for (auto* n = copy_list.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n\n";


    std::cout << "===== COPY ASSIGNMENT TEST =====\n";
    single_linked_list<int> assigned;
    assigned = list;

    std::cout << "Assigned list: ";
    for (auto* n = assigned.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n\n";


    std::cout << "===== MOVE CONSTRUCTOR TEST =====\n";
    single_linked_list<int> moved(std::move(list));

    std::cout << "Moved-from list (should be empty): ";
    if (list.first())
    {
        for (auto* n = list.first(); n; n = n->next)
            std::cout << n->data << " ";
    }
    else
        std::cout << "(empty)";
    std::cout << "\n";

    std::cout << "Moved-to list: ";
    for (auto* n = moved.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n\n";


    std::cout << "===== MOVE ASSIGNMENT TEST =====\n";
    single_linked_list<int> move_assigned;
    move_assigned = std::move(moved);

    std::cout << "Move-assigned list: ";
    for (auto* n = move_assigned.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n";

    std::cout << "Moved-from list should be empty: ";
    if (!moved.first()) std::cout << "(empty)";
    std::cout << "\n\n";


    std::cout << "===== CLEAR TEST =====\n";
    move_assigned.clear();
    std::cout << "After clear, size = " << move_assigned.size() << "\n";
    std::cout << "Is empty: " << std::boolalpha << move_assigned.is_empty() << "\n";

    return 0;
}
