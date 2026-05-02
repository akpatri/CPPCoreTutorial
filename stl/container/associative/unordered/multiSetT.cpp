/*
unordered_multiset stores values in unordered form

Header file:
#include <unordered_set>

Syntax:
unordered_multiset<data_type> set_name;

Example:
unordered_multiset<int> ums;

Important points:
1. Duplicate values are allowed
2. Unordered storage
3. Faster searching using hashing
4. No indexing
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // ================= CREATE =================

    unordered_multiset<int> ums; // empty unordered_multiset

    ums.insert(10); // insert() adds value

    ums.insert(20);

    ums.insert(10); // duplicate allowed

    ums.insert(30);

    cout << "unordered_multiset elements: ";

    for(int x : ums)
    {
        cout << x << " ";
    }

    /*
    Output can be:
    30 10 20 10

    Order is not fixed
    */

    cout << endl << endl;


    // insert() inserts more values

    ums.insert(40);

    ums.insert(20);

    cout << "After insert(): ";

    for(int x : ums)
    {
        cout << x << " ";
    }

    /*
    Output can be:
    40 30 20 20 10 10
    */

    cout << endl << endl;



    // ================= READ =================

    cout << "ums.size(): " << ums.size() << endl; // size() returns total elements
    // Output: ums.size(): 6

    cout << "ums.empty(): " << ums.empty() << endl; // empty() checks set is empty or not
    // Output: ums.empty(): 0

    cout << endl;


    // count() returns total occurrences

    cout << "count(10): " << ums.count(10) << endl;
    // Output: count(10): 2

    cout << "count(20): " << ums.count(20) << endl;
    // Output: count(20): 2

    cout << endl;


    // find() searches value

    if(ums.find(30) != ums.end())
    {
        cout << "30 found" << endl;
    }

    // Output: 30 found

    cout << endl;


    // equal_range() accesses duplicate values

    auto range = ums.equal_range(20);

    cout << "Values of 20: ";

    for(auto it = range.first; it != range.second; it++)
    {
        cout << *it << " ";
    }

    // Output: 20 20

    cout << endl << endl;



    // ================= UPDATE =================

    // unordered_multiset values cannot be updated directly

    // erase old value and insert new value

    auto it2 = ums.find(30);

    if(it2 != ums.end())
    {
        ums.erase(it2); // remove single occurrence
    }

    ums.insert(300);

    cout << "After update:" << endl;

    for(int x : ums)
    {
        cout << x << " ";
    }

    /*
    Output can be:
    300 40 20 20 10 10
    */

    cout << endl << endl;



    // ================= DELETE =================

    ums.erase(10); // erase(value) removes all occurrences of 10

    cout << "After erase(10): ";

    for(int x : ums)
    {
        cout << x << " ";
    }

    /*
    Output can be:
    300 40 20 20
    */

    cout << endl << endl;


    auto it3 = ums.find(20);

    if(it3 != ums.end())
    {
        ums.erase(it3); // erase(iterator) removes single occurrence
    }

    cout << "After erase(iterator): ";

    for(int x : ums)
    {
        cout << x << " ";
    }

    /*
    Output can be:
    300 40 20
    */

    cout << endl << endl;


    ums.clear(); // clear() removes all elements

    cout << "ums.empty(): " << ums.empty() << endl;
    // Output: ums.empty(): 1

    return 0;
}