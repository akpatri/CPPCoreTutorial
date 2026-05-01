#include <iostream>
using namespace std;

// multiple_inheritance.cpp
// purpose:
// understand multiple inheritance (one derived ← multiple base classes)


// ==================================================
// BASE CLASS 1
// ==================================================
class Animal
{
public:
    string name;

    void eat()
    {
        cout << name << " is eating\n";
    }
};


// ==================================================
// BASE CLASS 2
// ==================================================
class Pet
{
public:
    void play()
    {
        cout << "Playing with owner\n";
    }
};


// ==================================================
// DERIVED CLASS (MULTIPLE INHERITANCE)
// ==================================================
// Dog inherits from BOTH Animal and Pet
class Dog : public Animal, public Pet
{
public:
    void bark()
    {
        cout << name << " is barking\n";
    }
};


// ==================================================
// MAIN FUNCTION
// ==================================================
int main()
{
    Dog d;

    d.name = "Buddy";   // ✔ from Animal

    d.eat();            // ✔ from Animal
    d.play();           // ✔ from Pet
    d.bark();           // ✔ from Dog

    return 0;
}


/*
==================== OUTPUT ====================
Buddy is eating
Playing with owner
Buddy is barking
================================================


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