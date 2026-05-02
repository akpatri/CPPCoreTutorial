/*
map stores data in key-value pair

Header file:
#include <map>

Syntax:
map<key_data_type, value_data_type> map_name;

Example:
map<int, string> mp;

Important points:
1. Stores data using key-value pair
2. Keys are unique
3. Data stored in sorted order by key
4. Internally uses Red Black Tree
5. No indexing
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    // ================= CREATE =================

    map<int, string> mp; // empty map

    mp[1] = "Ali"; // insert key-value pair

    mp[2] = "John";

    mp[3] = "Sam";

    cout << "map elements:" << endl;

    for(auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl; // first = key , second = value
    }

    /*
    Output:
    1 -> Ali
    2 -> John
    3 -> Sam
    */

    cout << endl;


    // insert() inserts key-value pair

    mp.insert({4, "David"});

    cout << "After insert():" << endl;

    for(auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output:
    1 -> Ali
    2 -> John
    3 -> Sam
    4 -> David
    */

    cout << endl;



    // ================= READ =================

    cout << "mp[1]: " << mp[1] << endl; // access value using key
    // Output: mp[1]: Ali

    cout << "mp.at(2): " << mp.at(2) << endl; // at() safely accesses value
    // Output: mp.at(2): John

    cout << "mp.size(): " << mp.size() << endl; // size() returns total pairs
    // Output: mp.size(): 4

    cout << "mp.empty(): " << mp.empty() << endl; // empty() checks map is empty or not
    // Output: mp.empty(): 0

    cout << endl;


    // find() searches key

    if(mp.find(3) != mp.end())
    {
        cout << "Key 3 found" << endl;
    }

    // Output: Key 3 found

    cout << endl;


    // count() checks key exists or not

    cout << "count(2): " << mp.count(2) << endl;
    // Output: count(2): 1

    cout << "count(10): " << mp.count(10) << endl;
    // Output: count(10): 0

    cout << endl;



    // ================= UPDATE =================

    mp[2] = "Peter"; // update value using key

    cout << "After update:" << endl;

    for(auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output:
    1 -> Ali
    2 -> Peter
    3 -> Sam
    4 -> David
    */

    cout << endl;



    // ================= DELETE =================

    mp.erase(3); // erase() removes pair using key

    cout << "After erase(3):" << endl;

    for(auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    /*
    Output:
    1 -> Ali
    2 -> Peter
    4 -> David
    */

    cout << endl;


    mp.clear(); // clear() removes all elements

    cout << "mp.empty(): " << mp.empty() << endl;
    // Output: mp.empty(): 1

    return 0;
}