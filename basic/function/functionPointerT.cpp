/*
===============================================================================
FUNCTION POINTER (COMPLETE NOTES + EXAMPLE)
-------------------------------------------------------------------------------
DEFINITION:
→ A function pointer stores the address of a function.
→ It allows calling a function indirectly.

SYNTAX:
return_type (*pointer_name)(parameter_types);

EXAMPLE:
int (*fp)(int, int);

DESCRIPTION:
- fp → pointer to a function
- (int, int) → parameters of function
- int → return type of function

IMPORTANT:
- Function name itself acts as its address
    fp = add;     ✔
    fp = &add;    ✔ (optional '&')

- Calling styles:
    fp(2,3);      ✔
    (*fp)(2,3);   ✔

USES:
- Callbacks
- Dynamic function calls
- Passing functions as arguments

ARRAY TYPE: 
declartion: int (*operations[])(int, int)
    operations = array name
    each element stores address of function
Initialization: operation[i]=function_name
call: operation[i](param1, param2);

===============================================================================
*/

#include <iostream>
using namespace std;

// ------------------ NORMAL FUNCTIONS ------------------
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

// ------------------ CALLBACK FUNCTION ------------------
// takes function pointer as parameter
void compute(int x, int y, int (*operation)(int, int))
{
    cout << "Result: " << operation(x, y) << endl;
}

int main()
{
    // ------------------ BASIC FUNCTION POINTER ------------------
    int (*fp)(int, int); // declaration

    fp = add; // assign function

    cout << "Using function pointer:\n";
    cout << fp(2, 3) << endl;    // 5
    cout << (*fp)(4, 5) << endl; // 9

    // ------------------ SWITCHING FUNCTIONS ------------------
    fp = multiply; // change function dynamically
    cout << "After switching function:\n";
    cout << fp(3, 4) << endl; // 12

    // ------------------ CALLBACK DEMO ------------------
    cout << "\nCallback examples:\n";

    compute(10, 5, add);      // pass function as argument
    compute(10, 5, multiply); // different behavior

    //array of function pointer
    int (*operations[2])(int, int) = {
        add,  
    };
    operations[1]=multiply;
    for (int i = 0; i < 4; i++)
    {
        cout << operations[i](50, 10) << endl;
    }

    return 0;
}