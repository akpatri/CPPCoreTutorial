/*
========================================================
               UNORDERED_MAP IN C++
========================================================

Definition:
- unordered_map stores data in key-value pair
- Uses hashing for fast searching
- Elements are NOT stored in sorted order

Header File:
    #include <unordered_map>

Syntax:
    unordered_map<key_data_type, value_data_type> map_name;

Example:
    unordered_map<int, string> um;

Internal Working:
- Internally implemented using Hash Table
- Uses hashing technique

Important Points:
1. Stores data in key-value pair
2. Keys are unique
3. Unordered storage
4. Faster searching compared to map
5. No indexing by position
6. [] operator supported
7. first = key
8. second = value

Main Functions:
1. insert()     -> insert key-value pair
2. [] operator  -> insert/access/update value
3. at()         -> safely access value
4. size()       -> total key-value pairs
5. empty()      -> checks container empty or not
6. find()       -> search key
7. count()      -> checks key exists or not
8. erase()      -> remove key-value pair
9. clear()      -> remove all elements

Iterator Support:
- Forward iterator supported
- ++it -> supported
- --it -> NOT supported

Time Complexity:
(Average Case)
- insert() -> O(1)
- find()   -> O(1)
- erase()  -> O(1)

(Worst Case)
- O(n)

Example Output:
    3 -> Sam
    2 -> John
    1 -> Ali

Order is NOT fixed

========================================================
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(unordered_map<int, string> um)
{
    unordered_map<int, string>::iterator it;

    for (it = um.begin(); it != um.end(); ++it)
    {
        cout << it->first << " -> " << it->second << endl;
    }
}

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    unordered_map<int, string> um; // empty unordered_map

    // insert using [] operator

    um[1] = "Ali";
    um[2] = "John";
    um[3] = "Sam";

    cout << "unordered_map elements:" << endl;

    display(um);

    /*
    Output can be:
    3 -> Sam
    2 -> John
    1 -> Ali
    */

    cout << endl;

    // insert() inserts key-value pair

    um.insert({4, "David"});

    cout << "After insert():" << endl;

    display(um);

    /*
    Output can be:
    4 -> David
    3 -> Sam
    2 -> John
    1 -> Ali
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    unordered_map<int, string> um;

    um[1] = "Ali";
    um[2] = "John";
    um[3] = "Sam";
    um[4] = "David";

    // [] operator

    cout << "um[1]: " << um[1] << endl;

    // at()

    cout << "um.at(2): " << um.at(2) << endl;

    // size()

    cout << "um.size(): " << um.size() << endl;

    // empty()

    cout << "um.empty(): " << um.empty() << endl;

    cout << endl;

    // find()

    if (um.find(3) != um.end())
    {
        cout << "Key 3 found" << endl;
    }

    cout << endl;

    // count()

    cout << "count(2): " << um.count(2) << endl;

    cout << "count(10): " << um.count(10) << endl;

    cout << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    unordered_map<int, string> um;

    um[1] = "Ali";
    um[2] = "John";
    um[3] = "Sam";

    unordered_map<int, string>::iterator it = um.begin();

    cout << "First element:" << endl;

    cout << it->first << " -> " << it->second << endl;

    ++it;

    cout << "\nSecond element:" << endl;

    cout << it->first << " -> " << it->second << endl;

    /*
    ++it -> supported
    --it -> NOT supported
    */

    cout << endl;
}

// ================= UPDATE FUNCTION =================

void updateDemo()
{
    cout << "================ UPDATE =================\n"
         << endl;

    unordered_map<int, string> um;

    um[1] = "Ali";
    um[2] = "John";
    um[3] = "Sam";
    um[4] = "David";

    // update value using key

    um[2] = "Peter";

    cout << "After update:" << endl;

    display(um);

    /*
    Output can be:
    4 -> David
    3 -> Sam
    2 -> Peter
    1 -> Ali
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    unordered_map<int, string> um;

    um[1] = "Ali";
    um[2] = "Peter";
    um[3] = "Sam";
    um[4] = "David";

    // erase()

    um.erase(3);

    cout << "After erase(3):" << endl;

    display(um);

    /*
    Output can be:
    4 -> David
    2 -> Peter
    1 -> Ali
    */

    cout << endl;

    // clear()

    um.clear();

    cout << "After clear()" << endl;

    cout << "um.empty(): " << um.empty() << endl;

    /*
    Output:
    um.empty(): 1
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