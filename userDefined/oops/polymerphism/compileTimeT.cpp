#include <iostream>
using namespace std;

/*
====================================================
        COMPILE TIME POLYMORPHISM IN C++
====================================================

Compile Time Polymorphism means:
The compiler decides which function/operator
to call during compilation.
Note (::, sizeof(), . operator) cant be overloaded
Types:
1. Function / Method Overloading
2. Operator Overloading
*/


class Calculator {
public:

    /*
    ----------------------------------------
    FUNCTION / METHOD OVERLOADING
    ----------------------------------------

    Same function name
    Different parameters
    */

    // Method 1
    int add(int a, int b) {
        return a + b;
    }

    // Method 2
    // Different parameter types
    double add(double a, double b) {
        return a + b;
    }

    // Method 3
    // Different number of parameters
    int add(int a, int b, int c) {
        return a + b + c;
    }
};


/*
----------------------------------------
OPERATOR OVERLOADING
----------------------------------------

We are teaching C++ how '+' should work
for custom objects.
*/

class Box {
public:
    int value;

    // Constructor
    Box(int v) {
        value = v;
    }

    /*
    Overloading + operator

    This:
        b1 + b2

    Internally becomes:
        b1.operator+(b2)
    */

    Box operator + (Box other) {

        // Temporary object
        Box temp(0);

        // Add object values
        temp.value = value + other.value;

        return temp;
    }
};


int main() {

    cout << "===== FUNCTION OVERLOADING =====" << endl;

    Calculator c;

    /*
    Compiler selects correct method
    during compilation.
    */

    // Calls add(int, int)
    cout << c.add(2, 3) << endl;

    // Calls add(double, double)
    cout << c.add(2.5, 3.5) << endl;

    // Calls add(int, int, int)
    cout << c.add(1, 2, 3) << endl;


    cout << endl;
    cout << "===== OPERATOR OVERLOADING =====" << endl;

    Box b1(10);
    Box b2(20);

    /*
    Compiler calls:
        b1.operator+(b2)
    */

    Box result = b1 + b2;

    cout << result.value << endl;


    return 0;
}