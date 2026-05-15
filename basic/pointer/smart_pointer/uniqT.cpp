/*
========================================================
                UNIQUE POINTER IN C++
========================================================

Definition:
- unique_ptr is a smart pointer
- Only one unique_ptr can own object
- Provides exclusive ownership
- Automatically deletes memory

Header File:
    #include <memory>

Syntax:
    unique_ptr<data_type> ptr_name;

Example:
    unique_ptr<int> ptr;

========================================================
                IMPORTANT POINTS
========================================================

1. Only one owner allowed
2. Copying NOT allowed
3. Ownership transferable using move()
4. Prevents memory leaks
5. Automatic memory management
6. Recommended creation:
       make_unique<Type>()

========================================================
                MAIN FUNCTIONS
========================================================

make_unique() -> creates unique_ptr
get()         -> returns raw pointer
release()     -> releases ownership
reset()       -> deletes/replaces object
swap()        -> swaps ownership
move()        -> transfers ownership

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

void uniquePointerDemo()
{
    cout << "\n================ UNIQUE_PTR ================\n";

    // unique_ptr provides exclusive ownership
    // only one unique_ptr can own object


    // ============================================================
    // make_unique()
    // ============================================================

    unique_ptr<Test> ptr1 = make_unique<Test>(); // create unique_ptr object

    ptr1->show(); // access member function using ->

    (*ptr1).show(); // dereference object using *


    // ============================================================
    // get()
    // ============================================================

    Test *raw = ptr1.get(); // get raw pointer

    cout << "\nRaw pointer address: " << raw << endl;

    // do NOT manually delete raw
    // because ptr1 still owns object


    // ============================================================
    // COPY NOT ALLOWED
    // ============================================================

    // unique_ptr cannot be copied

    // unique_ptr<Test> ptr2 = ptr1; // ERROR


    // ============================================================
    // move()
    // ============================================================

    unique_ptr<Test> ptr2 = move(ptr1); // transfer ownership

    if (ptr1 == nullptr) // ptr1 becomes empty
    {
        cout << "ptr1 is now empty" << endl;
    }

    ptr2->show(); // ptr2 now owns object


    // ============================================================
    // release()
    // ============================================================

    Test *raw2 = ptr2.release(); // release ownership

    cout << "\nAfter release()" << endl;

    if (ptr2 == nullptr)
    {
        cout << "ptr2 is empty" << endl;
    }

    delete raw2; // manual delete required


    // ============================================================
    // reset()
    // ============================================================

    unique_ptr<Test> ptr3 = make_unique<Test>(); // create object

    ptr3.reset(new Test()); // delete old object and assign new object

    cout << "\nAfter reset()" << endl;

    ptr3->show();

    ptr3.reset(); // delete object and make pointer empty

    if (ptr3 == nullptr)
    {
        cout << "ptr3 is empty after reset()" << endl;
    }


    // ============================================================
    // swap()
    // ============================================================

    unique_ptr<Test> a = make_unique<Test>(); // first object

    unique_ptr<Test> b = make_unique<Test>(); // second object

    cout << "\nBefore swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;

    a.swap(b); // swap ownership

    cout << "\nAfter swap()" << endl;

    cout << "a address: " << a.get() << endl;

    cout << "b address: " << b.get() << endl;


    // ============================================================
    // AUTOMATIC CLEANUP
    // ============================================================

    // remaining objects automatically deleted
    // when function ends
}

// ================= MAIN FUNCTION =================

int main()
{
    uniquePointerDemo(); // call unique_ptr demo function

    return 0;
}