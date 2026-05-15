/*
========================================================
                  MULTISET IN C++
========================================================

Definition:
- multiset stores values in sorted order
- Duplicate values are allowed
- Elements are automatically sorted

Header File:
    #include <set>

Syntax:
    multiset<data_type> set_name;

Example:
    multiset<int> ms;

Internal Working:
- Internally implemented using Red Black Tree
- Uses bidirectional iterator

Important Points:
1. Duplicate values are allowed
2. Values stored in sorted order
3. No direct indexing
4. Values cannot be modified directly
5. Only one value stored (no key-value pair)

Main Functions:
1. insert()        -> insert value
2. size()          -> total elements
3. empty()         -> checks multiset empty or not
4. count(value)    -> total occurrences
5. find(value)     -> search value
6. equal_range()   -> access duplicate values
7. erase(value)    -> delete all occurrences
8. erase(iterator) -> delete single occurrence
9. clear()         -> remove all elements

Iterator Support:
- ++it -> supported
- --it -> supported
- it+2 -> NOT supported
- it-2 -> NOT supported

Time Complexity:
- insert()  -> O(log n)
- find()    -> O(log n)
- erase()   -> O(log n)
- count()   -> O(log n + duplicates)

Example:
    10 10 20 20 30 40

========================================================
*/

#include <iostream>
#include <set>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(multiset<int> ms)
{
    for (int x : ms)
    {
        cout << x << " ";
    }

    cout << endl;
}

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    multiset<int> ms; // empty multiset

    ms.insert(30);
    ms.insert(10);
    ms.insert(20);
    ms.insert(10); // duplicate allowed

    cout << "multiset elements: ";

    display(ms);

    /*
    Output:
    10 10 20 30
    */

    // insert more values

    ms.insert(40);
    ms.insert(20);

    cout << "\nAfter insert(): ";

    display(ms);

    /*
    Output:
    10 10 20 20 30 40
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    multiset<int> ms{
        30,
        10,
        20,
        10,
        40,
        20};

    // size()

    cout << "ms.size(): " << ms.size() << endl;

    // empty()

    cout << "ms.empty(): " << ms.empty() << endl;

    cout << endl;

    // count()

    cout << "count(10): " << ms.count(10) << endl;

    cout << "count(20): " << ms.count(20) << endl;

    cout << endl;

    // find()

    if (ms.find(30) != ms.end())
    {
        cout << "30 found" << endl;
    }

    cout << endl;

    // begin()

    cout << "First element: " << *ms.begin() << endl;

    cout << endl;

    // equal_range()

    auto range = ms.equal_range(20);

    cout << "Values of 20: ";

    for (auto it = range.first; it != range.second; it++)
    {
        cout << *it << " ";
    }

    /*
    Output:
    20 20
    */

    cout << endl
         << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    multiset<int> ms{
        10,
        20,
        30,
        40};

    auto it = ms.begin();

    cout << "First element: " << *it << endl;

    ++it;

    cout << "Second element: " << *it << endl;

    /*
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

    multiset<int> ms{
        10,
        10,
        20,
        20,
        30,
        40};

    // multiset values cannot be updated directly

    // erase old value and insert new value

    auto it = ms.find(30);

    if (it != ms.end())
    {
        ms.erase(it); // remove single occurrence
    }

    ms.insert(300);

    cout << "After update:" << endl;

    display(ms);

    /*
    Output:
    10 10 20 20 40 300
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    multiset<int> ms{
        10,
        10,
        20,
        20,
        40,
        300};

    // erase(value)

    ms.erase(10);

    cout << "After erase(10): ";

    display(ms);

    /*
    Output:
    20 20 40 300
    */

    cout << endl;

    // erase(iterator)

    auto it = ms.find(20);

    if (it != ms.end())
    {
        ms.erase(it); // removes single occurrence
    }

    cout << "After erase(iterator): ";

    display(ms);

    /*
    Output:
    20 40 300
    */

    cout << endl;

    // clear()

    ms.clear();

    cout << "After clear()" << endl;

    cout << "ms.empty(): " << ms.empty() << endl;

    /*
    Output:
    ms.empty(): 1
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