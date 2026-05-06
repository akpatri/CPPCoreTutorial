/*
===============================================================================
FUNCTION REFERENCE (WITH CALLBACK)
-------------------------------------------------------------------------------
DEFINITION:
→ A function reference is an alias to a function.
→ It does NOT store address separately (unlike pointer).

SYNTAX:
return_type (&ref_name)(parameter_types) = function_name;

KEY POINTS:
- Must be initialized at declaration
- Cannot be reassigned
- Cannot be NULL
- Can be used as callback (but less flexible)
===============================================================================
*/

#include <iostream>
using namespace std;

// ------------------ FUNCTIONS ------------------
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

// ------------------ CALLBACK USING FUNCTION REFERENCE ------------------
void compute(int x, int y, int (&ref)(int, int))
{
    cout << "Result: " << ref(x, y) << endl;
}

int main()
{
    // ================== FUNCTION REFERENCE ==================
    int (&ref)(int, int) = add;   // must initialize

    cout << "Using reference (add): " << ref(2, 3) << endl;

    // ❌ NOT ALLOWED (uncomment to see error)
    // ref = multiply;


    // ================== CALLBACK USING REFERENCE ==================
    cout << "\nCallback using function reference:\n";

    compute(10, 5, add);        // pass add
    compute(10, 5, multiply);   // pass multiply


    return 0;
}