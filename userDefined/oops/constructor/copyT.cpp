/*
==================== IMPORTANT POINTS ====================
1. copy constructor: ClassName(const ClassName &obj)

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
    int *data; //it's value store an address

    // constructor
    Shallow(int val)
    {
        data = new int(val);   // allocate memory
    }

    // copy constructor (default behavior → shallow copy)
    Shallow(const Shallow &obj) //here obj refers to lvalue
    {
        data = obj.data;   // copies address only (shared memory)
    }

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
};


int main()
{
    cout << "=== SHALLOW COPY ===\n";
    Shallow s1(10);
    Shallow s2 = s1;   // copy constructor // can also be "Shallow s2(s1)"
    s2.set(50);        // modifies shared memory
    s1.display();      // both changed
    s2.display();

    cout << "\n=== DEEP COPY ===\n";
    Deep d1(10);
    Deep d2 = d1;      // copy constructor
    d2.set(50);        // only d2 changes
    d1.display();      // unchanged
    d2.display();


    return 0;
}

/*
==================== OUTPUT ====================

=== SHALLOW COPY ===
Value: 50, Address: 0x123...
Value: 50, Address: 0x123...   (same address)

=== DEEP COPY ===
Value: 10, Address: 0x456...
Value: 50, Address: 0x789...   (different address)

================================================
*/