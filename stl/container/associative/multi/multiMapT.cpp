/*
multimap stores data in key-value pair
Header file: #include <map>
Syntax: multimap<key_data_type, value_data_type> map_name;
Example: multimap<int, string> mm;
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

#include <iostream>
#include <map>
using namespace std;

// reusable display function

void display(multimap<int, string> mm)
{
    for (pair<int, string> x : mm)
    {
        cout << x.first << " -> " << x.second << endl;
    }
}

int main()
{
    // ================= CREATE =================

    multimap<int, string> mm; // empty multimap

    // multimap stores key-value pairs

    // duplicate keys are allowed

    // values are automatically sorted by key

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

    // make_pair() creates pair object

    mm.insert(make_pair(4, "Peter"));

    cout << "\nAfter make_pair():" << endl;

    display(mm);

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> John
    3 -> David
    4 -> Peter
    */

    // ================= READ =================

    // size() returns total key-value pairs

    cout << "\nmm.size(): " << mm.size() << endl;

    // Output: 5

    // empty() checks multimap is empty or not

    // returns:
    // 1 = true
    // 0 = false

    cout << "mm.empty(): " << mm.empty() << endl;

    // Output: 0

    // count() returns total duplicate keys

    cout << "count(1): " << mm.count(1) << endl;

    // Output: 2

    cout << "count(2): " << mm.count(2) << endl;

    // Output: 1

    // find() searches key

    // returns iterator if found
    // returns mm.end() if not found

    multimap<int, string>::iterator it = mm.find(1);

    if (it != mm.end())
    {
        cout << "Found key 1 -> " << it->second << endl;
    }

    // Output: Found key 1 -> Ali

    // equal_range() accesses all duplicate keys

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

    // Output: Ali Sam

    // ================= ITERATOR =================

    // multimap supports bidirectional iterator

    // ++it -> supported
    // --it -> supported

    // it+2 -> NOT supported
    // it-2 -> NOT supported

    multimap<int, string>::iterator it2 = mm.begin();

    cout << "\n\nFirst element:" << endl;

    cout << it2->first << " -> " << it2->second << endl;

    ++it2;

    cout << "\nSecond element:" << endl;

    cout << it2->first << " -> " << it2->second << endl;

    // ================= UPDATE =================

    // multimap does NOT support [] operator

    // update value using iterator

    multimap<int, string>::iterator it3 = mm.find(2);

    if (it3 != mm.end())
    {
        it3->second = "Robert";
    }

    cout << "\nAfter update:" << endl;

    display(mm);

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> Robert
    3 -> David
    4 -> Peter
    */

    // ================= DELETE =================

    // erase(key) removes all pairs with same key

    mm.erase(3);

    cout << "\nAfter erase(3):" << endl;

    display(mm);

    /*
    Output:
    1 -> Ali
    1 -> Sam
    2 -> Robert
    4 -> Peter
    */

    // erase(iterator) removes single element

    multimap<int, string>::iterator it4 = mm.find(1);

    if (it4 != mm.end())
    {
        mm.erase(it4);
    }

    cout << "\nAfter erase(iterator):" << endl;

    display(mm);

    /*
    Output:
    1 -> Sam
    2 -> Robert
    4 -> Peter
    */

    // clear() removes all elements

    mm.clear();

    cout << "\nAfter clear()" << endl;

    // empty() now returns true

    cout << "mm.empty(): " << mm.empty() << endl;

    // Output: 1

    return 0;
}