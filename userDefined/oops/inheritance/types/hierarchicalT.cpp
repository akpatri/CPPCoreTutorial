/*
==================== IMPORTANT POINTS ====================

1. hierarchical inheritance:
   Base → Child1
        → Child2

2. one base class is shared by multiple child classes

3. each child has:
   - its own members
   - access to base class members

4. objects are separate:
   - each child has its own Base part

5. constructor order:
   Base → Child

6. destructor order:
   Child → Base

=========================================================
*/
#include <iostream>
using namespace std;

// purpose: demonstrate hierarchical inheritance (one base class → multiple child classes)

// BASE CLASS
class Base
{
public:
    int x;

    Base(int val)
    {
        x = val;
        cout << "Base constructor\n";
    }

    void show()
    {
        cout << "Base::show() -> x = " << x << endl;
    }

    ~Base()
    {
        cout << "Base destructor\n";
    }
};


// CHILD1 (DERIVED FROM BASE)
class Child1 : public Base
{
public:
    int y;

    Child1(int a, int b) : Base(a)
    {
        y = b;
        cout << "Child1 constructor\n";
    }

    void display()
    {
        cout << "Child1::display() -> y = " << y << endl;
    }

    ~Child1()
    {
        cout << "Child1 destructor\n";
    }
};


// CHILD2 (DERIVED FROM BASE)
class Child2 : public Base
{
public:
    int z;

    Child2(int a, int c) : Base(a)
    {
        z = c;
        cout << "Child2 constructor\n";
    }

    void print()
    {
        cout << "Child2::print() -> z = " << z << endl;
    }

    ~Child2()
    {
        cout << "Child2 destructor\n";
    }
};


int main()
{
    cout << "---- Child1 Object ----\n";
    Child1 c1(10, 20);

    c1.show();     // ✔ Base method
    c1.display();  // ✔ Child1 method

    cout << "\n---- Child2 Object ----\n";
    Child2 c2(30, 40);

    c2.show();     // ✔ Base method
    c2.print();    // ✔ Child2 method

    cout << "\nEnd of program\n";

    return 0;
}


/*
==================== OUTPUT ====================

---- Child1 Object ----
Base constructor
Child1 constructor
Base::show() -> x = 10
Child1::display() -> y = 20

---- Child2 Object ----
Base constructor
Child2 constructor
Base::show() -> x = 30
Child2::print() -> z = 40

End of program
Child2 destructor
Base destructor
Child1 destructor
Base destructor

================================================
*/