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

#include <iostream>
#include <forward_list>
using namespace std;

// reusable display function

void display(forward_list<int> fl)
{
    for (int x : fl)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    // ================= CREATE =================

    forward_list<int> fl; // empty forward_list

    forward_list<int> fl2 = {10, 20, 30}; // initialize with values

    forward_list<int> fl3(5); // create 5 elements with default value 0

    forward_list<int> fl4(5, 100); // create 5 elements with value 100

    forward_list<int> fl5{1, 2, 3}; // uniform initialization

    cout << "fl4 elements: ";

    display(fl4);

    // Output: 100 100 100 100 100

    // assign() replaces old elements with new values

    fl3.assign({7, 8, 9});

    cout << "\nAfter assign(): ";

    display(fl3);

    // Output: 7 8 9

    // push_front() inserts element at beginning
    // forward_list supports only push_front()
    // push_back() is NOT supported

    fl2.push_front(5);

    cout << "\nAfter push_front(): ";

    display(fl2);

    // Output: 5 10 20 30

    // insert_after() inserts element after iterator position

    forward_list<int>::iterator it = fl2.begin();

    fl2.insert_after(it, 99);

    cout << "\nAfter insert_after(): ";

    display(fl2);

    // Output: 5 99 10 20 30

    // ================= READ =================

    cout << "\nforward_list elements: ";

    display(fl2);

    // Output: 5 99 10 20 30

    // front() returns first element

    cout << "\nfl2.front(): " << fl2.front() << endl;

    // Output: 5

    // empty() checks list is empty or not

    cout << "fl2.empty(): " << fl2.empty() << endl;

    // Output: 0

    // IMPORTANT:
    // forward_list is singly linked list
    // so it supports only forward iterator

    // ++it  -> supported
    // --it  -> NOT supported
    // it+2  -> NOT supported
    // it-2  -> NOT supported

    // ================= UPDATE =================

    forward_list<int>::iterator it2 = fl2.begin();

    ++it2; // move iterator forward by 1 position

    *it2 = 500; // update value using iterator

    cout << "\nAfter update(): ";

    display(fl2);

    // Output: 5 500 10 20 30

    // ================= DELETE =================

    // pop_front() removes first element
    // pop_back() is NOT supported

    fl2.pop_front();

    cout << "\nAfter pop_front(): ";

    display(fl2);

    // Output: 500 10 20 30

    // erase_after() removes next element

    forward_list<int>::iterator it3 = fl2.begin();

    fl2.erase_after(it3);

    cout << "\nAfter erase_after(): ";

    display(fl2);

    // Output: 500 20 30

    // remove() removes all matching values

    fl2.remove(20);

    cout << "\nAfter remove(20): ";

    display(fl2);

    // Output: 500 30

    // clear() removes all elements

    fl2.clear();

    cout << "\nAfter clear()" << endl;

    cout << "fl2.empty(): " << fl2.empty() << endl;

    // Output: 1

    // ================= SORT =================

    forward_list<int> nums = {40, 10, 30, 20};

    // sort() sorts elements in ascending order

    nums.sort();

    cout << "\nAfter sort(): ";

    display(nums);

    // Output: 10 20 30 40

    // ================= REVERSE =================

    // reverse() reverses elements

    nums.reverse();

    cout << "\nAfter reverse(): ";

    display(nums);

    // Output: 40 30 20 10

    // ================= UNIQUE =================

    // unique() removes consecutive duplicate values

    forward_list<int> dup = {1, 1, 2, 2, 3, 3};

    dup.unique();

    cout << "\nAfter unique(): ";

    display(dup);

    // Output: 1 2 3

    // ================= MERGE =================

    // merge() merges two sorted forward_lists

    forward_list<int> a = {1, 3, 5};

    forward_list<int> b = {2, 4, 6};

    a.merge(b);

    cout << "\nAfter merge(): ";

    display(a);

    // Output: 1 2 3 4 5 6

    return 0;
}