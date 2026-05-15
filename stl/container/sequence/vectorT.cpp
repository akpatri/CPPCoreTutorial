/*
========================================================
                    VECTOR IN C++
========================================================

Definition:
- vector stores dynamic-size elements of same data type
- Size automatically grows or shrinks

Header File:
    #include <vector>

Syntax:
    vector<data_type> vector_name;

Example:
    vector<int> v;

Internal Working:
- Stored in contiguous memory
- Internally uses dynamic array
- Automatically reallocates memory when needed

Important Points:
1. Dynamic size
2. Fast random access using index
3. Supports indexing
4. Elements stored in contiguous memory
5. Automatic memory management
6. Slower insertion/deletion in middle
7. Faster insertion/deletion at end

Main Functions:
1. push_back() -> insert at end
2. pop_back()  -> remove last element
3. insert()    -> insert at specific position
4. erase()     -> remove specific element
5. clear()     -> remove all elements
6. at()        -> safe element access
7. front()     -> first element
8. back()      -> last element
9. size()      -> total elements
10. capacity() -> allocated memory
11. empty()    -> checks vector empty or not

Iterator Support:
- Random access iterator supported
- ++it  -> supported
- --it  -> supported
- it+2  -> supported
- it-2  -> supported

Difference:
- []   -> no bounds checking
- at() -> throws out_of_range exception

Time Complexity:
- Access        -> O(1)
- push_back()   -> O(1) average
- pop_back()    -> O(1)
- insert()      -> O(n)
- erase()       -> O(n)
- Traversal     -> O(n)

2D Vector Syntax:
    vector<vector<int>> matrix;

Example:
    vector<vector<int>> matrix =
    {
        {1,2,3},
        {4,5,6}
    };

========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(vector<int> v)
{
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); ++it)
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

    vector<int> v; // empty vector

    vector<int> v2 = {10, 20, 30};

    vector<int> v3(5);

    vector<int> v4(5, 100);

    vector<int> v5{1, 2, 3, 4, 5};

    cout << "v4 elements: ";

    display(v4);

    /*
    Output:
    100 100 100 100 100
    */

    cout << endl;

    // push_back()

    v2.push_back(40);

    v2.push_back(50);

    cout << "After push_back(): ";

    display(v2);

    /*
    Output:
    10 20 30 40 50
    */

    cout << endl;

    // insert()

    v2.insert(v2.begin() + 1, 99);

    cout << "After insert(): ";

    display(v2);

    /*
    Output:
    10 99 20 30 40 50
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    vector<int> v = {10, 99, 20, 30, 40, 50};

    // []

    cout << "v[0]: " << v[0] << endl;

    /*
    Output:
    10
    */

    // at()

    cout << "v.at(2): " << v.at(2) << endl;

    /*
    Output:
    20
    */

    // front()

    cout << "v.front(): " << v.front() << endl;

    /*
    Output:
    10
    */

    // back()

    cout << "v.back(): " << v.back() << endl;

    /*
    Output:
    50
    */

    // size()

    cout << "v.size(): " << v.size() << endl;

    /*
    Output:
    6
    */

    // capacity()

    cout << "v.capacity(): " << v.capacity() << endl;

    // empty()

    cout << "v.empty(): " << v.empty() << endl;

    /*
    Output:
    0
    */

    cout << endl;

    // iterator traversal

    vector<int>::iterator it;

    it = v.begin();

    cout << "Iterator traversal: ";

    while (it != v.end())
    {
        cout << *it << " ";

        ++it;
    }

    /*
    Last valid element:
    v.end() - 1
    */

    cout << endl
         << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    vector<int> v = {10, 20, 30, 40, 50};

    vector<int>::iterator it;

    it = v.begin();

    cout << "First value: " << *it << endl;

    ++it;

    cout << "Second value: " << *it << endl;

    it = it + 2;

    cout << "Fourth value: " << *it << endl;

    /*
    Random access iterator:
    ++it -> supported
    --it -> supported
    it+2 -> supported
    it-2 -> supported
    */

    cout << endl;
}

// ================= UPDATE FUNCTION =================

void updateDemo()
{
    cout << "================ UPDATE =================\n"
         << endl;

    vector<int> v = {10, 99, 20, 30, 40, 50};

    // update using index

    v[1] = 500;

    cout << "After update: ";

    display(v);

    /*
    Output:
    10 500 20 30 40 50
    */

    cout << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    vector<int> v = {10, 500, 20, 30, 40, 50};

    // pop_back()

    v.pop_back();

    cout << "After pop_back(): ";

    display(v);

    /*
    Output:
    10 500 20 30 40
    */

    cout << endl;

    // erase()

    v.erase(v.begin() + 2);

    cout << "After erase(): ";

    display(v);

    /*
    Output:
    10 500 30 40
    */

    cout << endl;

    // clear()

    v.clear();

    cout << "Size after clear(): " << v.size() << endl;

    /*
    Output:
    0
    */

    cout << "v.empty(): " << v.empty() << endl;

    /*
    Output:
    1
    */

    cout << endl;
}

// ================= 2D VECTOR FUNCTION =================

void twoDVectorDemo()
{
    cout << "================ 2D VECTOR =================\n"
         << endl;

    vector<vector<int>> matrix =
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    int i, j;

    for (i = 0; i < matrix.size(); i++)
    {
        for (j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    /*
    Output:
    1 2 3
    4 5 6
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

    twoDVectorDemo();

    return 0;
}