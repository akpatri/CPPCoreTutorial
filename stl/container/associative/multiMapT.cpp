/*
multimap stores data in key-value pair

Header file:
#include <map>

Syntax:
multimap<key_data_type, value_data_type> map_name;

Example:
multimap<int, string> mm;

Important points:
1. Duplicate keys are allowed
2. Data stored in sorted order by key
3. Internally uses Red Black Tree
4. No indexing
5. No [] operator
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    // ================= CREATE =================

    multimap<int, string> mm; // empty multimap

    mm.insert({1, "Ali"}); // insert key-value pair

    mm.insert({2, "John"});

    mm.insert({1, "Sam"}); // duplicate key allowed

    mm.insert({3, "David"});

    cout << "multimap elements:" << endl;

    for(auto x : mm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> John
    3 -> David
    */

    cout << endl;



    // ================= READ =================

    cout << "mm.size(): " << mm.size() << endl; // size() returns total pairs
    // Output: mm.size(): 4

    cout << "mm.empty(): " << mm.empty() << endl; // empty() checks map is empty or not
    // Output: mm.empty(): 0

    cout << endl;


    // count() returns total duplicate keys

    cout << "count(1): " << mm.count(1) << endl;
    // Output: count(1): 2

    cout << "count(2): " << mm.count(2) << endl;
    // Output: count(2): 1

    cout << endl;


    // find() searches key

    auto it = mm.find(1);

    if(it != mm.end())
    {
        cout << "Found key 1 -> " << it->second << endl;
    }

    // Output: Found key 1 -> Ali

    cout << endl;


    // equal_range() accesses all duplicate keys

    auto range = mm.equal_range(1);

    cout << "Values of key 1: ";

    for(auto i = range.first; i != range.second; i++)
    {
        cout << i->second << " ";
    }

    // Output: Ali Sam

    cout << endl << endl;



    // ================= UPDATE =================

    // multimap does not support [] operator

    // update using iterator

    auto it2 = mm.find(2);

    if(it2 != mm.end())
    {
        it2->second = "Peter";
    }

    cout << "After update:" << endl;

    for(auto x : mm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> Peter
    3 -> David
    */

    cout << endl;



    // ================= DELETE =================

    mm.erase(3); // erase() removes all pairs with key 3

    cout << "After erase(3):" << endl;

    for(auto x : mm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> Peter
    */

    cout << endl;


    auto it3 = mm.find(1);

    if(it3 != mm.end())
    {
        mm.erase(it3); // erase(iterator) removes single element
    }

    cout << "After erase(iterator):" << endl;

    for(auto x : mm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output:
    1 -> Sam
    2 -> Peter
    */

    cout << endl;


    mm.clear(); // clear() removes all elements

    cout << "mm.empty(): " << mm.empty() << endl;
    // Output: mm.empty(): 1

    return 0;
}