/*
==================== SIMPLE UNDERSTANDING ====================

1. friend member function:
   - a function of another class is given access of private field

2. syntax:
   class A {
       friend void B::function(A obj);
   };

3. steps:
   - forward declare class B
   - declare function inside B
   - make it friend inside A
   - define function outside

4. important:
   - only that function gets access (not whole class)

==============================================================
*/

#include <iostream>
using namespace std;

// purpose: simple demonstration of friend MEMBER function



// FORWARD DECLARATION (required)
class A;

// CLASS B (contains the member function)
class B
{
public:
    void show(A obj);   // declaration: you cant access obj.x here , as friendship not extablished yet
};



// CLASS A (gives access)
class A
{
private:
    int x;

public:
    A(int val)
    {
        x = val;
    }

    // friend member function of class B
    friend void B::show(A obj);   // ✔ only this function gets access: can be declared with any access specifier
};


// DEFINITION OF FRIEND MEMBER FUNCTION
void B::show(A obj)
{
    // ✔ accessing private member of A
    cout << "Value of x = " << obj.x << endl;
}


int main()
{
    A a(50);
    B b;

    b.show(a);   // ✔ calling member function

    return 0;
}


// output: Value of x = 50