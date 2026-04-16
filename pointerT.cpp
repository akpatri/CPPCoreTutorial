#include <iostream>
using namespace std;

// ============================================================
// 🔷 POINTER BASICS
// → pointer stores address of a variable
// → '*' → declaration + dereference (indirection)
// → '&' → address-of operator
// ============================================================

int main()
{
    int a = 10;

    int* p = &a;                 // single pointer → stores address of 'a'

    cout << p << endl;           // prints address
    cout << *p << endl;          // indirection → value at address (10)

    *p = 20;                     // modify value using pointer
    cout << a << endl;           // a becomes 20

    // ========================================================
    // 🔷 MULTI-LEVEL POINTER (POINTER TO POINTER)
    // ========================================================

    int** pp = &p;               // pointer to pointer

    cout << pp << endl;          // address of pointer p
    cout << *pp << endl;         // value of p (address of a)
    cout << **pp << endl;        // value of a (20)

    **pp = 30;                   // modify a through double indirection
    cout << a << endl;           // a becomes 30

    // ========================================================
    // 🔷 ARRAY BASICS
    // → array name acts like pointer to first element
    // ========================================================

    int arr[3] = {1, 2, 3};

    cout << arr << endl;         // address of first element
    cout << *arr << endl;        // arr[0]

    // pointer arithmetic
    cout << *(arr + 1) << endl;  // arr[1]
    cout << *(arr + 2) << endl;  // arr[2]

    // ========================================================
    // 🔷 POINTER WITH ARRAY
    // ========================================================

    int* pArr = arr;             // points to first element

    cout << *pArr << endl;       // 1
    cout << *(pArr + 1) << endl; // 2

    // ========================================================
    // 🔷 ARRAY OF POINTERS
    // ========================================================

    int x = 100, y = 200, z = 300;

    int* ptrArr[3] = { &x, &y, &z };   // array of pointers

    cout << *ptrArr[0] << endl;        // 100
    cout << *ptrArr[1] << endl;        // 200
    cout << *ptrArr[2] << endl;        // 300

    // ========================================================
    // 🔷 POINTER TO ARRAY
    // ========================================================

    int (*ptrToArr)[3] = &arr;         // pointer to whole array

    cout << (*ptrToArr)[0] << endl;    // arr[0]
    cout << (*ptrToArr)[1] << endl;    // arr[1]

    // ========================================================
    // 🔷 MULTI-DIMENSIONAL ARRAY
    // ========================================================

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << matrix[0][1] << endl;      // 2

    // pointer form access
    cout << *(*(matrix + 1) + 2) << endl; // 6

    // ========================================================
    // 🔷 POINTER TO MULTI-DIMENSIONAL ARRAY
    // ========================================================

    int (*pMat)[3] = matrix;           // points to row (array of 3 ints)

    cout << pMat[0][0] << endl;        // 1
    cout << pMat[1][2] << endl;        // 6

    // ========================================================
    // 🔷 DOUBLE POINTER WITH ARRAY (SIMULATION)
    // ========================================================

    int* rows[2];

    rows[0] = matrix[0];               // first row
    rows[1] = matrix[1];               // second row

    cout << rows[1][1] << endl;        // 5 (like matrix[1][1])

    // ========================================================
    // 🔷 IMPORTANT NOTES
    // ========================================================

    // arr == &arr[0]           → true (address of first element)
    // *(arr + i) == arr[i]     → same
    // pointer arithmetic moves by size of datatype

    return 0;
}