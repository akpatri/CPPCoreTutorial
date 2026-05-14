/*
map stores data in key-value pair
Header file: #include <map>
Syntax: map<key_data_type, value_data_type> map_name;
Example: map<int, string> mp;
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

// reusable display function

void display(map<string, int> mp)
{
    for (pair<string, int> x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }
}

int main()
{
    // ================= CREATE =================

    map<string, int> mp; // empty map



    // uniform initialization

    map<string, int> student{
        {"Ali", 101},
        {"John", 102},
        {"Sam", 103}
    };

    cout << "Uniform initialized map:" << endl;

    display(student);

    /*
    Output:
    Ali -> 101
    John -> 102
    Sam -> 103
    */



    // map stores data in key-value pair

    // key   = unique
    // value = can be duplicate

    // map automatically stores keys in ascending order



    // insert using [] operator

    mp["Aman"] = 201;

    mp["David"] = 202;

    mp["Peter"] = 203;

    cout << "\nMap elements:" << endl;

    display(mp);

    /*
    Output:
    Aman -> 201
    David -> 202
    Peter -> 203
    */



    // insert() inserts key-value pair

    mp.insert({"Rohit", 204});

    cout << "\nAfter insert():" << endl;

    display(mp);

    /*
    Output:
    Aman -> 201
    David -> 202
    Peter -> 203
    Rohit -> 204
    */



    // make_pair() creates pair object

    mp.insert(make_pair("Karan", 205));

    cout << "\nAfter make_pair():" << endl;

    display(mp);

    /*
    Output:
    Aman -> 201
    David -> 202
    Karan -> 205
    Peter -> 203
    Rohit -> 204
    */



    // duplicate keys are NOT allowed

    // if same key inserted again
    // old value gets updated

    mp["Aman"] = 999;

    cout << "\nAfter duplicate key update:" << endl;

    display(mp);

    /*
    Output:
    Aman -> 999
    David -> 202
    Karan -> 205
    Peter -> 203
    Rohit -> 204
    */



    // ================= READ =================



    // access value using key

    cout << "\nmp[\"Peter\"]: " << mp["Peter"] << endl;

    // Output: 203



    // at() safely accesses value

    cout << "mp.at(\"David\"): " << mp.at("David") << endl;

    // Output: 202



    // size() returns total key-value pairs

    cout << "mp.size(): " << mp.size() << endl;

    // Output: 5



    // empty() checks map is empty or not

    // returns:
    // 1 = true
    // 0 = false

    cout << "mp.empty(): " << mp.empty() << endl;

    // Output: 0



    // find() searches key

    // returns iterator if key found
    // returns mp.end() if key not found

    if (mp.find("Karan") != mp.end())
    {
        cout << "Key Karan found" << endl;
    }

    // Output: Key Karan found



    // count() checks key exists or not

    // map stores unique keys only

    // returns:
    // 1 = key exists
    // 0 = key does not exist

    cout << "count(\"Aman\"): " << mp.count("Aman") << endl;

    // Output: 1

    cout << "count(\"Tom\"): " << mp.count("Tom") << endl;

    // Output: 0



    // ================= ITERATOR =================



    // map supports bidirectional iterator

    // ++it -> supported
    // --it -> supported

    // it+2 -> NOT supported
    // it-2 -> NOT supported



    map<string, int>::iterator it = mp.begin();

    cout << "\nFirst element:" << endl;

    cout << it->first << " -> " << it->second << endl;



    ++it;

    cout << "\nSecond element:" << endl;

    cout << it->first << " -> " << it->second << endl;



    // ================= UPDATE =================

    // update value using key

    mp["David"] = 500;

    cout << "\nAfter update:" << endl;

    display(mp);

    /*
    Output:
    Aman -> 999
    David -> 500
    Karan -> 205
    Peter -> 203
    Rohit -> 204
    */



    // ================= DELETE =================

    // erase() removes pair 
    mp.erase("Peter"); //using key
    mp.erase(mp.begin()); //using pointer
    mp.erase(mp.find("a"), mp.find("z")); //remove all pair from a(inclusive) to b(exclusive) 
    cout << "\nAfter erase(\"Peter\"):" << endl;

    

    display(mp);

    /*
    Output:
    Aman -> 999
    David -> 500
    Karan -> 205
    Rohit -> 204
    */



    // clear() removes all elements

    mp.clear();

    cout << "\nAfter clear()" << endl;



    // empty() now returns true

    cout << "mp.empty(): " << mp.empty() << endl;

    // Output: 1



    return 0;
}