/*
========================================================
            UNORDERED_MULTIMAP IN C++
========================================================

Definition:
- unordered_multimap stores data in key-value pair
- Duplicate keys are allowed
- Uses hashing for fast searching
- Elements are NOT stored in sorted order

Header File:
    #include <unordered_map>

Syntax:
    unordered_multimap<key_data_type, value_data_type> map_name;

Example:
    unordered_multimap<int, string> umm;

Internal Working:
- Internally implemented using Hash Table
- Uses hashing technique

Important Points:
1. Stores data in key-value pair
2. Duplicate keys are allowed
3. Unordered storage
4. Faster searching compared to multimap
5. No indexing by position
6. [] operator NOT supported
7. first = key
8. second = value

Main Functions:
1. insert()        -> insert key-value pair
2. size()          -> total key-value pairs
3. empty()         -> checks container empty or not
4. count()         -> returns duplicate key count
5. find()          -> search key
6. equal_range()  -> access all duplicate keys
7. erase(key)      -> delete all matching keys
8. erase(iterator) -> delete single element
9. clear()         -> remove all elements

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
    3 -> David
    1 -> Sam
    2 -> John
    1 -> Ali

Order is NOT fixed

========================================================
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(unordered_multimap<int, string> umm)
{
    unordered_multimap<int, string>::iterator it;

    for (it = umm.begin(); it != umm.end(); ++it)
    {
        cout << it->first << " -> " << it->second << endl;
    }
}

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    unordered_multimap<int, string> umm;

    // insert key-value pairs

    umm.insert({1, "Ali"});
    umm.insert({2, "John"});
    umm.insert({1, "Sam"}); // duplicate key allowed
    umm.insert({3, "David"});

    cout << "unordered_multimap elements:" << endl;

    display(umm);

    /*
    Output can be:
    3 -> David
    1 -> Sam
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

    unordered_multimap<int, string> umm;

    umm.insert({1, "Ali"});
    umm.insert({2, "John"});
    umm.insert({1, "Sam"});
    umm.insert({3, "David"});

    // size()

    cout << "umm.size(): " << umm.size() << endl;

    // empty()

    cout << "umm.empty(): " << umm.empty() << endl;

    cout << endl;

    // count()

    cout << "count(1): " << umm.count(1) << endl;

    cout << "count(2): " << umm.count(2) << endl;

    cout << endl;

    // find()

    unordered_multimap<int, string>::iterator it;

    it = umm.find(1);

    if (it != umm.end())
    {
        cout << "Found key 1 -> " << it->second << endl;
    }

    cout << endl;

    // equal_range()

    pair<
        unordered_multimap<int, string>::iterator,
        unordered_multimap<int, string>::iterator>
        range = umm.equal_range(1);

    cout << "Values of key 1: ";

    unordered_multimap<int, string>::iterator i;

    for (i = range.first; i != range.second; ++i)
    {
        cout << i->second << " ";
    }

    /*
    Output can be:
    Ali Sam
    */

    cout << endl
         << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    unordered_multimap<int, string> umm;

    umm.insert({1, "Ali"});
    umm.insert({2, "John"});
    umm.insert({3, "Sam"});

    unordered_multimap<int, string>::iterator it;

    it = umm.begin();

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

    unordered_multimap<int, string> umm;

    umm.insert({1, "Ali"});
    umm.insert({2, "John"});
    umm.insert({1, "Sam"});
    umm.insert({3, "David"});

    // update value using iterator

    unordered_multimap<int, string>::iterator it;

    it = umm.find(2);

    if (it != umm.end())
    {
        it->second = "Peter";
    }

    cout << "After update:" << endl;

    display(umm);

    /*
    Output can be:
    3 -> David
    1 -> Sam
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

    unordered_multimap<int, string> umm;

    umm.insert({1, "Ali"});
    umm.insert({2, "Peter"});
    umm.insert({1, "Sam"});
    umm.insert({3, "David"});

    // erase(key)

    umm.erase(3);

    cout << "After erase(3):" << endl;

    display(umm);

    /*
    Output can be:
    1 -> Sam
    2 -> Peter
    1 -> Ali
    */

    cout << endl;

    // erase(iterator)

    unordered_multimap<int, string>::iterator it;

    it = umm.find(1);

    if (it != umm.end())
    {
        umm.erase(it);
    }

    cout << "After erase(iterator):" << endl;

    display(umm);

    /*
    Output can be:
    2 -> Peter
    1 -> Ali
    */

    cout << endl;

    // clear()

    umm.clear();

    cout << "After clear()" << endl;

    cout << "umm.empty(): " << umm.empty() << endl;

    /*
    Output:
    umm.empty(): 1
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