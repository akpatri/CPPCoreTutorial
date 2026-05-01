#include <iostream>
using namespace std;

// hybrid_inheritance.cpp
// purpose:
// understand hybrid inheritance
// (combination of multiple + multilevel inheritance)


// ==================================================
// BASE CLASS (TOP LEVEL)
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
// LEVEL 2 (MULTILEVEL PART)
// ==================================================
class Mammal : public Animal
{
public:
    void walk()
    {
        cout << name << " is walking\n";
    }
};


// ==================================================
// ANOTHER BASE CLASS (FOR MULTIPLE INHERITANCE)
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
// DERIVED CLASS (HYBRID)
// ==================================================
// Dog inherits:
// - Mammal → Animal (multilevel chain)
// - Pet (multiple inheritance)
class Dog : public Mammal, public Pet
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

    d.name = "Charlie";  // ✔ from Animal (top level)

    // accessing functions from all inheritance paths
    d.eat();    // ✔ Animal
    d.walk();   // ✔ Mammal
    d.play();   // ✔ Pet
    d.bark();   // ✔ Dog

    return 0;
}


/*
==================== OUTPUT ====================
Charlie is eating
Charlie is walking
Playing with owner
Charlie is barking
================================================


==================== IMPORTANT POINTS ====================

1. hybrid inheritance:
   - combination of two or more types of inheritance
   - here:
     multilevel (Animal → Mammal → Dog)
     + multiple (Dog ← Pet)

2. structure:
          Animal
             |
          Mammal
             |
             Dog ----> Pet

3. derived class (Dog) gets:
   - Animal members
   - Mammal members
   - Pet members

4. used in real-world complex systems

5. can lead to "diamond problem" in some cases
   (same base inherited multiple times)

=========================================================
*/