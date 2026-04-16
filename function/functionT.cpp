#include <iostream>
#include <cstdarg> // for variable arguments (va_list)
using namespace std;

// ============================================================
// 🔷 FUNCTION DECLARATION (PROTOTYPE): Forward reference
// → informs compiler before use (forward reference)
// → default arguments should either in function declaration(recomanded) or in initialization
// ============================================================
int add(int a, int b); // simple declaration

int mul(int a, int b = 2); // argument order: positional -> defalut

int sumAll(int count, ...); // variable argument function (var_args)

// ============================================================
// 🔷 MAIN (CALLING BEFORE DEFINITION → FORWARD REFERENCE)
// ============================================================

int main()
{
    // ========================================================
    // 🔷 FUNCTION CALLS
    // ========================================================

    cout << add(2, 3) << endl; // normal call

    cout << mul(5) << endl;    // uses default argument b=2
    cout << mul(5, 4) << endl; // overrides default

    cout << sumAll(4, 1, 2, 3, 4) << endl; // var_args call → first param tells count

    // ========================================================
    // 🔷 PASS BY VALUE
    // → copy is passed, original not modified
    // ========================================================

    int x = 10;
    passByValue(x);
    cout << "After passByValue: " << x << endl; // unchanged

    // ========================================================
    // 🔷 PASS BY REFERENCE (&)
    // → alias of original variable, modifies original
    // ========================================================

    passByReference(x);
    cout << "After passByReference: " << x << endl; // changed

    // ========================================================
    // 🔷 PASS BY POINTER (*)
    // → address is passed, dereference to modify
    // ========================================================

    passByPointer(&x);
    cout << "After passByPointer: " << x << endl; // changed

    cout <<"inline function :" << square(5) << endl;    // square replaced by 5*5
    return 0;
}

// ============================================================
// 🔷 FUNCTION DEFINITIONS
// ============================================================

// ============================================================
// INLINE FUNCTION
// → suggests compiler to replace function call with function body
// ============================================================

inline int square(int x)
{
    return x * x;
}

int add(int a, int b) // definition (no default args here)
{
    return a + b;
}

int mul(int a, int b) // default argument NOT repeated here
{
    return a * b;
}

// ============================================================
// 🔷 VARIABLE ARGUMENT FUNCTION
// RULES:
// 1. '...' must be LAST parameter
// 2. at least one fixed parameter required (like count)
// 3. caller must pass correct number of args
// ============================================================

int sumAll(int count, ...)
{
    va_list args;          // declare argument list
    va_start(args, count); // initialize

    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int); // read next argument
    }

    va_end(args); // cleanup

    return sum;
}

// ============================================================
// 🔷 PASSING METHODS
// ============================================================

void passByValue(int x) // copy created
{
    x = x + 10; // does NOT affect original
}

void passByReference(int &x) // reference (alias)
{
    x = x + 10; // modifies original
}

void passByPointer(int *x) // pointer (address)
{
    *x = *x + 10; // dereference and modify
}