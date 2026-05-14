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
    int a = 10; // variable with value

    int *p = &a; // single pointer → stores address of 'a'

    cout << p << endl;  // prints address
    cout << *p << endl; // indirection → value at address (10)

    *p = 20;           // modify value using pointer
    cout << a << endl; // a becomes 20

    // 🔷 MULTI-LEVEL POINTER (POINTER TO POINTER)
    int **pp = &p; // pointer to pointer

    cout << pp << endl;   // address of pointer p
    cout << *pp << endl;  // value of p (address of a)
    cout << **pp << endl; // value of a (20)

    **pp = 30;         // modify a through double indirection
    cout << a << endl; // a becomes 30

    // 🔷 VOID POINTER (GENERIC POINTER) → can store address of any type → must typecast before dereferencing
    int x = 100;
    void *vp = &x; // generic pointer
    cout << *(int *)vp << endl; // typecast to int* before use
    return 0;
}