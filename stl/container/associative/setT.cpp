/*
set stores unique values in sorted order
Header file:#include <set>
Syntax: set<data_type> set_name;
Example: set<int> s;
Important points:
1. Stores only unique values
2. Values are readonly and stored in sorted order
3. Duplicate values are ignored
4. Internally uses Red Black Tree
5. No indexing
*/

#include <iostream>
#include <set>
using namespace std;

// reusable display function

void display(set<int> s)
{
    for (int x : s)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    // ================= CREATE =================

    set<int> s; // empty set

    // set stores only unique values

    // duplicate values are ignored

    // set automatically stores values in ascending order

    // insert() adds value

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

    // uniform initialization

    set<int> s2{5, 1, 3, 2, 5};

    cout << "\nUniform initialized set: ";

    display(s2);

    /*
    Output:
    1 2 3 5
    */

    // insert() inserts new value

    s.insert(50);

    cout << "\nAfter insert(): ";

    display(s);

    /*
    Output:
    10 20 30 50
    */

    // ================= READ =================

    // size() returns total unique elements

    cout << "\ns.size(): " << s.size() << endl;

    // Output: 4

    // empty() checks set is empty or not

    // returns:
    // 1 = true
    // 0 = false

    cout << "s.empty(): " << s.empty() << endl;

    // Output: 0

    // find() searches value

    // returns iterator if found
    // returns s.end() if not found

    if (s.find(20) != s.end())
    {
        cout << "20 found" << endl;
    }

    // Output: 20 found

    // count() checks value exists or not

    // returns:
    // 1 = exists
    // 0 = does not exist

    cout << "count(10): " << s.count(10) << endl;

    // Output: 1

    cout << "count(100): " << s.count(100) << endl;

    // Output: 0

    // begin() returns iterator to first element

    cout << "First element: " << *s.begin() << endl;

    // Output: 10

    // ================= ITERATOR =================

    // set supports bidirectional iterator

    // ++it -> supported
    // --it -> supported

    // it+2 -> NOT supported
    // it-2 -> NOT supported

    set<int>::iterator it = s.begin();

    cout << "\nIterator value: " << *it << endl;

    // Output: 10

    ++it;

    cout << "Next value: " << *it << endl;

    // Output: 20

    // ================= UPDATE =================

    // set values cannot be modified directly

    // because modifying value may break sorted order

    // so:
    // erase old value
    // insert new value

    s.erase(20);

    s.insert(200);

    cout << "\nAfter update:" << endl;

    display(s);

    /*
    Output:
    10 30 50 200
    */

    // ================= DELETE =================

    // erase(value) removes value

    s.erase(30);

    cout << "\nAfter erase(30): ";

    display(s);

    /*
    Output:
    10 50 200
    */

    // erase(iterator) removes single element

    set<int>::iterator it2 = s.find(50);

    if (it2 != s.end())
    {
        s.erase(it2);
    }

    cout << "\nAfter erase(iterator): ";

    display(s);

    /*
    Output:
    10 200
    */

    // clear() removes all elements

    s.clear();

    cout << "\nAfter clear()" << endl;

    cout << "s.empty(): " << s.empty() << endl;

    // Output: 1

    // ================= COMPARATOR =================

    // greater<int> sorts elements in descending order

    set<int, greater<int>> ds;

    ds.insert(10);

    ds.insert(40);

    ds.insert(20);

    ds.insert(30);

    cout << "\nDescending order set: ";

    for (int x : ds)
    {
        cout << x << " ";
    }

    /*
    Output:
    40 30 20 10
    */

    return 0;
}