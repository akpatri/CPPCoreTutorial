/*
overriding: dynamic polymerphism or dynamic binding
Functions → can be virtual → runtime polymorphism
Variables → NEVER virtual → always compile-time (static binding)
Memory Rule:
1. virtual + same signature(same name, same return, same parameter list) -> Derived called
2. virtual + different signature -> Base called (hiding)
3. non-virtual + same signature -> Base called via base pointer
4. non-virtual + different signature -> Base called via base pointer
Virtual function:
1. cant be static or friend
2. class can have virtual destrucor but cant have virtual constructor
in case of polymerphism if parent class pointer have child class object, then virtual destructor of parent is compulsory, else only parent destrucot will be called
*/

#include <iostream>
using namespace std;

// == CASE 1 : virtual + same signature (REAL OVERRIDING) ==
class Base1
{
public:
    virtual void show() 
    {
        cout << "Base1 show()" << endl;
    }
};

class Derived1 : public Base1
{
public:
    void show() //an over-riden method is virtual by default
    {
        cout << "Derived1 show()" << endl;
    }
};


// == CASE 2 : virtual + different signature (FUNCTION HIDING) ==
class Base2
{
public:
    virtual void show()
    {
        cout << "Base2 show()" << endl;
    }
};

class Derived2 : public Base2
{
public:
    void show(int x)
    {
        cout << "Derived2 show(int): " << x << endl;
    }
};


// == CASE 3 : non-virtual + same signature ==
class Base3
{
public:
    void show()
    {
        cout << "Base3 show()" << endl;
    }
};

class Derived3 : public Base3
{
public:
    void show()
    {
        cout << "Derived3 show()" << endl;
    }
};


// == CASE 4 : non-virtual + different signature ==
class Base4
{
public:
    void show()
    {
        cout << "Base4 show()" << endl;
    }
};

class Derived4 : public Base4
{
public:
    void show(int x)
    {
        cout << "Derived4 show(int): " << x << endl;
    }
};


int main()
{
    // CASE 1 (overriding):(virtual + same signature): runtime polymorphism happens : derived version runs
    Base1 *b1 = new Derived1();
    cout << "CASE 1: ";
    b1->show();   // Derived1 show()


    // CASE 2 (hiding):(virtual + different signature): no overriding: base version runs
    Base2 *b2 = new Derived2();
    cout << "CASE 2: ";
    b2->show();   // Base2 show()

    Derived2 d2;
    d2.show(10);  // Derived2 show(int)


    
    // CASE 3 (non-virtual + same signature): compile-time binding: pointer type decides
    Base3 *b3 = new Derived3();

    cout << "CASE 3: ";
    b3->show();   // Base3 show()


    // CASE 4 (non-virtual + different signature): completely separate functions
    Base4 *b4 = new Derived4();

    cout << "CASE 4: ";
    b4->show();   // Base4 show()

    Derived4 d4;
    d4.show(20);


    return 0;
}

