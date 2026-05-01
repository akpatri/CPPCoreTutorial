/*
==================== IMPORTANT POINTS (ENHANCED) ====================

lifetime:
- static members exist for the entire program (created once, destroyed once)


1. static variable (class/static data member):
   - shared by all objects (only one copy)
   - declared inside class, defined OUTSIDE class
   - accessed using: ClassName::variable
   - updated value is visible to all objects

   example:
   class A { static int count; };
   int A::count = 0;   // definition (required)


2. static method:
   - belongs to class, not object
   - called using: ClassName::function()
   - does NOT have "this" pointer
   - can directly access ONLY static members
   - cannot directly access non-static members (no object context)

   example:
   static void show()
   {
       cout << count;   // ✔ allowed
       // cout << id;   // ❌ not allowed
   }


3. local variables inside static method:
   - normal local variable → recreated every call
   - static local variable → created once, value persists

   example:
   static void fun()
   {
       int x = 0;        // resets every call
       static int y = 0; // retains value

       x++;
       y++;

       cout << x << " " << y << endl;
   }


4. memory behavior:
   - static variable → one shared memory location
   - non-static variable → separate copy per object


5. initialization rules:
   - static class variable → must be defined outside class
   - static local variable → initialized where declared


6. use cases:
   - counting number of objects
   - shared configuration/settings
   - maintaining state across function calls


==================== MEMORY TRICK ====================

static → ONE copy → shared → lifetime = full program
non-static → MANY copies → per object

=========================================================
*/

#include <iostream>
using namespace std;

// purpose: understand static data members (fields) and static member functions

class ClassName
{
public:
    int id;           // normal (instance) variable, different for each obj
    static int count; // static class variable (shared(same) by all objects): can only be initilized outside of class

    // constructor
    ClassName()
    {
        count++;    // increase shared count
        id = count; // assign unique id
    }

    // static method
    static void showCount()
    {
        // ✔ can access static members directly (shared across all objects)
        cout << "Total objects: " << count << endl;

        // ❌ cannot access non-static members directly
        // cout << id;   // ERROR: no object context (which object's id?)

        // ✔ accessing non-static member using object (allowed)
        ClassName temp;
        cout << "Access via object -> id = " << temp.id << endl;

        // ✔ static local variable (retains value across calls)
        static int callCount = 0;
        callCount++;
        cout << "showCount() called: " << callCount << " times\n";
    }

    // normal method
    void display()
    {
        cout << "Object ID: " << id << endl;
    }
};

// STATIC VARIABLE DEFINITION (outside class): as it is initiated before object creation
int ClassName::count = 0; // must define once

int main()
{
    ClassName obj1;
    ClassName obj2;
    ClassName obj3;

    obj1.display();
    obj2.display();
    obj3.display();

    cout << endl;

    // calling static method
    ClassName::showCount(); // preferred way

    // also possible (but not recommended)
    obj1.showCount();

    return 0;
}

/*
==================== OUTPUT ====================

Object ID: 1
Object ID: 2
Object ID: 3

Total objects: 3

================================================



*/