/*
==================== IMPORTANT POINTS ====================
1. copy constructor: ClassName(const ClassName &obj)
   - it cant be virtual 

2. shallow copy:
   - copies pointer (address)
   - both objects share same memory
   - change in one affects other
   - dangerous → double delete possible

3. deep copy:
   - allocates new memory
   - copies actual value
   - objects are independent ✔

4. rule:
   if class uses dynamic memory → write your own copy constructor

5. copy constructor is ONLY called:
   ✔ when object is initialized using another object or lvalue
     (e.g., A b = a;  OR  A b(a);) //here a is an Compatible Object of Type A

   ❌ NOT called during assignment
     (e.g., b = a; → uses assignment operator)

6. default copy constructor:
   - provided by compiler
   - performs shallow copy

7. if you define:
   - destructor
   - copy constructor
   - assignment operator

   → follow RULE OF 3 (very important in C++)

=========================================================
*/

#include <iostream>
using namespace std;


// purpose:  copy constructor + shallow copy vs deep copy

// ==================================================
// SHALLOW COPY EXAMPLE
// ==================================================
class Shallow
{
public:
    int *data; // it's value store an address

    // constructor
    Shallow(int val)
    {
        data = new int(val);   // allocate memory
    }

    // copy constructor (default behavior → shallow copy)
    Shallow(const Shallow &obj) // here obj refers to lvalue
    {
        data = obj.data;   // copies address only (shared memory)
    }

    /*
    ⚠ NOTE:
    If we DO NOT write this copy constructor,
    compiler will generate one → which also does shallow copy.
    */

    void set(int val)
    {
        *data = val;
    }

    void display()
    {
        cout << "Value: " << *data << ", Address: " << data << endl;
    }

    ~Shallow()
    {
        delete data;   // ⚠ can cause double delete
    }

    /*
    ⚠ PROBLEM:
    s1 and s2 point to same memory.
    When both destructors run → delete same memory twice → CRASH (undefined behavior)
    */
};


// ==================================================
// DEEP COPY EXAMPLE
// ==================================================
class Deep
{
public:
    int *data;

    // constructor
    Deep(int val)
    {
        data = new int(val);
    }

    // copy constructor (deep copy)
    Deep(const Deep &obj)
    {
        data = new int(*obj.data);   // ✔ new memory + copy value
    }

    /*
    ✔ KEY IDEA:
    Instead of copying address → we copy VALUE into NEW memory
    */

    void set(int val)
    {
        *data = val;
    }

    void display()
    {
        cout << "Value: " << *data << ", Address: " << data << endl;
    }

    ~Deep()
    {
        delete data;   // safe (each object has its own memory)
    }

    /*
    ✔ NO PROBLEM:
    Each object owns its own memory → no double delete
    */
};


int main()
{
    cout << "=== SHALLOW COPY ===\n";
    Shallow s1(10);

    // ✔ copy constructor called (initialization)
    Shallow s2 = s1;   // can also be "Shallow s2(s1)"

    // ❌ NOT copy constructor (assignment)
    // s2 = s1;   // would call assignment operator instead

    s2.set(50);        // modifies shared memory

    s1.display();      // both changed
    s2.display();

    cout << "\n=== DEEP COPY ===\n";
    Deep d1(10);

    // ✔ copy constructor called
    Deep d2 = d1;

    d2.set(50);        // only d2 changes

    d1.display();      // unchanged
    d2.display();

    return 0;
}

/*
==================== EXTRA INTERVIEW POINTS ====================

✔ Difference: Initialization vs Assignment

    Deep d2 = d1;   → copy constructor
    d2 = d1;        → assignment operator

✔ Why pass by reference in copy constructor?
    - avoids infinite recursion
    - avoids unnecessary copying

✔ What happens if pass by value?
    Deep(Deep obj) → infinite loop (copy constructor keeps calling itself)

✔ Rule of 3 (VERY IMPORTANT):
    If your class uses:
        - dynamic memory (new/delete)
    then you must define:
        1. destructor
        2. copy constructor
        3. copy assignment operator

✔ Modern C++ (Rule of 5):
    + move constructor
    + move assignment operator

===============================================================

==================== OUTPUT ====================

=== SHALLOW COPY ===
Value: 50, Address: 0x123...
Value: 50, Address: 0x123...   (same address)

=== DEEP COPY ===
Value: 10, Address: 0x456...
Value: 50, Address: 0x789...   (different address)

================================================
*/