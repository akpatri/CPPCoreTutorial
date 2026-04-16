#include <iostream>
using namespace std;

//type of variable: 
// global(application wide scope and lifetime), 
// static(function level scope and application wide lifecycle)
// local(block level scope and lifetime)

//staorage class
// auto
// register
// static
// extern
// mutable

//modifiers for char int double
// signed
// unsigned
// long
// short

//qulaifier
// const
// volatile
// restrict


// ============================================================
// 🔷 GLOBAL VARIABLES
// ============================================================

int g1;        // global default initialization → 0
int g2 = 10;   // global copy initialization
static int g3; // global static → 0

// ============================================================
// 🔷 MACRO CONSTANT (PREPROCESSOR)
// ============================================================

#define PI 3.14 // macro constant → no type, replaced before compilation

// ============================================================
// 🔷 ENUMERATED CONSTANTS
// ============================================================

enum Color
{
    RED,
    GREEN,
    BLUE
}; // enumerated constants → RED=0, GREEN=1, BLUE=2

// ============================================================
// 🔷 FUNCTION
// ============================================================

int main()
{
    // ========================================================
    // 🔷 LOCAL VARIABLES
    // ========================================================

    int a;        // local default initialization → garbage value
    static int b; // local static → 0

    // ========================================================
    // 🔷 INITIALIZATION TYPES
    // ========================================================

    int c = 10;      // copy initialization
    int d(20);       // direct initialization
    int e{30};       // list initialization (no narrowing)
    int f{};         // value initialization → 0
    int g = {40};    // copy list initialization
    int h = int(50); // temporary + copy init
    int i = int{};   // value init via temporary → 0

    // ========================================================
    // 🔷 CONSTANT VARIABLES (NAMED CONSTANTS)
    // ========================================================

    const int MAX1 = 100; // constant variable (datatype CONST_NAME)
    int const MAX2 = 200; // constant variable (const datatype NAME)

    // ========================================================
    // 🔷 LITERAL CONSTANTS
    // ========================================================

    int intLiteral = 10;   // integer literal
    int hexLiteral = 0x1A; // hexadecimal literal
    int octLiteral = 012;  // octal literal

    float floatLiteral = 3.14f;  // float literal
    double doubleLiteral = 3.14; // double literal

    char charLiteral = 'A';           // character literal
    bool boolLiteral = true;          // boolean literal
    const char *strLiteral = "Hello"; // string literal

    // ========================================================
    // 🔷 TYPE CONVERSION
    // ========================================================

    double d1 = 10; // implicit conversion → int to double

    int x = 10, y = 3;
    double d2 = x / y; // implicit but integer division first → result 3

    // ---------- Explicit Conversion ----------

    double d3 = (double)x / y; // C-style cast (cast notation)

    double d4 = double(x) / y; // function notation

    double d5 = static_cast<double>(x) / y; // named cast (C++ style, safest)
    //try as operator as well

    // ========================================================
    // 🔷 AUTO & DECLTYPE
    // ========================================================

    auto a1 = 10;   // auto → int
    auto a2 = 3.14; // auto → double

    decltype(a2) a3 = 5.5; // decltype → same type as a2 (double)

    // ========================================================
    // 🔷 ARRAYS
    // ========================================================

    int arr1[3];          // garbage values
    int arr2[3]{};        // all 0
    int arr3[3]{1, 2, 3}; // list initialized

    // ========================================================
    // 🔷 COMMA OPERATOR
    // ========================================================

    int z = (x = 5, y = 10, x + y); // evaluates left→right, result = last expression (15)

    // ========================================================
    // 🔷 ENUM USAGE
    // ========================================================

    Color col = RED; // enum variable

    // ========================================================
    // 🔷 LVALUE & RVALUE
    // ========================================================

    int a = 5;      // 'a' is lvalue (has memory location)
    int b = a + 10; // (a + 10) is rvalue (temporary)

    int &ref = a; // lvalue reference → binds to lvalue

    int &&rref = 20; // rvalue reference → binds to temporary

    // int &&wrong = a;        // ❌ error → rvalue ref cannot bind to lvalue

    // ========================================================
    // 🔷 REFERENCE VARIABLE (&)
    // → alias of existing variable (must be initialized)
    // ========================================================

    int a = 10;

    int &ref = a; // reference → ref is another name for a

    ref = 20; // modifies 'a'


    // ========================================================
    // 🔷 POINTER VARIABLE (*)
    // → stores address, can be reassigned
    // ========================================================

    int b = 30;

    int *ptr = &b;            // pointer to b

    *ptr = 40;                // modifies b
    
    // ========================================================
    // 🔷 OUTPUT (SAFE VARIABLES ONLY)
    // ========================================================

    cout << "Global g1: " << g1 << endl;
    cout << "Global g2: " << g2 << endl;
    cout << "Static g3: " << g3 << endl;

    cout << "b (static local): " << b << endl;

    cout << "c,d,e,f: " << c << " " << d << " " << e << " " << f << endl;

    cout << "Constants: " << MAX1 << " " << MAX2 << endl;

    cout << "Literals: " << intLiteral << " " << floatLiteral << " " << charLiteral << endl;

    cout << "Conversions: " << d1 << " " << d2 << " " << d3 << " " << d5 << endl;

    cout << "Auto/Decltype: " << a1 << " " << a2 << " " << a3 << endl;

    cout << "Comma operator result: " << z << endl;

    cout << "Enum value: " << col << endl;

    cout << ref << " " << rref << endl;

    ref = 20;          // modifies 'a'
    cout << a << endl; // 20

    cout << b << endl;        // 40
    int c = 50;
    ptr = &c;                 // pointer can point to another variable
    cout << *ptr << endl;     // 50

    return 0;
}