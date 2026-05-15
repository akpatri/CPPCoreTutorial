/*
========================================================
                FORWARD_LIST IN C++
========================================================

Definition:
- forward_list stores elements using singly linked list
- Supports only forward traversal

Header File:
    #include <forward_list>

Syntax:
    forward_list<data_type> list_name;

Example:
    forward_list<int> fl;

Internal Working:
- Implemented using singly linked list
- Each node stores:
    1. Data
    2. Address of next node

Important Points:
1. Dynamic size
2. Fast insertion and deletion
3. Uses singly linked list
4. Only forward traversal allowed
5. No size() function
6. No back() function
7. push_back() NOT supported
8. pop_back() NOT supported
9. Memory efficient compared to list

Main Functions:
1. assign()        -> replace elements
2. push_front()    -> insert at beginning
3. pop_front()     -> remove first element
4. insert_after()  -> insert after iterator
5. erase_after()   -> erase next element
6. remove()        -> remove matching values
7. clear()         -> remove all elements
8. front()         -> first element
9. empty()         -> checks empty or not
10. sort()         -> sort elements
11. reverse()      -> reverse elements
12. unique()       -> remove consecutive duplicates
13. merge()        -> merge sorted lists

Iterator Support:
- Forward iterator supported
- ++it  -> supported
- --it  -> NOT supported
- it+2  -> NOT supported
- it-2  -> NOT supported

Time Complexity:
- push_front()   -> O(1)
- pop_front()    -> O(1)
- insert_after() -> O(1)
- erase_after()  -> O(1)
- search          -> O(n)

Difference:
- forward_list -> singly linked list
- list         -> doubly linked list

========================================================
*/

#include <iostream>
#include <forward_list>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(forward_list<int> fl)
{
    forward_list<int>::iterator it;

    for (it = fl.begin(); it != fl.end(); ++it)
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

    forward_list<int> fl; // empty list

    forward_list<int> fl2 = {10, 20, 30};

    forward_list<int> fl3(5); // 5 elements with default value 0

    forward_list<int> fl4(5, 100); // 5 elements with value 100

    forward_list<int> fl5{1, 2, 3};

    cout << "fl4 elements: ";

    display(fl4);

    /*
    Output:
    100 100 100 100 100
    */

    cout << endl;

    // assign()

    fl3.assign({7, 8, 9});

    cout << "After assign(): ";

    display(fl3);

    /*
    Output:
    7 8 9
    */

    cout << endl;

    // push_front()

    fl2.push_front(5);

    cout << "After push_front(): ";

    display(fl2);

    /*
    Output:
    5 10 20 30
    */

    cout << endl;

    // insert_after()

    forward_list<int>::iterator it;

    it = fl2.begin();

    fl2.insert_after(it, 99);

    cout << "After insert_after(): ";

    display(fl2);

    /*
    Output:
    5 99 10 20 30
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    forward_list<int> fl = {5, 99, 10, 20, 30};

    cout << "forward_list elements: ";

    display(fl);

    /*
    Output:
    5 99 10 20 30
    */

    cout << endl;

    // front()

    cout << "fl.front(): " << fl.front() << endl;

    /*
    Output:
    5
    */

    // empty()

    cout << "fl.empty(): " << fl.empty() << endl;

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

    forward_list<int> fl = {10, 20, 30};

    forward_list<int>::iterator it;

    it = fl.begin();

    cout << "First value: " << *it << endl;

    ++it;

    cout << "Second value: " << *it << endl;

    /*
    Forward iterator:
    ++it -> supported
    --it -> NOT supported
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

    forward_list<int> fl = {5, 99, 10, 20, 30};

    forward_list<int>::iterator it;

    it = fl.begin();

    ++it;

    *it = 500;

    cout << "After update(): ";

    display(fl);

    /*
    Output:
    5 500 10 20 30
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    forward_list<int> fl = {5, 500, 10, 20, 30};

    // pop_front()

    fl.pop_front();

    cout << "After pop_front(): ";

    display(fl);

    /*
    Output:
    500 10 20 30
    */

    cout << endl;

    // erase_after()

    forward_list<int>::iterator it;

    it = fl.begin();

    fl.erase_after(it);

    cout << "After erase_after(): ";

    display(fl);

    /*
    Output:
    500 20 30
    */

    cout << endl;

    // remove()

    fl.remove(20);

    cout << "After remove(20): ";

    display(fl);

    /*
    Output:
    500 30
    */

    cout << endl;

    // clear()

    fl.clear();

    cout << "After clear()" << endl;

    cout << "fl.empty(): " << fl.empty() << endl;

    /*
    Output:
    1
    */

    cout << endl;
}

// ================= SORT FUNCTION =================

void sortDemo()
{
    cout << "================ SORT =================\n"
         << endl;

    forward_list<int> nums = {40, 10, 30, 20};

    nums.sort();

    cout << "After sort(): ";

    display(nums);

    /*
    Output:
    10 20 30 40
    */

    cout << endl;
}

// ================= REVERSE FUNCTION =================

void reverseDemo()
{
    cout << "================ REVERSE =================\n"
         << endl;

    forward_list<int> nums = {10, 20, 30, 40};

    nums.reverse();

    cout << "After reverse(): ";

    display(nums);

    /*
    Output:
    40 30 20 10
    */

    cout << endl;
}

// ================= UNIQUE FUNCTION =================

void uniqueDemo()
{
    cout << "================ UNIQUE =================\n"
         << endl;

    forward_list<int> dup = {1, 1, 2, 2, 3, 3};

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

    forward_list<int> a = {1, 3, 5};

    forward_list<int> b = {2, 4, 6};

    a.merge(b);

    cout << "After merge(): ";

    display(a);

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

    sortDemo();

    reverseDemo();

    uniqueDemo();

    mergeDemo();

    return 0;
}