/*
multiset stores values in sorted order

Header file:
#include <set>

Syntax:
multiset<data_type> set_name;

Example:
multiset<int> ms;

Important points:
1. Duplicate values are allowed
2. Values stored in sorted order
3. Internally uses Red Black Tree
4. No indexing
*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    // ================= CREATE =================

    multiset<int> ms; // empty multiset

    ms.insert(30); // insert() adds value

    ms.insert(10);

    ms.insert(20);

    ms.insert(10); // duplicate allowed

    cout << "multiset elements: ";

    for(int x : ms)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 10 20 30
    */

    cout << endl << endl;


    // insert() inserts more values

    ms.insert(40);

    ms.insert(20);

    cout << "After insert(): ";

    for(int x : ms)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 10 20 20 30 40
    */

    cout << endl << endl;



    // ================= READ =================

    cout << "ms.size(): " << ms.size() << endl; // size() returns total elements
    // Output: ms.size(): 6

    cout << "ms.empty(): " << ms.empty() << endl; // empty() checks multiset is empty or not
    // Output: ms.empty(): 0

    cout << endl;


    // count() returns total occurrences

    cout << "count(10): " << ms.count(10) << endl;
    // Output: count(10): 2

    cout << "count(20): " << ms.count(20) << endl;
    // Output: count(20): 2

    cout << endl;


    // find() searches value

    if(ms.find(30) != ms.end())
    {
        cout << "30 found" << endl;
    }

    // Output: 30 found

    cout << endl;


    // begin() returns iterator of first element

    cout << "First element: " << *ms.begin() << endl;
    // Output: First element: 10

    cout << endl;


    // equal_range() accesses duplicate values

    auto range = ms.equal_range(20);

    cout << "Values of 20: ";

    for(auto it = range.first; it != range.second; it++)
    {
        cout << *it << " ";
    }

    // Output: 20 20

    cout << endl << endl;



    // ================= UPDATE =================

    // multiset values cannot be updated directly

    // erase old value and insert new value

    auto it2 = ms.find(30);

    if(it2 != ms.end())
    {
        ms.erase(it2); // remove single occurrence
    }

    ms.insert(300);

    cout << "After update:" << endl;

    for(int x : ms)
    {
        cout << x << " ";
    }

    /*
    Output:
    10 10 20 20 40 300
    */

    cout << endl << endl;



    // ================= DELETE =================

    ms.erase(10); // erase(value) removes all occurrences of 10

    cout << "After erase(10): ";

    for(int x : ms)
    {
        cout << x << " ";
    }

    /*
    Output:
    20 20 40 300
    */

    cout << endl << endl;


    auto it3 = ms.find(20);

    if(it3 != ms.end())
    {
        ms.erase(it3); // erase(iterator) removes single occurrence
    }

    cout << "After erase(iterator): ";

    for(int x : ms)
    {
        cout << x << " ";
    }

    /*
    Output:
    20 40 300
    */

    cout << endl << endl;


    ms.clear(); // clear() removes all elements

    cout << "ms.empty(): " << ms.empty() << endl;
    // Output: ms.empty(): 1

    return 0;
}