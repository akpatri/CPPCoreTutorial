/*
set stores unique values in sorted order

Header file:
#include <set>

Syntax:
set<data_type> set_name;

Example:
set<int> s;

Important points:
1. Stores only unique values
2. Values stored in sorted order
3. Duplicate values are ignored
4. Internally uses Red Black Tree
5. No indexing
*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    // ================= CREATE =================

    set<int> s; // empty set

    s.insert(30); // insert() adds value

    s.insert(10);

    s.insert(20);

    s.insert(10); // duplicate value ignored

    cout << "set elements: ";

    for(int x : s)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 20 30
    */

    cout << endl << endl;


    // insert() inserts new value

    s.insert(50);

    cout << "After insert(): ";

    for(int x : s)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 20 30 50
    */

    cout << endl << endl;



    // ================= READ =================

    cout << "s.size(): " << s.size() << endl; // size() returns total unique elements
    // Output: s.size(): 4

    cout << "s.empty(): " << s.empty() << endl; // empty() checks set is empty or not
    // Output: s.empty(): 0

    cout << endl;


    // find() searches value

    if(s.find(20) != s.end())
    {
        cout << "20 found" << endl;
    }

    // Output: 20 found

    cout << endl;


    // count() checks value exists or not

    cout << "count(10): " << s.count(10) << endl;
    // Output: count(10): 1

    cout << "count(100): " << s.count(100) << endl;
    // Output: count(100): 0

    cout << endl;


    // begin() returns iterator of first element

    cout << "First element: " << *s.begin() << endl;
    // Output: First element: 10

    cout << endl;



    // ================= UPDATE =================

    // set values cannot be updated directly

    // erase old value and insert new value

    s.erase(20);

    s.insert(200);

    cout << "After update:" << endl;

    for(int x : s)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 30 50 200
    */

    cout << endl << endl;



    // ================= DELETE =================

    s.erase(30); // erase() removes value

    cout << "After erase(30): ";

    for(int x : s)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 50 200
    */

    cout << endl << endl;


    auto it = s.find(50);

    if(it != s.end())
    {
        s.erase(it); // erase(iterator) removes single element
    }

    cout << "After erase(iterator): ";

    for(int x : s)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 200
    */

    cout << endl << endl;


    s.clear(); // clear() removes all elements

    cout << "s.empty(): " << s.empty() << endl;
    // Output: s.empty(): 1

    return 0;
}