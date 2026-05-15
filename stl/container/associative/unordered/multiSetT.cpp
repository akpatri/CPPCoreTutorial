/*
========================================================
            UNORDERED_MULTISET IN C++
========================================================

Definition:
- unordered_multiset stores values in unordered form
- Duplicate values are allowed
- Uses hashing for fast searching

Header File:
    #include <unordered_set>

Syntax:
    unordered_multiset<data_type> set_name;

Example:
    unordered_multiset<int> ums;

Internal Working:
- Internally implemented using Hash Table
- Uses hashing technique

Important Points:
1. Duplicate values are allowed
2. Unordered storage
3. Faster searching compared to multiset
4. No indexing
5. Values cannot be modified directly
6. Order is NOT fixed

Main Functions:
1. insert()        -> insert value
2. size()          -> total elements
3. empty()         -> checks container empty or not
4. count()         -> returns total occurrences
5. find()          -> search value
6. equal_range()   -> access duplicate values
7. erase(value)    -> remove all occurrences
8. erase(iterator) -> remove single occurrence
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
    30 10 20 10

Order is NOT fixed

========================================================
*/

#include <iostream>
#include <unordered_set>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(unordered_multiset<int> ums)
{
    unordered_multiset<int>::iterator it;

    for (it = ums.begin(); it != ums.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
}

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    unordered_multiset<int> ums; // empty unordered_multiset

    ums.insert(10);
    ums.insert(20);
    ums.insert(10); // duplicate allowed
    ums.insert(30);

    cout << "unordered_multiset elements: ";

    display(ums);

    /*
    Output can be:
    30 10 20 10
    */

    cout << endl;

    // insert more values

    ums.insert(40);
    ums.insert(20);

    cout << "After insert(): ";

    display(ums);

    /*
    Output can be:
    40 30 20 20 10 10
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    unordered_multiset<int> ums;

    ums.insert(10);
    ums.insert(20);
    ums.insert(10);
    ums.insert(30);
    ums.insert(40);
    ums.insert(20);

    // size()

    cout << "ums.size(): " << ums.size() << endl;

    // empty()

    cout << "ums.empty(): " << ums.empty() << endl;

    cout << endl;

    // count()

    cout << "count(10): " << ums.count(10) << endl;

    cout << "count(20): " << ums.count(20) << endl;

    cout << endl;

    // find()

    if (ums.find(30) != ums.end())
    {
        cout << "30 found" << endl;
    }

    cout << endl;

    // equal_range()

    pair<
        unordered_multiset<int>::iterator,
        unordered_multiset<int>::iterator>
        range = ums.equal_range(20);

    cout << "Values of 20: ";

    unordered_multiset<int>::iterator it;

    for (it = range.first; it != range.second; ++it)
    {
        cout << *it << " ";
    }

    /*
    Output can be:
    20 20
    */

    cout << endl
         << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    unordered_multiset<int> ums;

    ums.insert(10);
    ums.insert(20);
    ums.insert(30);

    unordered_multiset<int>::iterator it;

    it = ums.begin();

    cout << "First element: " << *it << endl;

    ++it;

    cout << "Second element: " << *it << endl;

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

    unordered_multiset<int> ums;

    ums.insert(10);
    ums.insert(20);
    ums.insert(10);
    ums.insert(30);
    ums.insert(40);
    ums.insert(20);

    // unordered_multiset values cannot be updated directly

    // erase old value and insert new value

    unordered_multiset<int>::iterator it;

    it = ums.find(30);

    if (it != ums.end())
    {
        ums.erase(it); // remove single occurrence
    }

    ums.insert(300);

    cout << "After update:" << endl;

    display(ums);

    /*
    Output can be:
    300 40 20 20 10 10
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    unordered_multiset<int> ums;

    ums.insert(10);
    ums.insert(20);
    ums.insert(10);
    ums.insert(20);
    ums.insert(40);
    ums.insert(300);

    // erase(value)

    ums.erase(10);

    cout << "After erase(10): ";

    display(ums);

    /*
    Output can be:
    300 40 20 20
    */

    cout << endl;

    // erase(iterator)

    unordered_multiset<int>::iterator it;

    it = ums.find(20);

    if (it != ums.end())
    {
        ums.erase(it); // removes single occurrence
    }

    cout << "After erase(iterator): ";

    display(ums);

    /*
    Output can be:
    300 40 20
    */

    cout << endl;

    // clear()

    ums.clear();

    cout << "After clear()" << endl;

    cout << "ums.empty(): " << ums.empty() << endl;

    /*
    Output:
    ums.empty(): 1
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