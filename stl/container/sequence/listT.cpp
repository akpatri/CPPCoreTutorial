/*
list stores elements in non-contiguous memory. doubly linked list, i.e. previous and next pointer

Header file: #include <list>

Syntax: list<data_type> list_name;

Example: list<int> l;

Important points:
1. Dynamic size
2. Fast insertion and deletion
3. No direct indexing like array/vector
4. Uses doubly linked list
*/

#include <iostream>
#include <list>
using namespace std;

// reusable display function
void display(list<int> l)
{
    // range based loop to print all elements

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    // ================= CREATE =================

    list<int> l; // empty list

    list<int> l2 = {10, 20, 30}; // list with initializer list

    list<int> l3(5); // list of size 5 with default value 0

    list<int> l4(5, 100); // list of size 5 with all values = 100

    list<int> l5{1, 2, 3}; // uniform initialization

    cout << "l4 elements: ";

    display(l4);

    // Output: 100 100 100 100 100

    // push_back() inserts element at end

    l2.push_back(40);

    l2.push_back(50);

    cout << "\nAfter push_back(): ";

    display(l2);

    // Output: 10 20 30 40 50

    // push_front() inserts element at beginning

    l2.push_front(5);

    cout << "\nAfter push_front(): ";

    display(l2);

    // Output: 5 10 20 30 40 50

    // ================= READ =================

    cout << "\nList elements: ";

    display(l2);

    // Output: 5 10 20 30 40 50

    // front() returns first element

    cout << "\nl2.front(): " << l2.front() << endl;

    // Output: 5

    // back() returns last element

    cout << "l2.back(): " << l2.back() << endl;

    // Output: 50

    // size() returns total number of elements

    cout << "l2.size(): " << l2.size() << endl;

    // Output: 6

    // empty() checks list is empty or not
    // returns 1 = true
    // returns 0 = false

    cout << "l2.empty(): " << l2.empty() << endl;

    // Output: 0

    // ================= ITERATOR =================

    // begin() returns iterator pointing to first element

    list<int>::iterator it = l2.begin();

    // list supports only bidirectional iterator
    // so:
    // ++it  -> supported
    // --it  -> supported
    // it+3  -> NOT supported
    // it-3  -> NOT supported

    // advance() is used to move iterator forward/backward

    advance(it, 2);

    // iterator now points to 3rd element

    // *it dereferences iterator

    cout << "\nIterator value: " << *it << endl;

    // Output: 20

    // ================= UPDATE =================

    // updating value using iterator

    *it = 500;

    cout << "\nAfter update: ";

    display(l2);

    // Output: 5 10 500 30 40 50

    // insert() inserts value before iterator position

    list<int>::iterator it2 = l2.begin();

    advance(it2, 1);

    l2.insert(it2, 99);

    cout << "\nAfter insert(): ";

    display(l2);

    // Output: 5 99 10 500 30 40 50

    // ================= DELETE =================

    // pop_back() removes last element

    l2.pop_back();

    cout << "\nAfter pop_back(): ";

    display(l2);

    // Output: 5 99 10 500 30 40

    // pop_front() removes first element

    l2.pop_front();

    cout << "\nAfter pop_front(): ";

    display(l2);

    // Output: 99 10 500 30 40

    // erase() removes element using iterator

    list<int>::iterator it3 = l2.begin();

    advance(it3, 2);

    l2.erase(it3);

    cout << "\nAfter erase(): ";

    display(l2);

    // Output: 99 10 30 40

    // remove() removes all matching values

    l2.remove(10);

    cout << "\nAfter remove(10): ";

    display(l2);

    // Output: 99 30 40

    // ================= EXTRA FUNCTIONS =================

    // reverse() reverses list

    l2.reverse();

    cout << "\nAfter reverse(): ";

    display(l2);

    // Output: 40 30 99

    // sort() sorts elements in ascending order

    l2.sort();

    cout << "\nAfter sort(): ";

    display(l2);

    // Output: 30 40 99

    // unique() removes consecutive duplicate values

    list<int> dup = {1, 1, 2, 2, 3, 3};

    dup.unique();

    cout << "\nAfter unique(): ";

    display(dup);

    // Output: 1 2 3

    // merge() merges two sorted lists

    list<int> m1 = {1, 3, 5};

    list<int> m2 = {2, 4, 6};

    m1.merge(m2);

    cout << "\nAfter merge(): ";

    display(m1);

    // Output: 1 2 3 4 5 6

    // clear() removes all elements

    l2.clear();

    cout << "\nSize after clear(): " << l2.size() << endl;

    // Output: 0

    // empty() now returns true

    cout << "l2.empty(): " << l2.empty() << endl;

    // Output: 1

    return 0;
}