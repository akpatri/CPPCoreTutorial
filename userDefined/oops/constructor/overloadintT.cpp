#include <iostream>
using namespace std;

// constructor_overloading + chaining + initializer list
class ClassName
{
public:
    int a;
    float b;
    float sum;
    float product;

    // main constructor (runs first in chaining)
    ClassName(int a, float b) : a(a), b(b), sum(a + b), product(a * b) // initializer list(leftside: class variable, rightside:parameter): runs BEFORE constructor body
    {
        cout << "Constructor with 2 parameters\n";
    }

    // 1-parameter constructor (calls 2-param)
    ClassName(int a) : ClassName(a, 0.0)
    {
        cout << "Constructor with 1 parameter\n";
    }

    // default constructor: default consturctor is implictly defined with empty body, if no constructor is defined
    ClassName() : ClassName(0)
    {
        cout << "Default constructor\n";
    }

    void display()
    {
        cout << "a = " << this->a // this is a pointer to current class
             << ", b = " << b
             << ", sum = " << sum
             << ", product = " << product << endl;
    }

    ~ClassName() //atmost 1 destructor allowed: have no parameter, implictly created if none defined
    {
        cout<<"Called just before object destruction"<<endl;
    }
};

int main()
{
    ClassName obj1;          // default → 1 → 2
    ClassName obj2(10);      // 1 → 2
    ClassName obj3(20, 5.5); // direct 2

    cout << endl;

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}

/*
OUTPUT:

Constructor with 2 parameters
Constructor with 1 parameter
Default constructor

Constructor with 2 parameters
Constructor with 1 parameter

Constructor with 2 parameters

a = 0, b = 0, sum = 0, product = 0
a = 10, b = 0, sum = 10, product = 0
a = 20, b = 5.5, sum = 25.5, product = 110

*/