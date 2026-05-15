/*
========================================================
                     MAP IN C++
========================================================

Definition:
- map stores data in key-value pair
- Keys are unique
- Elements are automatically stored in sorted order by key

Header File:
    #include <map>

Syntax:
    map<key_data_type, value_data_type> map_name;

Example:
    map<int, string> mp;

Internal Working:
- Internally implemented using Red Black Tree
- Uses bidirectional iterator

Important Points:
1. Stores data in key-value pair
2. Keys are unique
3. Values can be duplicate
4. Data stored in sorted order by key
5. No indexing by position
6. [] operator supported
7. first = key
8. second = value

Main Functions:
1. insert()       -> insert key-value pair
2. [] operator    -> insert/access/update value
3. at()           -> safely access value
4. size()         -> total key-value pairs
5. empty()        -> checks container empty or not
6. find()         -> search key
7. count()        -> checks key exists or not
8. erase(key)     -> remove pair using key
9. erase(iterator)-> remove single pair
10. erase(range)  -> remove range of pairs
11. clear()       -> remove all elements

Iterator Support:
- ++it -> supported
- --it -> supported
- it+2 -> NOT supported
- it-2 -> NOT supported

Time Complexity:
- insert() -> O(log n)
- find()   -> O(log n)
- erase()  -> O(log n)
- count()  -> O(log n)

Example:
    Aman  -> 201
    David -> 202
    Peter -> 203

========================================================
*/

#include <iostream>
#include <map>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(map<string, int> mp)
{
    map<string, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << " -> " << it->second << endl;
    }
}

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    map<string, int> mp; // empty map

    // uniform initialization

    map<string, int> student{
        {"Ali", 101},
        {"John", 102},
        {"Sam", 103}};

    cout << "Uniform initialized map:" << endl;

    display(student);

    /*
    Output:
    Ali -> 101
    John -> 102
    Sam -> 103
    */

    cout << endl;

    // insert using [] operator

    mp["Aman"] = 201;
    mp["David"] = 202;
    mp["Peter"] = 203;

    cout << "Map elements:" << endl;

    display(mp);

    /*
    Output:
    Aman -> 201
    David -> 202
    Peter -> 203
    */

    cout << endl;

    // insert()

    mp.insert({"Rohit", 204});

    cout << "After insert():" << endl;

    display(mp);

    cout << endl;

    // make_pair()

    mp.insert(make_pair("Karan", 205));

    cout << "After make_pair():" << endl;

    display(mp);

    cout << endl;

    // duplicate key update

    mp["Aman"] = 999;

    cout << "After duplicate key update:" << endl;

    display(mp);

    /*
    Output:
    Aman -> 999
    David -> 202
    Karan -> 205
    Peter -> 203
    Rohit -> 204
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    map<string, int> mp;

    mp["Aman"] = 999;
    mp["David"] = 202;
    mp["Karan"] = 205;
    mp["Peter"] = 203;
    mp["Rohit"] = 204;

    // [] operator

    cout << "mp[\"Peter\"]: " << mp["Peter"] << endl;

    // at()

    cout << "mp.at(\"David\"): " << mp.at("David") << endl;

    // size()

    cout << "mp.size(): " << mp.size() << endl;

    // empty()

    cout << "mp.empty(): " << mp.empty() << endl;

    cout << endl;

    // find()

    if (mp.find("Karan") != mp.end())
    {
        cout << "Key Karan found" << endl;
    }

    cout << endl;

    // count()

    cout << "count(\"Aman\"): " << mp.count("Aman") << endl;

    cout << "count(\"Tom\"): " << mp.count("Tom") << endl;

    cout << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    map<string, int> mp;

    mp["Aman"] = 999;
    mp["David"] = 202;
    mp["Karan"] = 205;

    map<string, int>::iterator it;

    it = mp.begin();

    cout << "First element:" << endl;

    cout << it->first << " -> " << it->second << endl;

    ++it;

    cout << "\nSecond element:" << endl;

    cout << it->first << " -> " << it->second << endl;

    /*
    ++it -> supported
    --it -> supported

    it+2 -> NOT supported
    it-2 -> NOT supported
    */

    cout << endl;
}

// ================= UPDATE FUNCTION =================

void updateDemo()
{
    cout << "================ UPDATE =================\n"
         << endl;

    map<string, int> mp;

    mp["Aman"] = 999;
    mp["David"] = 202;
    mp["Karan"] = 205;
    mp["Peter"] = 203;
    mp["Rohit"] = 204;

    // update value using key

    mp["David"] = 500;

    cout << "After update:" << endl;

    display(mp);

    /*
    Output:
    Aman -> 999
    David -> 500
    Karan -> 205
    Peter -> 203
    Rohit -> 204
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    map<string, int> mp;

    mp["Aman"] = 999;
    mp["David"] = 500;
    mp["Karan"] = 205;
    mp["Peter"] = 203;
    mp["Rohit"] = 204;

    // erase(key)

    mp.erase("Peter");

    cout << "After erase(\"Peter\"):" << endl;

    display(mp);

    cout << endl;

    // erase(iterator)

    mp.erase(mp.begin());

    cout << "After erase(begin()):" << endl;

    display(mp);

    cout << endl;

    // erase(range)

    mp.erase(mp.find("K"), mp.end());

    cout << "After erase(range):" << endl;

    display(mp);

    cout << endl;

    // clear()

    mp.clear();

    cout << "After clear()" << endl;

    cout << "mp.empty(): " << mp.empty() << endl;

    /*
    Output:
    mp.empty(): 1
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