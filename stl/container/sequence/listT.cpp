/*
list stores elements in non-contiguous memory

Header file:
#include <list>

Syntax:
list<data_type> list_name;

Example:
list<int> l;

Important points:
1. Dynamic size
2. Fast insertion and deletion
3. No direct indexing like array/vector
4. Uses doubly linked list
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
    // ================= CREATE =================

    list<int> l; // empty list

    list<int> l2 = {10, 20, 30}; // list with values

    list<int> l3(5); // list of size 5 with default value 0

    list<int> l4(5, 100); // list of size 5 with value 100

    cout << "l4 elements: ";

    for(int x : l4)
    {
        cout << x << " ";
    }

    // Output: 100 100 100 100 100

    cout << endl << endl;


    // push_back() inserts element at end

    l2.push_back(40);

    l2.push_back(50);

    cout << "After push_back(): ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 10 20 30 40 50

    cout << endl << endl;


    // push_front() inserts element at beginning

    l2.push_front(5);

    cout << "After push_front(): ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 5 10 20 30 40 50

    cout << endl << endl;



    // ================= READ =================

    cout << "List elements: ";

    for(int x : l2) // range based loop
    {
        cout << x << " ";
    }

    // Output: 5 10 20 30 40 50

    cout << endl << endl;

    cout << "l2.front(): " << l2.front() << endl; // front() returns first element
    // Output: l2.front(): 5

    cout << "l2.back(): " << l2.back() << endl; // back() returns last element
    // Output: l2.back(): 50

    cout << "l2.size(): " << l2.size() << endl; // size() returns total elements
    // Output: l2.size(): 6

    cout << "l2.empty(): " << l2.empty() << endl; // empty() checks list is empty or not
    // Output: l2.empty(): 0

    cout << endl;



    // ================= UPDATE =================

    auto it = l2.begin(); // iterator points to first element

    advance(it, 2); // move iterator to 3rd position

    *it = 500; // update value using iterator

    cout << "After update: ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 5 10 500 30 40 50

    cout << endl << endl;



    // insert() inserts value at specific position

    auto it2 = l2.begin();

    advance(it2, 1);

    l2.insert(it2, 99);

    cout << "After insert(): ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 5 99 10 500 30 40 50

    cout << endl << endl;



    // ================= DELETE =================

    l2.pop_back(); // pop_back() removes last element

    cout << "After pop_back(): ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 5 99 10 500 30 40

    cout << endl << endl;


    l2.pop_front(); // pop_front() removes first element

    cout << "After pop_front(): ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 99 10 500 30 40

    cout << endl << endl;


    auto it3 = l2.begin();

    advance(it3, 2);

    l2.erase(it3); // erase() removes element using iterator

    cout << "After erase(): ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 99 10 30 40

    cout << endl << endl;



    // remove() removes specific value

    l2.remove(10);

    cout << "After remove(10): ";

    for(int x : l2)
    {
        cout << x << " ";
    }

    // Output: 99 30 40

    cout << endl << endl;



    // clear() removes all elements

    l2.clear();

    cout << "Size after clear(): " << l2.size() << endl;
    // Output: Size after clear(): 0

    cout << "l2.empty(): " << l2.empty() << endl;
    // Output: l2.empty(): 1

    return 0;
}