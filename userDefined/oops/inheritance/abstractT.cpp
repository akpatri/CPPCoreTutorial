/*
1. abstract class: - has at least one pure virtual function (=0)
2. cannot create object: Shape s; ❌
3. must override pure virtual function in derived class: otherwise derived class also becomes abstract
4. used for:
   - interface design
   - achieving runtime polymorphism
5. base pointer can point to derived object: Shape *ptr = new Circle(); ✔
*/

#include <iostream>
using namespace std;


// ABSTRACT CLASS
class Shape
{
public:
    // pure virtual function
    virtual void draw() = 0; // = 0 makes this function "abstract" i.e. no implementation here (only declaration)

    // normal function (allowed inside abstract class)
    void info()
    {
        cout << "This is a Shape" << endl;
    }
};

// DERIVED CLASS 1
class Circle : public Shape
{
public:
    // must override draw(), otherwise Circle also becomes abstract
    void draw() override
    {
        cout << "Drawing Circle" << endl;
    }
};

// DERIVED CLASS 2
class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing Rectangle" << endl;
    }
};

// MAIN FUNCTION
int main()
{
    // Shape s; ❌ not allowed (abstract class)

    // base pointer pointing to derived objects
    Shape *s1 = new Circle();
    Shape *s2 = new Rectangle();

    // runtime polymorphism
    s1->draw();   // calls Circle::draw()
    s2->draw();   // calls Rectangle::draw()

    // calling normal function from base class
    s1->info();

    // cleanup (good practice)
    delete s1;
    delete s2;

    return 0;
}


