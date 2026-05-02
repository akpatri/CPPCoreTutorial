/*
STL array stores fixed-size elements of same data type

Header file:
#include <array>

Syntax:
array<data_type, size> array_name;

Example:
array<int, 5> arr;
*/

#include <iostream>
#include <array>
using namespace std;

int main()
{
    // ================= CREATE =================

    array<int, 5> arr = {10, 20, 30, 40, 50}; // create array with values

    array<int, 5> arr2; // empty array

    arr2.fill(100); // fill() inserts same value in all positions

    cout << "arr2 elements: ";

    for(int x : arr2)
    {
        cout << x << " ";
    }

    // Output: 100 100 100 100 100

    cout << endl << endl;



    // ================= READ =================

    cout << "arr elements: ";

    for(int i = 0; i < arr.size(); i++) // size() returns total elements
    {
        cout << arr[i] << " "; // [] accesses element using index
    }

    // Output: 10 20 30 40 50

    cout << endl << endl;

    cout << "arr[0]: " << arr[0] << endl; // [] accesses element using index
    // Output: arr[0]: 10

    cout << "arr.at(2): " << arr.at(2) << endl; // at() safely accesses element
    // Output: arr.at(2): 30

    cout << "arr.front(): " << arr.front() << endl; // front() returns first element
    // Output: arr.front(): 10

    cout << "arr.back(): " << arr.back() << endl; // back() returns last element
    // Output: arr.back(): 50

    cout << "arr.size(): " << arr.size() << endl; // size() returns total size
    // Output: arr.size(): 5

    cout << "arr.empty(): " << arr.empty() << endl; // empty() checks array is empty or not
    // Output: arr.empty(): 0

    cout << "Address: " << arr.data() << endl; // data() returns address of first element
    // Output: memory address like 0x61ff00

    cout << endl;



    // ================= UPDATE =================

    arr[1] = 500; // update value using index

    cout << "After update: ";

    for(int x : arr)
    {
        cout << x << " ";
    }

    // Output: 10 500 30 40 50

    cout << endl << endl;


    // swap() exchanges data of arrays

    array<int, 3> a = {1, 2, 3};

    array<int, 3> b = {10, 20, 30};

    a.swap(b);

    cout << "Array a after swap: ";

    for(int x : a)
    {
        cout << x << " ";
    }

    // Output: 10 20 30

    cout << endl;

    cout << "Array b after swap: ";

    for(int x : b)
    {
        cout << x << " ";
    }

    // Output: 1 2 3

    cout << endl << endl;



    // ================= DELETE =================

    // STL array size is fixed
    // Elements cannot be deleted like vector

    // We can overwrite value instead

    arr[2] = 0; // replace element with 0

    cout << "After replacing value: ";

    for(int x : arr)
    {
        cout << x << " ";
    }

    // Output: 10 500 0 40 50

    cout << endl << endl;



    // ================= COMPARE =================

    array<int, 3> x = {1, 2, 3};

    array<int, 3> y = {1, 2, 3};

    if(x == y) // compare arrays using ==
    {
        cout << "Arrays are equal" << endl;
    }

    // Output: Arrays are equal

    cout << endl;



    // ================= 2D ARRAY =================

    array<array<int, 3>, 2> matrix = {{{1,2,3}, {4,5,6}}}; // 2D array

    cout << "2D array:" << endl;

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
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

    return 0;
}