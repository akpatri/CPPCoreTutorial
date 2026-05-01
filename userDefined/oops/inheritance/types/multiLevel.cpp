/*
Can access parent versions using:
   Child1::show() //accessing child1's show from its child
   Base::show() //accessing Base's show from its child
constructor order:
   Base → Child1 → Child2
destructor order:
   Child2 → Child1 → Base
*/
#include <iostream>
using namespace std;
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

    virtual void show()
    {
        cout << "Base::show() -> x = " << x << endl;
    }

    ~Base()
    {
        cout << "Base destructor\n";
    }
};

// CHILD1
class Child1 : public Base
{
public:
    int y;

    Child1(int a, int b) : Base(a)
    {
        y = b;
        cout << "Child1 constructor\n";
    }

    void show() override //overriden method virtual by default
    {
        cout << "Child1::show() -> y = " << y << endl;
    }

    ~Child1()
    {
        cout << "Child1 destructor\n";
    }
};

// CHILD2
class Child2 : public Child1
{
public:
    int z;

    Child2(int a, int b, int c) : Child1(a, b)
    {
        z = c;
        cout << "Child2 constructor\n";
    }

    void show() override
    {
        cout << "Child2::show() -> z = " << z << endl;
    }

    void demo()
    {
        cout << "\nCalling all versions:\n";

        show();          // Child2
        Child1::show();  // Child1
        Base::show();    // Base
    }

    ~Child2()
    {
        cout << "Child2 destructor\n";
    }
};

// MAIN
int main()
{
    Child2 obj(10, 20, 30);   // only one object

    cout << "\nDirect call:\n";
    obj.show();   // Child2
    obj.demo();   // access all versions

    cout << "\nEnd of program\n";

    return 0;
}


/*
OUTPUT:

Base constructor
Child1 constructor
Child2 constructor

Direct call:
Child2::show() -> z = 30

Calling all versions:
Child2::show() -> z = 30
Child1::show() -> y = 20
Base::show() -> x = 10

End of program
Child2 destructor
Child1 destructor
Base destructor

*/


