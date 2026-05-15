/*
========================================================
                    DEQUE IN C++
========================================================

Definition:
- deque means Double Ended Queue
- Insertion and deletion can happen from both ends
- Behaves like both stack and queue

Header File:
    #include <deque>

Syntax:
    deque<data_type> deque_name;

Example:
    deque<int> dq;

Internal Working:
- Internally implemented using dynamic segmented arrays
- Provides fast insertion/deletion from both ends

Important Points:
1. Dynamic size
2. Fast insertion/deletion from front and back
3. Supports indexing
4. Combination of vector and queue features
5. Random access supported
6. Slower middle insertion compared to ends

Main Functions:
1. push_back()    -> insert at end
2. push_front()   -> insert at beginning
3. pop_back()     -> remove from end
4. pop_front()    -> remove from beginning
5. insert()       -> insert at specific position
6. emplace()      -> construct and insert element
7. erase()        -> remove specific element
8. front()        -> first element
9. back()         -> last element
10. at()          -> safe access
11. size()        -> total elements
12. empty()       -> checks deque empty or not
13. clear()       -> remove all elements

Iterator Support:
- Random access iterator supported
- ++it   -> supported
- --it   -> supported
- it+2   -> supported
- it-2   -> supported

Difference:
- []   -> no bounds checking
- at() -> throws exception if out of range

Time Complexity:
- push_front() -> O(1)
- push_back()  -> O(1)
- pop_front()  -> O(1)
- pop_back()   -> O(1)
- insert()     -> O(n)
- erase()      -> O(n)
- access       -> O(1)

Example:
    1 5 10 20

========================================================
*/

#include <iostream>
#include <deque>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(deque<int> dq)
{
    deque<int>::iterator it;

    for (it = dq.begin(); it != dq.end(); ++it)
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

    deque<int> dq; // empty deque

    // push_back()

    dq.push_back(10);
    dq.push_back(20);

    // push_front()

    dq.push_front(5);
    dq.push_front(1);

    /*
    Current deque:
    1 5 10 20
    */

    // emplace()

    deque<int>::iterator inserted;

    inserted = dq.emplace(dq.begin() + 2, 19);

    /*
    1 5 19 10 20
    */

    // insert()

    dq.insert(inserted, 99);

    /*
    1 5 99 19 10 20
    */

    cout << "Deque elements: ";

    display(dq);

    /*
    Output:
    1 5 99 19 10 20
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(5);
    dq.push_back(99);
    dq.push_back(19);
    dq.push_back(10);
    dq.push_back(20);

    // []

    cout << "dq[1]: " << dq[1] << endl;

    // at()

    cout << "dq.at(2): " << dq.at(2) << endl;

    // front()

    cout << "dq.front(): " << dq.front() << endl;

    // back()

    cout << "dq.back(): " << dq.back() << endl;

    // size()

    cout << "dq.size(): " << dq.size() << endl;

    // empty()

    cout << "dq.empty(): " << dq.empty() << endl;

    cout << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);

    deque<int>::iterator it;

    it = dq.begin();

    cout << "First value: " << *it << endl;

    ++it;

    cout << "Second value: " << *it << endl;

    it = it + 2;

    cout << "Fourth value: " << *it << endl;

    /*
    Random access iterator:
    ++it -> supported
    --it -> supported
    it+2 -> supported
    it-2 -> supported
    */

    cout << endl;
}

// ================= UPDATE FUNCTION =================

void updateDemo()
{
    cout << "================ UPDATE =================\n"
         << endl;

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(5);
    dq.push_back(10);
    dq.push_back(20);

    // update using []

    dq[1] = 500;

    // update using at()

    dq.at(2) = 999;

    cout << "After update: ";

    display(dq);

    /*
    Output:
    1 500 999 20
    */

    cout << endl;

    // insert()

    dq.insert(dq.begin() + 2, 100);

    cout << "After insert(): ";

    display(dq);

    /*
    Output:
    1 500 100 999 20
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    deque<int> dq;

    dq.push_back(500);
    dq.push_back(99);
    dq.push_back(10);
    dq.push_back(20);

    // pop_front()

    dq.pop_front();

    cout << "After pop_front(): ";

    display(dq);

    /*
    Output:
    99 10 20
    */

    cout << endl;

    // pop_back()

    dq.pop_back();

    cout << "After pop_back(): ";

    display(dq);

    /*
    Output:
    99 10
    */

    cout << endl;

    // erase()

    dq.erase(dq.begin());

    cout << "After erase(): ";

    display(dq);

    /*
    Output:
    10
    */

    cout << endl;

    // clear()

    dq.clear();

    cout << "After clear()" << endl;

    cout << "dq.empty(): " << dq.empty() << endl;

    /*
    Output:
    dq.empty(): 1
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

    return 0;
}