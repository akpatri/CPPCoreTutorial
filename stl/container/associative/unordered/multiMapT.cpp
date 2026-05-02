/*
unordered_multimap stores data in key-value pair

Header file:
#include <unordered_map>

Syntax:
unordered_multimap<key_data_type, value_data_type> map_name;

Example:
unordered_multimap<int, string> umm;

Important points:
1. Stores data using key-value pair
2. Duplicate keys are allowed
3. Unordered storage
4. Faster searching using hashing
5. No indexing
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // ================= CREATE =================

    unordered_multimap<int, string> umm; // empty unordered_multimap

    umm.insert({1, "Ali"}); // insert key-value pair

    umm.insert({2, "John"});

    umm.insert({1, "Sam"}); // duplicate key allowed

    umm.insert({3, "David"});

    cout << "unordered_multimap elements:" << endl;

    for(auto x : umm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output can be:
    3 -> David
    1 -> Sam
    2 -> John
    1 -> Ali

    Order is not fixed
    */

    cout << endl;



    // ================= READ =================

    cout << "umm.size(): " << umm.size() << endl; // size() returns total pairs
    // Output: umm.size(): 4

    cout << "umm.empty(): " << umm.empty() << endl; // empty() checks map is empty or not
    // Output: umm.empty(): 0

    cout << endl;


    // count() returns number of duplicate keys

    cout << "count(1): " << umm.count(1) << endl;
    // Output: count(1): 2

    cout << "count(2): " << umm.count(2) << endl;
    // Output: count(2): 1

    cout << endl;


    // find() returns iterator to first matching key

    auto it = umm.find(1);

    if(it != umm.end())
    {
        cout << "Found key 1 -> " << it->second << endl;
    }

    // Output can be: Found key 1 -> Ali

    cout << endl;


    // equal_range() accesses all duplicate keys

    auto range = umm.equal_range(1);

    cout << "Values of key 1: ";

    for(auto i = range.first; i != range.second; i++)
    {
        cout << i->second << " ";
    }

    // Output can be: Ali Sam

    cout << endl << endl;



    // ================= UPDATE =================

    // unordered_multimap does not support [] operator

    // update using iterator

    auto it2 = umm.find(2);

    if(it2 != umm.end())
    {
        it2->second = "Peter";
    }

    cout << "After update:" << endl;

    for(auto x : umm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output can be:
    3 -> David
    1 -> Sam
    2 -> Peter
    1 -> Ali
    */

    cout << endl;



    // ================= DELETE =================

    umm.erase(3); // erase() removes all pairs with key 3

    cout << "After erase(3):" << endl;

    for(auto x : umm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output can be:
    1 -> Sam
    2 -> Peter
    1 -> Ali
    */

    cout << endl;


    auto it3 = umm.find(1);

    if(it3 != umm.end())
    {
        umm.erase(it3); // erase(iterator) removes single element
    }

    cout << "After erase(iterator):" << endl;

    for(auto x : umm)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output can be:
    2 -> Peter
    1 -> Ali
    */

    cout << endl;


    umm.clear(); // clear() removes all elements

    cout << "umm.empty(): " << umm.empty() << endl;
    // Output: umm.empty(): 1

    return 0;
}