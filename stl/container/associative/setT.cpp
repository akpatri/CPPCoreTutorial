/*
========================================================
                     SET IN C++
========================================================

Definition:
- set stores unique values in sorted order
- Duplicate values are automatically ignored
- Elements are automatically sorted

Header File:
    #include <set>

Syntax:
    set<data_type> set_name;

Example:
    set<int> s;

Internal Working:
- Internally implemented using Red Black Tree
- Uses bidirectional iterator

Important Points:
1. Stores only unique values
2. Values are readonly
3. Duplicate values are ignored
4. Elements stored in ascending order by default
5. No indexing
6. Values cannot be modified directly
7. Sorted automatically

Main Functions:
1. insert()        -> insert value
2. size()          -> total unique elements
3. empty()         -> checks container empty or not
4. find()          -> search value
5. count()         -> checks value exists or not
6. erase(value)    -> remove value
7. erase(iterator) -> remove single element
8. clear()         -> remove all elements
9. begin()         -> iterator to first element

Iterator Support:
- ++it -> supported
- --it -> supported
- it+2 -> NOT supported
- it-2 -> NOT supported

Comparator:
- greater<int> -> descending order sorting

Time Complexity:
- insert() -> O(log n)
- find()   -> O(log n)
- erase()  -> O(log n)
- count()  -> O(log n)

Example:
    10 20 30

========================================================
*/

#include <iostream>
#include <set>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(set<int> s)
{
    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); ++it)
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

    set<int> s; // empty set

    // insert values

    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10); // duplicate ignored

    cout << "Set elements: ";

    display(s);

    /*
    Output:
    10 20 30
    */

    cout << endl;

    // uniform initialization

    set<int> s2{5, 1, 3, 2, 5};

    cout << "Uniform initialized set: ";

    display(s2);

    /*
    Output:
    1 2 3 5
    */

    cout << endl;

    // insert new value

    s.insert(50);

    cout << "After insert(): ";

    display(s);

    /*
    Output:
    10 20 30 50
    */

    cout << endl
         << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(50);

    // size()

    cout << "s.size(): " << s.size() << endl;

    // empty()

    cout << "s.empty(): " << s.empty() << endl;

    cout << endl;

    // find()

    if (s.find(20) != s.end())
    {
        cout << "20 found" << endl;
    }

    cout << endl;

    // count()

    cout << "count(10): " << s.count(10) << endl;

    cout << "count(100): " << s.count(100) << endl;

    cout << endl;

    // begin()

    cout << "First element: " << *s.begin() << endl;

    cout << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);

    set<int>::iterator it;

    it = s.begin();

    cout << "Iterator value: " << *it << endl;

    ++it;

    cout << "Next value: " << *it << endl;

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

    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(50);

    // set values cannot be modified directly

    // erase old value and insert new value

    s.erase(20);

    s.insert(200);

    cout << "After update:" << endl;

    display(s);

    /*
    Output:
    10 30 50 200
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    set<int> s;

    s.insert(10);
    s.insert(30);
    s.insert(50);
    s.insert(200);

    // erase(value)

    s.erase(30);

    cout << "After erase(30): ";

    display(s);

    /*
    Output:
    10 50 200
    */

    cout << endl;

    // erase(iterator)

    set<int>::iterator it;

    it = s.find(50);

    if (it != s.end())
    {
        s.erase(it);
    }

    cout << "After erase(iterator): ";

    display(s);

    /*
    Output:
    10 200
    */

    cout << endl;

    // clear()

    s.clear();

    cout << "After clear()" << endl;

    cout << "s.empty(): " << s.empty() << endl;

    /*
    Output:
    s.empty(): 1
    */

    cout << endl;
}

// ================= COMPARATOR FUNCTION =================

void comparatorDemo()
{
    cout << "================ COMPARATOR =================\n"
         << endl;

    // greater<int> sorts in descending order

    set<int, greater<int>> ds;

    ds.insert(10);
    ds.insert(40);
    ds.insert(20);
    ds.insert(30);

    cout << "Descending order set: ";

    set<int, greater<int>>::iterator it;

    for (it = ds.begin(); it != ds.end(); ++it)
    {
        cout << *it << " ";
    }

    /*
    Output:
    40 30 20 10
    */

    cout << endl
         << endl;
}

// ================= MAIN FUNCTION =================

int main()
{
    createDemo();

    readDemo();

    iteratorDemo();

    updateDemo();

    deleteDemo();

    comparatorDemo();

    return 0;
}