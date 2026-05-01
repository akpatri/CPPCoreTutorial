#include <iostream>
using namespace std;

// 🔷 BASE CLASS
class Base
{
public:
    int pub = 1;

protected:
    int prot = 2;

private:
    int priv = 3;

public:
    Base() { cout << "Base Constructor\n"; }
    virtual ~Base() { cout << "Base Destructor\n"; }

    virtual void show() // virtual → enables runtime polymorphism
    {
        cout << "Base show()\n";
    }
};

// ============================================================
// 🔷 SINGLE INHERITANCE (PUBLIC)
// ============================================================

class DerivedPublic : public Base
{
public:
    DerivedPublic() { cout << "DerivedPublic Constructor\n"; }
    ~DerivedPublic() { cout << "DerivedPublic Destructor\n"; }

    void access()
    {
        cout << pub << endl;  // ✔ remains public
        cout << prot << endl; // ✔ remains protected
        // cout << priv;       // ❌ not accessible
    }

    void show() override // overriding (dynamic polymorphism)
    {
        cout << "DerivedPublic show()\n";
    }
};



// ============================================================
// 🔷 MULTILEVEL INHERITANCE
// ============================================================

class Level1
{
public:
    Level1() { cout << "Level1 Constructor\n"; }
    ~Level1() { cout << "Level1 Destructor\n"; }
};

class Level2 : public Level1
{
public:
    Level2() { cout << "Level2 Constructor\n"; }
    ~Level2() { cout << "Level2 Destructor\n"; }
};

class Level3 : public Level2
{
public:
    Level3() { cout << "Level3 Constructor\n"; }
    ~Level3() { cout << "Level3 Destructor\n"; }
};

// ============================================================
// 🔷 MULTIPLE INHERITANCE
// ============================================================

class A
{
public:
    void show() { cout << "A show\n"; }
};

class B
{
public:
    void show() { cout << "B show\n"; }
};

// ============================================================
// 🔷 AMBIGUITY PROBLEM
// ============================================================

class C : public A, public B
{
public:
    void test()
    {
        // show();            // ❌ ambiguous → which show()?
        A::show(); // ✔ resolved using scope resolution
        B::show();
    }
};

// ============================================================
// 🔷 VIRTUAL INHERITANCE (DIAMOND PROBLEM SOLUTION)
// ============================================================

class VBase
{
public:
    int x;
};

class V1 : virtual public VBase
{
};
class V2 : virtual public VBase
{
};

class VDerived : public V1, public V2
{
public:
    void set()
    {
        x = 10; // only one copy due to virtual inheritance
    }
};

// ============================================================
// 🔷 MAIN
// ============================================================

int main()
{
    // ========================================================
    // 🔷 SINGLE INHERITANCE + POLYMORPHISM
    // ========================================================

    Base *ptr;
    DerivedPublic d;

    ptr = &d;
    ptr->show(); // runtime polymorphism → calls DerivedPublic::show()

    // ========================================================
    // 🔷 MULTILEVEL INHERITANCE (CALL SEQUENCE)
    // → constructors: Base → Derived
    // → destructors: reverse order
    // ========================================================

    Level3 obj;

    // ========================================================
    // 🔷 MULTIPLE INHERITANCE + AMBIGUITY
    // ========================================================

    C c;
    c.test();

    // ========================================================
    // 🔷 VIRTUAL INHERITANCE
    // ========================================================

    VDerived vd;
    vd.set();

    // ========================================================
    // 🔷 DESTRUCTOR CALL WITH BASE POINTER
    // → virtual destructor ensures proper cleanup
    // ========================================================

    Base *p = new DerivedPublic();
    delete p; // calls DerivedPublic then Base destructor

    return 0;
}