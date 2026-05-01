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
// 🔷 Funciton with array: defined prior to use , hence no need to forward reference
// ============================================================
// 🔷 Function for 1D array
void modify1D(int arr[], int size){   // int arr[] becomes int* arr
    for(int i = 0; i < size; i++){
        arr[i] += 5;   // modifies original array (same memory location)
    }
}
// 🔷 Function for 2D array
void modify2D(int arr[][3], int row){   // last [] size must be fixed
    for(int i = 0; i < row; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] *= 2;   // modifies original 2D array
        }
    }
}

int main()
{
    
    // 🔷 FUNCTION CALLS
    cout << add(2, 3) << endl; // normal call
    cout << mul(5) << endl;    // uses default argument b=2
    cout << mul(5, 4) << endl; // overrides default
    cout << sumAll(4, 1, 2, 3, 4) << endl; // var_args call → first param tells count

    // 🔷 PASS BY VALUE → copy is passed, original not modified
    int x = 10;
    passByValue(x);
    cout << "After passByValue: " << x << endl; //10: unchanged

    // 🔷 PASS BY REFERENCE (&) → alias of original variable, modifies original
    passByReference(x);
    cout << "After passByReference: " << x << endl; // changed

    // 🔷 PASS BY POINTER (*) → address is passed, dereference to modify
    passByPointer(&x);
    cout << "After passByPointer: " << x << endl; // changed

    cout <<"inline function :" << square(5) << endl;    // square replaced by 5*5
    return 0;


    int arr2D[2][3] = {{1, 2, 3},{4, 5, 6}};
    modify1D(arr2D[0], 3); // &arr2D[0][0] is passed
    modify2D(arr2D, 2);  // arr2D → passed as pointer to first row
}

// ============================================================
// 🔷 FUNCTION DEFINITIONS
// ============================================================
// INLINE FUNCTION → suggests compiler to replace function call with function body, cant be a method
inline int square(int x)
{
    return x * x;
}

// definition (no default args here)
int add(int a, int b) 
{
    return a + b;
}

// default argument at declaration: NOT repeated here
int mul(int a, int b) 
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

