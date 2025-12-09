#include <iostream>
#include "single_linked_list.hpp"

struct Person {
    std::string name;
    int age;

    Person(std::string n, int a) : name(std::move(n)), age(a) {}
};

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

    list.push_front(777); // modify original

    std::cout << "Original after modification: ";
    for (auto* n = list.first(); n; n = n->next)
        std::cout << n->data << " ";

    std::cout << "\nCopy must not change: ";
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
    if (!list.first()) std::cout << "(empty)";
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
    std::cout << "Is empty: " << std::boolalpha << move_assigned.is_empty() << "\n\n";


    // ================================================================
    //            VARIADIC TEMPLATE TESTING (IMPORTANT!)
    // ================================================================
    std::cout << "===== VARIADIC TEMPLATE TESTS =====\n";

    single_linked_list<Person> persons;

    persons.push_front("Karen", 17);
    persons.push_back("Anna", 19);
    persons.push_front("Mark", 21);

    std::cout << "Persons list: ";
    for (auto* n = persons.first(); n; n = n->next)
        std::cout << n->data.name << " (" << n->data.age << ")  ";
    std::cout << "\n\n";

    // insert using variadic constructor
    persons.insert(persons.first(), "Inserted", 99);

    std::cout << "After insert(Person): ";
    for (auto* n = persons.first(); n; n = n->next)
        std::cout << n->data.name << " (" << n->data.age << ")  ";
    std::cout << "\n\n";


    // ===================================================================
    //                REMOVE + REMOVE_BY_VALUES   (VARIADIC TEST)
    // ===================================================================
    std::cout << "===== REMOVE / REMOVE_BY_VALUES TESTS =====\n";

    single_linked_list<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(5);

    std::cout << "Nums before remove: ";
    for(auto* n = nums.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n";

    nums.remove(2);

    std::cout << "After remove(2): ";
        std::cout << "Nums before remove: ";
    for(auto* n = nums.first(); n; n = n->next)
        std::cout << n->data << " ";
    std::cout << "\n";

    return 0;
}
