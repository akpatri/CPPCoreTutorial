/*
==================== SIMPLE UNDERSTANDING ====================

1. friend non-member function:
   - normal function (not part of class)
   - declared inside class using 'friend'

2. syntax:
   class A {
       friend void function(A obj);
   };

3. key points:
   - defined outside class
   - called like: function(obj)
   - can access private + protected members

4. important:
   - NOT a member function
   - no this pointer
   - ignores access specifier (public/private doesn't matter)

==============================================================
*/

#include <iostream>
using namespace std;

// purpose: simple demonstration of friend NON-MEMBER function

// CLASS A (gives access)
class A
{
private:
    int x;   // private data

public:
    A(int val)
    {
        x = val;
    }

    // friend non-member function: any function who matches this declaration become its friend 
    friend void show(A obj);   // ✔ gives access to private members
};


// FRIEND FUNCTION DEFINITION (OUTSIDE CLASS)
void show(A obj)
{
    // ✔ accessing private member of A
    cout << "Value of x = " << obj.x << endl;
}


int main()
{
    A a(25);
    show(a);   // ✔ called like normal function (NOT using object)
    return 0;
}

// Output: Value of x = 25
