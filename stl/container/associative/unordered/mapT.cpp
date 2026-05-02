/*
unordered_map stores data in key-value pair
Header file: #include <unordered_map>
Syntax: unordered_map<key_data_type, value_data_type> map_name;
Example: unordered_map<int, string> um;
Important points:
1. Stores data using key-value pair
2. Keys are unique
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
    unordered_map<int, string> um; // empty unordered_map
    um[1] = "Ali"; // insert key-value pair
    um[2] = "John";
    um[3] = "Sam";
    cout << "unordered_map elements:" << endl;
    for(auto x : um)
    {
        cout << x.first << " -> " << x.second << endl; // first = key , second = value
    }
    /*
    Output can be:
    3 -> Sam
    2 -> John
    1 -> Ali
    Order is not fixed
    */
    cout << endl;

    // insert() inserts key-value pair
    um.insert({4, "David"});
    cout << "After insert():" << endl;
    for(auto x : um)
    {
        cout << x.first << " -> " << x.second << endl;
    }
    /*
    Output can be:
    4 -> David
    3 -> Sam
    2 -> John
    1 -> Ali
    */
    cout << endl;

    // ================= READ =================
    cout << "um[1]: " << um[1] << endl; // access value using key // Output: um[1]: Ali
    cout << "um.at(2): " << um.at(2) << endl; // at() safely accesses value // Output: um.at(2): John
    cout << "um.size(): " << um.size() << endl; // size() returns total pairs // Output: um.size(): 4
    cout << "um.empty(): " << um.empty() << endl; // empty() checks map is empty or not // Output: um.empty(): 0
    cout << endl;

    // find() searches key
    if(um.find(3) != um.end())
    {
        cout << "Key 3 found" << endl;
    } // Output: Key 3 found
    cout << endl;

    // count() checks key exists or not
    cout << "count(2): " << um.count(2) << endl; // Output: count(2): 1
    cout << "count(10): " << um.count(10) << endl; // Output: count(10): 0
    cout << endl;

    // ================= UPDATE =================
    um[2] = "Peter"; // update value using key
    cout << "After update:" << endl;
    for(auto x : um)
    {
        cout << x.first << " -> " << x.second << endl;
    }
    /*
    Output can be:
    4 -> David
    3 -> Sam
    2 -> Peter
    1 -> Ali
    */
    cout << endl;

    // ================= DELETE =================
    um.erase(3); // erase() removes pair using key
    cout << "After erase(3):" << endl;
    for(auto x : um)
    {
        cout << x.first << " -> " << x.second << endl;
    }
    /*
    Output can be:
    4 -> David
    2 -> Peter
    1 -> Ali
    */
    cout << endl;
    
    um.clear(); // clear() removes all elements
    cout << "um.empty(): " << um.empty() << endl; // Output: um.empty(): 1

    return 0;
}