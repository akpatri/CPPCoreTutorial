/*
========================================================
                SHARED POINTER IN C++
========================================================

Definition:
- shared_ptr is a smart pointer
- Multiple shared_ptr can own same object
- Uses reference counting
- Object automatically deleted
  when reference count becomes 0

Header File:
    #include <memory>

Syntax:
    shared_ptr<data_type> ptr_name;

Example:
    shared_ptr<int> ptr;

========================================================
                INTERNAL WORKING
========================================================

- shared_ptr maintains:
    1. Actual pointer
    2. Reference counter

- Every copy increases count
- reset()/destruction decreases count
- When count becomes 0:
      object automatically deleted

========================================================
                IMPORTANT POINTS
========================================================

1. Supports shared ownership
2. Automatic memory management
3. Prevents memory leak
4. Slightly slower than raw pointer
   because of reference counting
5. Copying is allowed
6. Recommended creation:
       make_shared<Type>()

========================================================
                MAIN FUNCTIONS
========================================================

1. make_shared()
   -> creates shared_ptr

2. use_count()
   -> returns total owners

3. get()
   -> returns raw pointer

4. reset()
   -> releases ownership

5. swap()
   -> swaps ownership

6. unique()
   -> checks only one owner exists

========================================================
                ACCESS OPERATORS
========================================================

ptr->member
(*ptr).member

========================================================
                TIME COMPLEXITY
========================================================

Creation      -> O(1)
Copy          -> O(1)
reset()       -> O(1)
use_count()   -> O(1)

========================================================
                IMPORTANT NOTES
========================================================

1. Never manually delete:
       ptr.get()

2. Avoid creating multiple shared_ptr
   from same raw pointer

   WRONG:
       Test* p = new Test();

       shared_ptr<Test> a(p);
       shared_ptr<Test> b(p);

   Causes double delete problem

3. Prefer:
       make_shared<Test>()

4. shared_ptr increases memory usage
   because of control block

========================================================
*/

#include <iostream>
#include <memory>
using namespace std;

// ================= CLASS =================

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

// ================= CREATE FUNCTION =================

void createDemo()
{
    cout << "================ CREATE =================\n"
         << endl;

    // make_shared()

    shared_ptr<Test> sp1 = make_shared<Test>();

    // operator->

    sp1->show();

    // operator*

    (*sp1).show();

    cout << endl;
}

// ================= USE COUNT FUNCTION =================

void useCountDemo()
{
    cout << "================ USE_COUNT =================\n"
         << endl;

    shared_ptr<Test> sp1 = make_shared<Test>();

    cout << "sp1 use_count(): ";

    cout << sp1.use_count() << endl;

    /*
    Output:
    1
    */

    cout << endl;
}

// ================= SHARED OWNERSHIP FUNCTION =================

void sharedOwnershipDemo()
{
    cout << "================ SHARED OWNERSHIP =================\n"
         << endl;

    shared_ptr<Test> sp1 = make_shared<Test>();

    // copy allowed

    shared_ptr<Test> sp2 = sp1;

    cout << "After copy()" << endl;

    cout << "sp1 use_count(): ";

    cout << sp1.use_count() << endl;

    /*
    Output:
    2
    */

    cout << "sp2 use_count(): ";

    cout << sp2.use_count() << endl;

    /*
    Output:
    2
    */

    sp2->show();

    cout << endl;
}

// ================= GET FUNCTION =================

void getDemo()
{
    cout << "================ GET =================\n"
         << endl;

    shared_ptr<Test> sp1 = make_shared<Test>();

    // get()

    Test *raw = sp1.get();

    cout << "Raw pointer address: ";

    cout << raw << endl;

    /*
    IMPORTANT:
    Do NOT manually delete raw pointer
    */

    cout << endl;
}

// ================= RESET FUNCTION =================

void resetDemo()
{
    cout << "================ RESET =================\n"
         << endl;

    shared_ptr<Test> sp1 = make_shared<Test>();

    shared_ptr<Test> sp2 = sp1;

    cout << "Before reset()" << endl;

    cout << "sp1 use_count(): ";

    cout << sp1.use_count() << endl;

    /*
    Output:
    2
    */

    // reset()

    sp2.reset();

    cout << "\nAfter sp2.reset()" << endl;

    cout << "sp1 use_count(): ";

    cout << sp1.use_count() << endl;

    /*
    Output:
    1
    */

    cout << "sp2 use_count(): ";

    cout << sp2.use_count() << endl;

    /*
    Output:
    0
    */

    if (sp2 == nullptr)
    {
        cout << "sp2 is empty" << endl;
    }

    cout << endl;
}

// ================= SWAP FUNCTION =================

void swapDemo()
{
    cout << "================ SWAP =================\n"
         << endl;

    shared_ptr<Test> a = make_shared<Test>();

    shared_ptr<Test> b = make_shared<Test>();

    cout << "Before swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;

    // swap ownership

    a.swap(b);

    cout << "\nAfter swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;

    cout << endl;
}

// ================= UNIQUE FUNCTION =================

void uniqueDemo()
{
    cout << "================ UNIQUE =================\n"
         << endl;

    shared_ptr<Test> sp1 = make_shared<Test>();

    cout << "sp1.unique(): ";

    cout << sp1.unique() << endl;

    /*
    Output:
    1
    */

    shared_ptr<Test> sp2 = sp1;

    cout << "After copy()" << endl;

    cout << "sp1.unique(): ";

    cout << sp1.unique() << endl;

    /*
    Output:
    0
    */

    cout << endl;
}

// ================= AUTOMATIC CLEANUP FUNCTION =================

void cleanupDemo()
{
    cout << "================ AUTOMATIC CLEANUP =================\n"
         << endl;

    {
        shared_ptr<Test> sp = make_shared<Test>();

        cout << "Inside scope" << endl;
    }

    // destructor automatically called here

    cout << "Outside scope" << endl;

    cout << endl;
}

// ================= MAIN FUNCTION =================

int main()
{
    createDemo();

    useCountDemo();

    sharedOwnershipDemo();

    getDemo();

    resetDemo();

    swapDemo();

    uniqueDemo();

    cleanupDemo();

    return 0;
}