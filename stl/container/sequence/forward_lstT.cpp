/*
forward_list stores elements using singly linked list

Header file:
#include <forward_list>

Syntax:
forward_list<data_type> list_name;

Example:
forward_list<int> fl;

Important points:
1. Dynamic size
2. Fast insertion and deletion
3. Uses singly linked list
4. Only forward traversal allowed
5. No size() function
6. No back() function
*/

#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    // ================= CREATE =================

    forward_list<int> fl; // empty forward_list

    forward_list<int> fl2 = {10, 20, 30}; // initialize with values

    forward_list<int> fl3(5); // create 5 elements with default value 0

    forward_list<int> fl4(5, 100); // create 5 elements with value 100

    cout << "fl4 elements: ";

    for(int x : fl4)
    {
        cout << x << " ";
    }

    // Output: 100 100 100 100 100

    cout << endl << endl;


    // push_front() inserts element at beginning

    fl2.push_front(5);

    cout << "After push_front(): ";

    for(int x : fl2)
    {
        cout << x << " ";
    }

    // Output: 5 10 20 30

    cout << endl << endl;


    // insert_after() inserts element after specific position

    auto it = fl2.begin();

    fl2.insert_after(it, 99);

    cout << "After insert_after(): ";

    for(int x : fl2)
    {
        cout << x << " ";
    }

    // Output: 5 99 10 20 30

    cout << endl << endl;



    // ================= READ =================

    cout << "forward_list elements: ";

    for(int x : fl2)
    {
        cout << x << " ";
    }

    // Output: 5 99 10 20 30

    cout << endl << endl;

    cout << "fl2.front(): " << fl2.front() << endl; // front() returns first element
    // Output: fl2.front(): 5

    cout << "fl2.empty(): " << fl2.empty() << endl; // empty() checks list is empty or not
    // Output: fl2.empty(): 0

    cout << endl;



    // ================= UPDATE =================

    auto it2 = fl2.begin();

    ++it2; // move iterator to second element

    *it2 = 500; // update value using iterator

    cout << "After update: ";

    for(int x : fl2)
    {
        cout << x << " ";
    }

    // Output: 5 500 10 20 30

    cout << endl << endl;



    // ================= DELETE =================

    fl2.pop_front(); // pop_front() removes first element

    cout << "After pop_front(): ";

    for(int x : fl2)
    {
        cout << x << " ";
    }

    // Output: 500 10 20 30

    cout << endl << endl;


    auto it3 = fl2.begin();

    fl2.erase_after(it3); // erase_after() removes next element

    cout << "After erase_after(): ";

    for(int x : fl2)
    {
        cout << x << " ";
    }

    // Output: 500 20 30

    cout << endl << endl;


    fl2.remove(20); // remove() removes specific value

    cout << "After remove(20): ";

    for(int x : fl2)
    {
        cout << x << " ";
    }

    // Output: 500 30

    cout << endl << endl;


    fl2.clear(); // clear() removes all elements

    cout << "fl2.empty(): " << fl2.empty() << endl;
    // Output: fl2.empty(): 1

    cout << endl;



    // ================= SORT =================

    forward_list<int> nums = {40, 10, 30, 20};

    nums.sort(); // sort() sorts elements in ascending order

    cout << "After sort(): ";

    for(int x : nums)
    {
        cout << x << " ";
    }

    // Output: 10 20 30 40

    cout << endl << endl;



    // ================= REVERSE =================

    nums.reverse(); // reverse() reverses list

    cout << "After reverse(): ";

    for(int x : nums)
    {
        cout << x << " ";
    }

    // Output: 40 30 20 10

    return 0;
}