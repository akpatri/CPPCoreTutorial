/*
========================================================
                    LIST IN C++
========================================================

Definition:
- list stores elements in non-contiguous memory
- Implemented using doubly linked list
- Each node stores:
    1. Previous pointer
    2. Data
    3. Next pointer

Header File:
    #include <list>

Syntax:
    list<data_type> list_name;

Example:
    list<int> l;

Internal Working:
- Uses doubly linked list
- Elements are connected using previous and next pointers

Important Points:
1. Dynamic size
2. Fast insertion and deletion
3. No direct indexing like array/vector
4. Uses doubly linked list
5. Non-contiguous memory allocation
6. Supports forward and backward traversal
7. Slower random access compared to vector

Main Functions:
1. push_back()   -> insert at end
2. push_front()  -> insert at beginning
3. pop_back()    -> remove last element
4. pop_front()   -> remove first element
5. insert()      -> insert before iterator
6. erase()       -> erase using iterator
7. remove()      -> remove matching values
8. front()       -> first element
9. back()        -> last element
10. size()       -> total elements
11. empty()      -> checks empty or not
12. clear()      -> remove all elements
13. reverse()    -> reverse list
14. sort()       -> sort list
15. unique()     -> remove consecutive duplicates
16. merge()      -> merge sorted lists

Iterator Support:
- Bidirectional iterator supported
- ++it  -> supported
- --it  -> supported
- it+2  -> NOT supported
- it-2  -> NOT supported

Iterator Movement:
- advance(it, n) is used to move iterator

Time Complexity:
- push_front() -> O(1)
- push_back()  -> O(1)
- pop_front()  -> O(1)
- pop_back()   -> O(1)
- insert()     -> O(1)
- erase()      -> O(1)
- search       -> O(n)

Difference:
- vector         -> contiguous memory
- list           -> non-contiguous memory
- forward_list   -> singly linked list
- list           -> doubly linked list

========================================================
*/

#include <iostream>
#include <list>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(list<int> l)
{
    list<int>::iterator it;

    for (it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
}

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    list<int> l; // empty list

    list<int> l2 = {10, 20, 30};

    list<int> l3(5);

    list<int> l4(5, 100);

    list<int> l5{1, 2, 3};

    cout << "l4 elements: ";

    display(l4);

    /*
    Output:
    100 100 100 100 100
    */

    cout << endl;

    // push_back()

    l2.push_back(40);
    l2.push_back(50);

    cout << "After push_back(): ";

    display(l2);

    /*
    Output:
    10 20 30 40 50
    */

    cout << endl;

    // push_front()

    l2.push_front(5);

    cout << "After push_front(): ";

    display(l2);

    /*
    Output:
    5 10 20 30 40 50
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    list<int> l = {5, 10, 20, 30, 40, 50};

    cout << "List elements: ";

    display(l);

    /*
    Output:
    5 10 20 30 40 50
    */

    cout << endl;

    // front()

    cout << "l.front(): " << l.front() << endl;

    /*
    Output:
    5
    */

    // back()

    cout << "l.back(): " << l.back() << endl;

    /*
    Output:
    50
    */

    // size()

    cout << "l.size(): " << l.size() << endl;

    /*
    Output:
    6
    */

    // empty()

    cout << "l.empty(): " << l.empty() << endl;

    /*
    Output:
    0
    */

    cout << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    list<int> l = {5, 10, 20, 30, 40};

    list<int>::iterator it;

    it = l.begin();

    advance(it, 2);

    cout << "Iterator value: " << *it << endl;

    /*
    Output:
    20
    */

    /*
    Bidirectional iterator:
    ++it -> supported
    --it -> supported
    it+2 -> NOT supported
    it-2 -> NOT supported
    */

    cout << endl;
}

// ================= UPDATE FUNCTION =================

void updateDemo()
{
    cout << "================ UPDATE =================\n"
         << endl;

    list<int> l = {5, 10, 20, 30, 40, 50};

    list<int>::iterator it;

    it = l.begin();

    advance(it, 2);

    // update value

    *it = 500;

    cout << "After update: ";

    display(l);

    /*
    Output:
    5 10 500 30 40 50
    */

    cout << endl;

    // insert()

    list<int>::iterator it2;

    it2 = l.begin();

    advance(it2, 1);

    l.insert(it2, 99);

    cout << "After insert(): ";

    display(l);

    /*
    Output:
    5 99 10 500 30 40 50
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    list<int> l = {5, 99, 10, 500, 30, 40, 50};

    // pop_back()

    l.pop_back();

    cout << "After pop_back(): ";

    display(l);

    /*
    Output:
    5 99 10 500 30 40
    */

    cout << endl;

    // pop_front()

    l.pop_front();

    cout << "After pop_front(): ";

    display(l);

    /*
    Output:
    99 10 500 30 40
    */

    cout << endl;

    // erase()

    list<int>::iterator it;

    it = l.begin();

    advance(it, 2);

    l.erase(it);

    cout << "After erase(): ";

    display(l);

    /*
    Output:
    99 10 30 40
    */

    cout << endl;

    // remove()

    l.remove(10);

    cout << "After remove(10): ";

    display(l);

    /*
    Output:
    99 30 40
    */

    cout << endl;

    // clear()

    l.clear();

    cout << "After clear()" << endl;

    cout << "l.empty(): " << l.empty() << endl;

    /*
    Output:
    1
    */

    cout << endl;
}

// ================= REVERSE FUNCTION =================

void reverseDemo()
{
    cout << "================ REVERSE =================\n"
         << endl;

    list<int> l = {99, 30, 40};

    l.reverse();

    cout << "After reverse(): ";

    display(l);

    /*
    Output:
    40 30 99
    */

    cout << endl;
}

// ================= SORT FUNCTION =================

void sortDemo()
{
    cout << "================ SORT =================\n"
         << endl;

    list<int> l = {40, 10, 30, 20};

    l.sort();

    cout << "After sort(): ";

    display(l);

    /*
    Output:
    10 20 30 40
    */

    cout << endl;
}

// ================= UNIQUE FUNCTION =================

void uniqueDemo()
{
    cout << "================ UNIQUE =================\n"
         << endl;

    list<int> dup = {1, 1, 2, 2, 3, 3};

    dup.unique();

    cout << "After unique(): ";

    display(dup);

    /*
    Output:
    1 2 3
    */

    cout << endl;
}

// ================= MERGE FUNCTION =================

void mergeDemo()
{
    cout << "================ MERGE =================\n"
         << endl;

    list<int> m1 = {1, 3, 5};

    list<int> m2 = {2, 4, 6};

    m1.merge(m2);

    cout << "After merge(): ";

    display(m1);

    /*
    Output:
    1 2 3 4 5 6
    */

    cout << endl;
}

// ================= MAIN FUNCTION =================

int main()
{
    createDemo();

    readDemo();

    iteratorDemo();

    updateDemo();

    deleteDemo();

    reverseDemo();

    sortDemo();

    uniqueDemo();

    mergeDemo();

    return 0;
}