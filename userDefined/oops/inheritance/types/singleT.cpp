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
    }

    // virtual function → enables runtime polymorphism
    virtual void show()
    {
        cout << "Base::show() -> x = " << x << endl;
    }
};

// CHILD CLASS
class Child : public Base
{
public:
    Child(int val) : Base(val) {}

    // override keyword (recommended for safety)
    void show() override
    {
        cout << "Child::show() -> x = " << x << endl;
    }

    void accessBase()
    {
        show(); // ✔ Child::show() if child have this function // calling child version
        Base::show(); // ✔ Base::show()  //explicitly calling base version
    }
};

// ==================================================
// MAIN FUNCTION
// ==================================================
int main()
{
    Child c(100);
    c.show(); // ✔ Child::show()
    cout << endl;

    // -- RUNTIME POLYMORPHISM --
    Base *b = new Child(200);
    b->show(); // ✔ Child::show() (because virtual)
    cout << endl;
    c.accessBase();
    delete b;

    return 0;
}
