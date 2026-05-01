/*
==================== IMPORTANT POINTS ====================

1. friend class:
   - declared using: friend class B;
   - all functions of B can access private members of A
   - can be declared with any access specifier
   
2. access:
   - normally private members are hidden
   - friend class can directly access them

3. direction:
   - A → gives access to B
   - NOT mutual (B cannot give access back automatically)

=========================================================
*/
#include <iostream>
using namespace std;

// purpose: demonstrate friend class with clear understanding

// CLASS A (GIVES ACCESS)
class A
{
private:
    int secret;   // private data (normally hidden)
    friend class B;   // ✔ B can access private members of A
public:
    A(int val)
    {
        secret = val;
    }

    // friend class declaration
    
};


// CLASS B (FRIEND CLASS)
class B
{
public:
    void showSecret(A obj)
    {
        // ✔ accessing private member of A
        cout << "Accessing A's private data: " << obj.secret << endl;
    }
};


int main()
{
    A a(100);   // object of class A
    B b;        // object of class B

    b.showSecret(a);   // ✔ works because B is friend of A

    return 0;
}


/*
==================== OUTPUT ====================

Accessing A's private data: 100

================================================



*/