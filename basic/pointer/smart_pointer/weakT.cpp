/*
========================================================
                    WEAK POINTER IN C++
========================================================

Definition:
- weak_ptr is a smart pointer
- It observes shared_ptr object
- Does NOT own object
- Does NOT increase reference count

Header File:
    #include <memory>

Syntax:
    weak_ptr<data_type> ptr_name;

Example:
    weak_ptr<int> ptr;

========================================================
                    IMPORTANT POINTS
========================================================

1. Non-owning smart pointer
2. Works with shared_ptr
3. Does NOT increase reference count
4. Used to avoid cyclic dependency
5. Cannot directly access object
6. Use lock() to access object
7. Object deleted when all shared_ptr destroyed

========================================================
                    MAIN FUNCTIONS
========================================================

lock()         -> converts weak_ptr to shared_ptr
expired()      -> checks object exists or not
reset()        -> removes observation
use_count()    -> returns shared owners count
owner_before() -> compares ownership order

========================================================
*/

#include <iostream>
#include <memory> // for smart pointers

using namespace std;

class Test
{
public:

    Test()
    {
        cout << "Constructor called" << endl;
    }

    ~Test()
    {
        cout << "Destructor called" << endl;
    }

    void show()
    {
        cout << "Inside show()" << endl;
    }
};


// ================= BASIC WEAK_PTR FUNCTION =================

void weakPointerDemo()
{
    cout << "\n================ WEAK_PTR ================\n";


    // ============================================================
    // create shared_ptr
    // ============================================================

    shared_ptr<Test> sp = make_shared<Test>(); // create shared object

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl; // count = 1


    // ============================================================
    // create weak_ptr
    // ============================================================

    weak_ptr<Test> wp = sp; // weak_ptr observes shared_ptr

    // weak_ptr does NOT increase reference count

    cout << "\nAfter weak_ptr creation" << endl;

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl; // still count = 1


    // ============================================================
    // expired()
    // ============================================================

    cout << "\nwp.expired(): ";

    cout << wp.expired() << endl; // 0 means object exists


    // ============================================================
    // lock()
    // ============================================================

    // weak_ptr cannot directly access object

    // convert weak_ptr -> shared_ptr

    shared_ptr<Test> temp = wp.lock();

    // lock() temporarily increases reference count

    cout << "\nAfter lock()" << endl;

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl; // count becomes 2

    if (temp != nullptr) // check object exists
    {
        temp->show();
    }


    // ============================================================
    // reset()
    // ============================================================

    wp.reset(); // weak_ptr stops observing object

    cout << "\nAfter wp.reset()" << endl;

    cout << "wp.expired(): ";

    cout << wp.expired() << endl; // weak_ptr now empty


    // ============================================================
    // owner_before()
    // ============================================================

    shared_ptr<Test> sp2 = make_shared<Test>(); // second object

    weak_ptr<Test> wp2 = sp2; // second weak_ptr

    cout << "\nowner_before(): ";

    cout << wp.owner_before(wp2) << endl;

    // compares ownership order internally


    // ============================================================
    // object destruction
    // ============================================================

    sp.reset(); // remove shared ownership

    cout << "\nAfter sp.reset()" << endl;

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl; // count = 0

    cout << "wp.expired(): ";

    cout << wp.expired() << endl; // object expired
}


// ================= CYCLIC DEPENDENCY PROBLEM =================

class B; // forward declaration

class A
{
public:

    shared_ptr<B> ptrB; // A owns B

    ~A()
    {
        cout << "A Destructor called" << endl;
    }
};

class B
{
public:

    shared_ptr<A> ptrA; // B owns A

    ~B()
    {
        cout << "B Destructor called" << endl;
    }
};


// ================= CYCLIC DEPENDENCY FUNCTION =================

void cyclicProblemDemo()
{
    cout << "\n================ CYCLIC DEPENDENCY PROBLEM ================\n";

    shared_ptr<A> a = make_shared<A>();

    shared_ptr<B> b = make_shared<B>();

    a->ptrB = b; // A points to B

    b->ptrA = a; // B points to A

    cout << "a use_count(): ";

    cout << a.use_count() << endl;

    cout << "b use_count(): ";

    cout << b.use_count() << endl;

    // destructors will NOT be called properly

    // because both objects keep each other alive

    // memory leak occurs
}


// ================= SOLUTION USING WEAK_PTR =================

class D; // forward declaration

class C
{
public:

    shared_ptr<D> ptrD; // C owns D

    ~C()
    {
        cout << "C Destructor called" << endl;
    }
};

class D
{
public:

    weak_ptr<C> ptrC; // weak_ptr prevents cycle

    ~D()
    {
        cout << "D Destructor called" << endl;
    }
};


// ================= CYCLIC DEPENDENCY SOLUTION FUNCTION =================

void cyclicSolutionDemo()
{
    cout << "\n================ CYCLIC DEPENDENCY SOLUTION ================\n";

    shared_ptr<C> c = make_shared<C>();

    shared_ptr<D> d = make_shared<D>();

    c->ptrD = d; // C owns D

    d->ptrC = c; // weak_ptr observes C

    cout << "c use_count(): ";

    cout << c.use_count() << endl;

    // count remains safe

    // weak_ptr does NOT increase count

    cout << "d use_count(): ";

    cout << d.use_count() << endl;

    // destructors automatically called correctly

    // no memory leak
}


// ================= MAIN FUNCTION =================

int main()
{
    weakPointerDemo();

    cyclicProblemDemo();

    cyclicSolutionDemo();

    return 0;
}