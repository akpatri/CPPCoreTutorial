#include <iostream>
using namespace std;


// Function template
// template <class type> ret-type func-name(parameter list) {
//    // body of function
// } 

// ============================================================
// 🔷 GENERICS IN C++ → TEMPLATES
// → write code once, work with any datatype
// ============================================================

// ============================================================
// 🔷 FUNCTION TEMPLATE
// ============================================================

template<typename T> // T is generic type
T add(T a, T b) 
{
    return a + b;
}

// ============================================================
// 🔷 MULTIPLE TEMPLATE PARAMETERS
// ============================================================

template<typename T, typename U>
auto addMixed(T a, U b)
{
    return a + b;                   // return type deduced
}

// ============================================================
// 🔷 CLASS TEMPLATE
// ============================================================

template<typename T>    //typename can be replaced with class
class Box
{
    T value;

public:
    Box(T v) : value(v) {}

    T get()
    {
        return value;
    }
};

// ============================================================
// 🔷 TEMPLATE SPECIALIZATION
// → custom behavior for specific type
// ============================================================

template<>
class Box<char>
{
    char value;

public:
    Box(char v) : value(v) {}

    void get()
    {
        cout << "Char: " << value << endl;
    }
};

// ============================================================
// 🔷 DEFAULT TEMPLATE ARGUMENT
// ============================================================

template<typename T = int>
class DefaultBox
{
public:
    T value;
};

// ============================================================
// 🔷 NON-TYPE TEMPLATE PARAMETER
// ============================================================

template<int N>
class Array
{
public:
    int arr[N];                     // size known at compile time
};

// ============================================================
// 🔷 FUNCTION TEMPLATE OVERLOADING
// ============================================================

template<typename T>
void print(T a)
{
    cout << "Generic: " << a << endl;
}

void print(int a)                  // non-template preferred
{
    cout << "Int: " << a << endl;
}

// ============================================================
// 🔷 TEMPLATE WITH REFERENCE
// ============================================================

template<typename T>
void swapVal(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// ============================================================
// 🔷 GENERIC LAMBDA (C++14)
// ============================================================

auto lambda = [](auto a, auto b)
{
    return a + b;
};

// ============================================================
// 🔷 MAIN
// ============================================================

int main()
{
    // ---------- FUNCTION TEMPLATE ----------
    cout << add(2,3) << endl;          // int
    cout << add(2.5,3.5) << endl;      // double

    // ---------- MULTIPLE TYPES ----------
    cout << addMixed(2,3.5) << endl;

    // ---------- CLASS TEMPLATE ----------
    Box<int> b1(10);
    cout << b1.get() << endl;

    Box<char> b2('A');                 // specialized version
    b2.get();

    // ---------- DEFAULT TEMPLATE ----------
    DefaultBox<> d;                   // int by default
    d.value = 5;
    cout << d.value << endl;

    // ---------- NON-TYPE TEMPLATE ----------
    Array<3> arr;                     // size = 3

    // ---------- OVERLOADING ----------
    print(10);                        // calls non-template
    print(3.14);                      // calls template

    // ---------- TEMPLATE WITH REFERENCE ----------
    int x = 1, y = 2;
    swapVal(x,y);
    cout << x << " " << y << endl;

    // ---------- GENERIC LAMBDA ----------
    cout << lambda(2,3) << endl;
    cout << lambda(2.5,3.5) << endl;

    return 0;
}