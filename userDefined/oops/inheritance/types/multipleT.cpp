/*
==================== IMPORTANT POINTS ====================

1. multiple inheritance:
   - one class inherits from multiple base classes

   syntax:
   class Derived : access Base1, access Base2

2. derived class gets:
   - all accessible members from ALL base classes

3. advantage:
   - combine features from different classes

4. ambiguity problem:
   if both base classes have same function name

   Example:

   class A { public: void show() { cout << "A\n"; } };
   class B { public: void show() { cout << "B\n"; } };

   class C : public A, public B {};

   C obj;
   obj.show();   // ❌ ERROR (ambiguous)

   solution:
   obj.A::show();  // ✔ call A version
   obj.B::show();  // ✔ call B version

5. careful use:
   - can make code complex
   - prefer composition if overused

=========================================================
*/

#include <iostream>
using namespace std;

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

// ==================================================
// MAIN FUNCTION
// ==================================================
int main()
{
    C c;
    c.test();

    return 0;
}
