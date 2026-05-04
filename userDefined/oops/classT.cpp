/*
BRACE / LIST INITIALIZATION COMPLETE NOTES

RULES:
1. ClassA x;        -> default initialization → members = garbage (uninitialized)
2. ClassA x{};      -> value initialization → members = 0 / nullptr
3. ClassA x = {};   -> same as x{}  (value initialization)

4. ClassA x{obj};   -> copy initialization → copy constructor (default = shallow copy)
5. ClassA x = {obj};-> same as above

6. ClassA x{1,2};   -> requires matching constructor → ERROR here (no constructor)

7. Arrays:
   ClassA arr[n];    -> each element garbage
   ClassA arr[n]{};  -> all elements zero initialized
   ClassA arr[n]={}; -> same

8. Dynamic:
   new ClassA;       -> garbage
   new ClassA{};     -> zero initialized

9. Pointer:
   int* p;
   {} -> nullptr
   no {} -> wild pointer

10. Temporary:
    ClassA{}; -> zero init, destroyed immediately

CORE RULE:
NO {}  -> garbage
{}     -> zero / nullptr
*/

#include <iostream>
using namespace std;

class ClassA
{
public:
    int a;
    int b;
    int* data;

    void init(int x, int y)
    {
        a = x;
        b = y;
        data = new int(x);
    }

    void display() const
    {
        cout << "a=" << a
             << " b=" << b
             << " data=" << (data ? *data : 0)
             << endl;
    }

    ~ClassA()
    {
        delete data;
    }
};

int main()
{
    // ----- BASIC OBJECTS -----

    ClassA o1;           // a=garbage, b=garbage, data=garbage ⚠
    ClassA o2{};         // a=0, b=0, data=nullptr ✔
    ClassA o3 = {};      // same as o2 ✔

    // ----- COPY WITH BRACES -----

    ClassA o4{};         // a=0, b=0, data=nullptr
    ClassA o5{o4};       // shallow copy → data copied (nullptr here)
    ClassA o6 = {o4};    // same as o5 ✔

    // ----- INVALID (NO CONSTRUCTOR) -----

    // ClassA o7{1,2};   // ERROR → no matching constructor
    // ClassA o8 = {1,2}; // ERROR → same reason

    // ----- ARRAYS (STACK) -----

    ClassA arr1[2];      // each: garbage ⚠
    ClassA arr2[2]{};    // each: a=0, b=0, data=nullptr ✔
    ClassA arr3[2] = {}; // same as arr2 ✔

    // ----- PARTIAL ARRAY -----

    ClassA arr4[3] = {ClassA{}};  
    // arr4[0]: a=0, b=0, data=nullptr
    // arr4[1], arr4[2]: also zero ✔

    // ----- DYNAMIC OBJECT -----

    ClassA* p1 = new ClassA;     // garbage ⚠
    ClassA* p2 = new ClassA{};   // zero initialized ✔

    // ----- DYNAMIC ARRAY -----

    ClassA* p3 = new ClassA[2];      // each: garbage ⚠
    ClassA* p4 = new ClassA[2]{};    // each: zero ✔

    // ----- TEMPORARY -----

    ClassA{};        // zero init → destroyed immediately
    ClassA().display(); // same effect ✔

    // ----- FUNCTION ARGUMENT -----

    auto func = [](ClassA obj)
    {
        obj.display();
    };

    func(ClassA{});   // temporary zero-initialized object

    // ----- POINTER / REFERENCE -----

    ClassA* ptr = &o2;   // pointer to object
    ClassA& ref = o2;    // reference (no new object)

    // ----- CLEANUP -----

    delete p1;
    delete p2;
    delete[] p3;
    delete[] p4;

    return 0;
}