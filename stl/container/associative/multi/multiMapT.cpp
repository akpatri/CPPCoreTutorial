/*
========================================================
                 MULTIMAP IN C++
========================================================

Definition:
- multimap stores elements in key-value pair
- Multiple duplicate keys are allowed
- Elements are automatically stored in sorted order by key

Header File:
    #include <map>

Syntax:
    multimap<key_data_type, value_data_type> map_name;

Example:
    multimap<int, string> mm;

Internal Working:
- Internally implemented using Red Black Tree
- Uses bidirectional iterator

Important Points:
1. Duplicate keys are allowed
2. Keys are automatically sorted
3. No direct indexing
4. [] operator NOT supported
5. Key cannot be modified directly
6. Value can be modified using iterator

Main Functions:
1. insert()        -> insert key-value pair
2. size()          -> total elements
3. empty()         -> checks container empty or not
4. count(key)      -> total duplicate keys
5. find(key)       -> search key
6. equal_range()   -> access all duplicate keys
7. erase(key)      -> delete all matching keys
8. erase(iterator) -> delete single element
9. clear()         -> remove all elements

Iterator Support:
- ++it -> supported
- --it -> supported
- it+2 -> NOT supported
- it-2 -> NOT supported

Time Complexity:
- insert()       -> O(log n)
- find()         -> O(log n)
- erase()        -> O(log n)
- count()        -> O(log n + duplicates)

Example:
    1 -> Ali
    1 -> Sam
    2 -> John
    3 -> David

========================================================
*/

#include <iostream>
#include <map>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(multimap<int, string> mm)
{
    for (pair<int, string> x : mm)
    {
        cout << x.first << " -> " << x.second << endl;
    }
}

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    multimap<int, string> mm;

    // insert() inserts key-value pair

    mm.insert({1, "Ali"});
    mm.insert({2, "John"});
    mm.insert({1, "Sam"}); // duplicate key allowed
    mm.insert({3, "David"});

    cout << "Multimap elements:" << endl;

    display(mm);

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> John
    3 -> David
    */

    // uniform initialization

    multimap<int, string> mm2{
        {10, "A"},
        {20, "B"},
        {10, "C"}};

    cout << "\nUniform initialized multimap:" << endl;

    display(mm2);

    /*
    Output:
    10 -> A
    10 -> C
    20 -> B
    */

    // make_pair()

    mm.insert(make_pair(4, "Peter"));

    cout << "\nAfter make_pair():" << endl;

    display(mm);

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    multimap<int, string> mm{
        {1, "Ali"},
        {2, "John"},
        {1, "Sam"},
        {3, "David"}};

    // size()

    cout << "mm.size(): " << mm.size() << endl;

    // empty()

    cout << "mm.empty(): " << mm.empty() << endl;

    // count()

    cout << "count(1): " << mm.count(1) << endl;

    cout << "count(2): " << mm.count(2) << endl;

    // find()

    multimap<int, string>::iterator it = mm.find(1);

    if (it != mm.end())
    {
        cout << "Found key 1 -> " << it->second << endl;
    }

    // equal_range()

    pair<
        multimap<int, string>::iterator,
        multimap<int, string>::iterator>
        range = mm.equal_range(1);

    cout << "\nValues of key 1: ";

    for (
        multimap<int, string>::iterator i = range.first;
        i != range.second;
        ++i)
    {
        cout << i->second << " ";
    }

    cout << endl
         << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    multimap<int, string> mm{
        {1, "Ali"},
        {2, "John"},
        {3, "David"}};

    multimap<int, string>::iterator it = mm.begin();

    cout << "First element:" << endl;

    cout << it->first << " -> " << it->second << endl;

    ++it;

    cout << "\nSecond element:" << endl;

    cout << it->first << " -> " << it->second << endl;

    cout << endl;
}

// ================= UPDATE FUNCTION =================

void updateDemo()
{
    cout << "================ UPDATE =================\n"
         << endl;

    multimap<int, string> mm{
        {1, "Ali"},
        {2, "John"},
        {1, "Sam"}};

    // update value using iterator

    multimap<int, string>::iterator it = mm.find(2);

    if (it != mm.end())
    {
        it->second = "Robert";
    }

    cout << "After update:" << endl;

    display(mm);

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> Robert
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    multimap<int, string> mm{
        {1, "Ali"},
        {1, "Sam"},
        {2, "Robert"},
        {3, "David"},
        {4, "Peter"}};

    // erase(key)

    mm.erase(3);

    cout << "After erase(3):" << endl;

    display(mm);

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> Robert
    4 -> Peter
    */

    // erase(iterator)

    multimap<int, string>::iterator it = mm.find(1);

    if (it != mm.end())
    {
        mm.erase(it);
    }

    cout << "\nAfter erase(iterator):" << endl;

    display(mm);

    /*
    Output:
    1 -> Sam
    2 -> Robert
    4 -> Peter
    */

    // clear()

    mm.clear();

    cout << "\nAfter clear()" << endl;

    cout << "mm.empty(): " << mm.empty() << endl;

    /*
    Output:
    mm.empty(): 1
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