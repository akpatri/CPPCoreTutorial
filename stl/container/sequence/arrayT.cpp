/*
========================================================
                  STL ARRAY IN C++
========================================================

Definition:
- STL array stores fixed-size elements of same data type
- Size cannot change after creation

Header File:
    #include <array>

Syntax:
    array<data_type, size> array_name;

Example:
    array<int, 5> arr;

Internal Working:
- Stored in contiguous memory locations
- Fixed-size container

Important Points:
1. Stores same data type elements
2. Size is fixed at compile time
3. Faster access using index
4. Supports iterators
5. [] does NOT check bounds
6. at() safely checks bounds
7. front() returns first element
8. back() returns last element
9. data() returns address of first element

Difference:
- []   -> may return garbage value for invalid index
- at() -> throws out_of_range exception

Main Functions:
1. fill()   -> fill entire array with same value
2. at()     -> safe element access
3. front()  -> first element
4. back()   -> last element
5. size()   -> total elements
6. empty()  -> checks array empty or not
7. data()   -> address of first element
8. swap()   -> swap two arrays

Iterator Support:
- Random access iterator supported
- ++it   -> supported
- --it   -> supported
- it+2   -> supported
- it-2   -> supported

Time Complexity:
- Access      -> O(1)
- Update      -> O(1)
- Traversal   -> O(n)
- swap()      -> O(n)

2D Array Syntax:
    array<array<int, col>, row> matrix;

Example:
    array<array<int, 3>, 2> matrix;

========================================================
*/

#include <iostream>
#include <array>
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(array<int, 5> arr)
{
    array<int, 5>::iterator it;

    for (it = arr.begin(); it != arr.end(); ++it)
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

    // initializer list

    array<int, 5> arr = {10, 20, 30, 40, 50};

    // uniform initialization

    array<int, 5> arr3{10, 20, 30, 40, 50};

    // empty array

    array<int, 5> arr2;

    // fill()

    arr2.fill(100);

    cout << "arr2 elements: ";

    display(arr2);

    /*
    Output:
    100 100 100 100 100
    */

    cout << endl;
}

// ================= READ FUNCTION =================

void readDemo()
{
    cout << "================ READ =================\n"
         << endl;

    array<int, 5> arr = {10, 20, 30, 40, 50};

    cout << "arr elements: ";

    int i;

    for (i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    /*
    Output:
    10 20 30 40 50
    */

    cout << endl
         << endl;

    // []

    cout << "arr[0]: " << arr[0] << endl;

    // at()

    cout << "arr.at(2): " << arr.at(2) << endl;

    // front()

    cout << "arr.front(): " << arr.front() << endl;

    // back()

    cout << "arr.back(): " << arr.back() << endl;

    // size()

    cout << "arr.size(): " << arr.size() << endl;

    // empty()

    cout << "arr.empty(): " << arr.empty() << endl;

    // data()

    cout << "Address: " << arr.data() << endl;

    cout << endl;
}

// ================= ITERATOR FUNCTION =================

void iteratorDemo()
{
    cout << "================ ITERATOR =================\n"
         << endl;

    array<int, 5> arr = {10, 20, 30, 40, 50};

    array<int, 5>::iterator it;

    it = arr.begin();

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

    array<int, 5> arr = {10, 20, 30, 40, 50};

    // update using index

    arr[1] = 500;

    cout << "After update: ";

    display(arr);

    /*
    Output:
    10 500 30 40 50
    */

    cout << endl;

    // swap()

    array<int, 3> a = {1, 2, 3};

    array<int, 3> b = {10, 20, 30};

    a.swap(b);

    cout << "Array a after swap: ";

    array<int, 3>::iterator it1;

    for (it1 = a.begin(); it1 != a.end(); ++it1)
    {
        cout << *it1 << " ";
    }

    /*
    Output:
    10 20 30
    */

    cout << endl;

    cout << "Array b after swap: ";

    array<int, 3>::iterator it2;

    for (it2 = b.begin(); it2 != b.end(); ++it2)
    {
        cout << *it2 << " ";
    }

    /*
    Output:
    1 2 3
    */

    cout << endl
         << endl;
}

// ================= DELETE FUNCTION =================

void deleteDemo()
{
    cout << "================ DELETE =================\n"
         << endl;

    array<int, 5> arr = {10, 500, 30, 40, 50};

    // STL array size is fixed

    // overwrite value instead of delete

    arr[2] = 0;

    cout << "After replacing value: ";

    display(arr);

    /*
    Output:
    10 500 0 40 50
    */

    cout << endl;
}

// ================= COMPARE FUNCTION =================

void compareDemo()
{
    cout << "================ COMPARE =================\n"
         << endl;

    array<int, 3> x = {1, 2, 3};

    array<int, 3> y = {1, 2, 3};

    if (x == y)
    {
        cout << "Arrays are equal" << endl;
    }

    /*
    Output:
    Arrays are equal
    */

    cout << endl;
}

// ================= 2D ARRAY FUNCTION =================

void twoDArrayDemo()
{
    cout << "================ 2D ARRAY =================\n"
         << endl;

    array<array<int, 3>, 2> matrix =
        {{{1, 2, 3},
          {4, 5, 6}}};

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

    compareDemo();

    twoDArrayDemo();

    return 0;
}