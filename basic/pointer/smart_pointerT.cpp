/*

========================= SMART POINTER =========================

Smart Pointer:
---------------
Smart pointers are special C++ objects that automatically manage memory.

Problem with raw pointers:
--------------------------
1. Memory leak
2. Dangling pointer
3. Double delete
4. Manual memory management is difficult
Smart pointers solve these problems automatically.

========================= RAII =========================

RAII = Resource Acquisition Is Initialization

Meaning:
---------
Resource (memory/file/socket/etc) is acquired inside object constructor
and automatically released inside destructor.

Example:
--------
Object created  -> memory acquired
Object destroyed -> memory released automatically

Smart pointers follow RAII principle.


========================= TYPES OF SMART POINTER =========================

1. unique_ptr
--------------
- Exclusive ownership
- Only ONE pointer owns object
- Cannot copy
- Can move ownership

Syntax: unique_ptr<int> p = make_unique<int>(10);
--------

2. shared_ptr
--------------
- Shared ownership
- Multiple pointers can own same object
- Uses reference counting

Syntax:
--------
shared_ptr<int> p = make_shared<int>(10);


3. weak_ptr
------------
- Non-owning observer
- Observes shared_ptr object
- Does not increase reference count
- Prevents cyclic dependency

Syntax:
--------
weak_ptr<int> wp = sp;

*/

#include <iostream>
#include <memory> // required for smart pointers
using namespace std;

// ============================================================
// CLASS
// ============================================================

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

// ============================================================
// UNIQUE_PTR
// ============================================================

void uniquePointerDemo()
{
    cout << "\n================ UNIQUE_PTR ================\n";

    // unique_ptr provides exclusive ownership

    // only ONE unique_ptr can own object at a time

    // ============================================================
    // make_unique()
    // ============================================================

    // recommended way to create unique_ptr

    unique_ptr<Test> ptr1 = make_unique<Test>();

    // operator-> used to access member function

    ptr1->show();

    // operator* dereferences object

    (*ptr1).show();

    // ============================================================
    // get()
    // ============================================================

    // get() returns raw pointer

    Test *raw = ptr1.get();

    cout << "\nRaw pointer address: " << raw << endl;

    // raw pointer should NOT be manually deleted

    // because unique_ptr still owns object

    // ============================================================
    // COPY NOT ALLOWED
    // ============================================================

    // unique_ptr cannot be copied

    // because ownership must remain unique

    // unique_ptr<Test> ptr2 = ptr1; // ERROR

    // ============================================================
    // move()
    // ============================================================

    // transfer ownership using move()

    unique_ptr<Test> ptr2 = move(ptr1);

    // ptr1 becomes nullptr after move

    if (ptr1 == nullptr)
    {
        cout << "ptr1 is now empty" << endl;
    }

    // ptr2 now owns object

    ptr2->show();

    // ============================================================
    // release()
    // ============================================================

    // release() releases ownership

    // returns raw pointer

    // unique_ptr becomes empty

    Test *raw2 = ptr2.release();

    cout << "\nAfter release()" << endl;

    if (ptr2 == nullptr)
    {
        cout << "ptr2 is empty" << endl;
    }

    // now manual delete is required

    delete raw2;

    // ============================================================
    // reset()
    // ============================================================

    // reset() deletes old object
    // and optionally assigns new object

    unique_ptr<Test> ptr3 = make_unique<Test>();

    ptr3.reset(new Test());

    cout << "\nAfter reset()" << endl;

    ptr3->show();

    // old object automatically deleted

    // reset() with no argument deletes object

    ptr3.reset();

    if (ptr3 == nullptr)
    {
        cout << "ptr3 is empty after reset()" << endl;
    }

    // ============================================================
    // swap()
    // ============================================================

    unique_ptr<Test> a = make_unique<Test>();

    unique_ptr<Test> b = make_unique<Test>();

    cout << "\nBefore swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;

    // swap ownership

    a.swap(b);

    cout << "\nAfter swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;

    // ============================================================
    // AUTOMATIC CLEANUP
    // ============================================================

    // all remaining objects automatically deleted
    // when function ends
}

// ============================================================
// SHARED_PTR
// ============================================================

