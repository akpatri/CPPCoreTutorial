/*
==================== IMPORTANT POINTS ====================

1. move constructor:
   ClassName(ClassName &&obj)

   - takes rvalue reference (&&)
   - transfers ownership of resources
   - avoids deep copy (faster)

2. purpose:
   - used for temporary objects
   - steals resource from source object

3. after move:
   - source object should be left in safe state
   - usually set pointer = nullptr

4. why needed?
   - copying dynamic memory is expensive
   - moving just transfers address (cheap)

5. move constructor is called:
   ✔ when object initialized from temporary/rvalue

     A b = A(10);
     A b(std::move(a));

   ❌ NOT called for lvalues directly
     A b = a;   // copy constructor

6. rule of 5:
   if class manages dynamic memory, define:
   - destructor
   - copy constructor
   - copy assignment operator
   - move constructor
   - move assignment operator

=========================================================
*/

#include <iostream>
using namespace std;

class MoveDemo
{
public:
    int *data;

    // constructor
    MoveDemo(int val)
    {
        data = new int(val);
        cout << "Constructor called\n";
    }

    // copy constructor
    MoveDemo(const MoveDemo &obj)
    {
        data = new int(*obj.data);
        cout << "Copy constructor called\n";
    }

    // move constructor
    MoveDemo(MoveDemo &&obj)
    {
        data = obj.data;       // steal resource
        obj.data = nullptr;    // release ownership

        cout << "Move constructor called\n";
    }

    void display()
    {
        if (data)
            cout << "Value: " << *data << ", Address: " << data << endl;
        else
            cout << "nullptr object\n";
    }

    ~MoveDemo()
    {
        delete data;
    }
};

int main()
{
    cout << "=== COPY ===\n";
    MoveDemo a(10);

    MoveDemo b = a;   // copy constructor

    a.display();
    b.display();

    cout << "\n=== MOVE ===\n";

    MoveDemo c = std::move(a);   // move constructor

    a.display();   // now nullptr
    c.display();

    return 0;
}

/*
==================== EXTRA INTERVIEW POINTS ====================

✔ rvalue:
   temporary object / expiring object

   Example:
   A(10)

✔ lvalue:
   named object

   Example:
   A a(10);

✔ std::move()
   - converts lvalue into rvalue
   - does NOT move itself
   - only allows move

   MoveDemo c = std::move(a);

✔ Why set nullptr after move?
   - prevents double delete
   - moved-from object remains valid

✔ Move is faster than copy because:
   copy:
      allocate new memory + copy value

   move:
      just transfer pointer

===============================================================

==================== OUTPUT ====================

=== COPY ===
Constructor called
Copy constructor called
Value: 10, Address: 0x111...
Value: 10, Address: 0x222...

=== MOVE ===
Move constructor called
nullptr object
Value: 10, Address: 0x111...

================================================
*/