void sharedPointerDemo()
{
    cout << "\n================ SHARED_PTR ================\n";

    // shared_ptr provides shared ownership

    // multiple shared_ptr can own same object

    // object deleted automatically
    // when reference count becomes 0

    // ============================================================
    // make_shared()
    // ============================================================

    // recommended way to create shared_ptr

    shared_ptr<Test> sp1 = make_shared<Test>();

    // operator-> used to access member function

    sp1->show();

    // operator* dereferences object

    (*sp1).show();

    // ============================================================
    // use_count()
    // ============================================================

    // use_count() returns total owners

    cout << "\nsp1 use_count(): ";

    cout << sp1.use_count() << endl;

    // Output: 1

    // ============================================================
    // SHARED OWNERSHIP
    // ============================================================

    // copy allowed in shared_ptr

    shared_ptr<Test> sp2 = sp1;

    // now both pointers own same object

    cout << "\nAfter copy" << endl;

    cout << "sp1 use_count(): ";

    cout << sp1.use_count() << endl;

    // Output: 2

    cout << "sp2 use_count(): ";

    cout << sp2.use_count() << endl;

    // Output: 2

    sp2->show();

    // ============================================================
    // get()
    // ============================================================

    // get() returns raw pointer

    Test *raw = sp1.get();

    cout << "\nRaw pointer address: ";

    cout << raw << endl;

    // raw pointer should NOT be manually deleted

    // ============================================================
    // reset()
    // ============================================================

    // reset() decreases reference count

    sp2.reset();

    cout << "\nAfter sp2.reset()" << endl;

    cout << "sp1 use_count(): ";

    cout << sp1.use_count() << endl;

    // Output: 1

    cout << "sp2 use_count(): ";

    cout << sp2.use_count() << endl;

    // Output: 0

    if (sp2 == nullptr)
    {
        cout << "sp2 is empty" << endl;
    }

    // ============================================================
    // swap()
    // ============================================================

    shared_ptr<Test> a = make_shared<Test>();

    shared_ptr<Test> b = make_shared<Test>();

    cout << "\nBefore swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;

    // swap ownership

    a.swap(b);

    cout << "\nAfter swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;

    // ============================================================
    // unique()
    // ============================================================

    // unique() checks only one owner exists

    cout << "\nsp1.unique(): ";

    cout << sp1.unique() << endl;

    // Output: 1

    // ============================================================
    // AUTOMATIC CLEANUP
    // ============================================================

    // object automatically deleted
    // when last shared_ptr destroyed
}

// ============================================================
// WEAK_PTR
// ============================================================

// ============================================================
// WEAK_PTR
// ============================================================

void weakPointerDemo()
{
    cout << "\n================ WEAK_PTR ================\n";

    // weak_ptr is non-owning smart pointer

    // it observes shared_ptr object

    // weak_ptr does NOT increase reference count

    // mainly used to avoid cyclic dependency

    // ============================================================
    // create shared_ptr
    // ============================================================

    shared_ptr<Test> sp = make_shared<Test>();

    // use_count() = 1

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl;

    // Output: 1

    // ============================================================
    // create weak_ptr
    // ============================================================

    weak_ptr<Test> wp = sp;

    // weak_ptr does NOT increase count

    cout << "\nAfter weak_ptr creation" << endl;

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl;

    // Output: 1

    // ============================================================
    // expired()
    // ============================================================

    // expired() checks object exists or not

    cout << "\nwp.expired(): ";

    cout << wp.expired() << endl;

    // Output: 0

    // ============================================================
    // lock()
    // ============================================================

    // weak_ptr cannot directly access object

    // convert weak_ptr -> shared_ptr using lock()

    shared_ptr<Test> temp = wp.lock();

    // lock() increases reference count temporarily

    cout << "\nAfter lock()" << endl;

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl;

    // Output: 2

    // check object still exists

    if (temp != nullptr)
    {
        temp->show();
    }

    // ============================================================
    // reset()
    // ============================================================

    // reset() removes observation

    wp.reset();

    cout << "\nAfter wp.reset()" << endl;

    cout << "wp.expired(): ";

    cout << wp.expired() << endl;

    // Output: 1

    // ============================================================
    // owner_before()
    // ============================================================

    // owner_before() compares ownership order

    shared_ptr<Test> sp2 = make_shared<Test>();

    weak_ptr<Test> wp2 = sp2;

    cout << "\nowner_before(): ";

    cout << wp.owner_before(wp2) << endl;

    // Output:
    // 0 or 1 (implementation dependent)

    // ============================================================
    // object destruction
    // ============================================================

    // when all shared_ptr destroyed
    // object automatically deleted

    sp.reset();

    cout << "\nAfter sp.reset()" << endl;

    cout << "sp use_count(): ";

    cout << sp.use_count() << endl;

    // Output: 0

    // weak_ptr becomes expired

    cout << "wp.expired(): ";

    cout << wp.expired() << endl;

    // Output: 1
}

// ============================================================
// RAW POINTER VS SMART POINTER
// ============================================================

void rawPointerProblem()
{
    cout << "\n================ RAW POINTER PROBLEM ================\n";

    // raw pointer requires manual delete

    Test *p = new Test();

    p->show();

    // manual delete required

    delete p;

    // forgetting delete causes memory leak
}

// ============================================================
// MAIN
// ============================================================

int main()
{
    rawPointerProblem();

    uniquePointerDemo();

    sharedPointerDemo();

    weakPointerDemo();

    return 0;
}