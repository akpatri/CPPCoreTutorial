/*
1) PRIMARY (FUNDAMENTAL)
- int(4B)            : stores whole numbers (e.g., -10, 0, 25)
- short int          : uses less memory than int (smaller range)
- long int           : can store larger values than int
- long long int      : stores very large integers
- signed(defalue)    : allows both negative and positive values
- unsigned           : stores only zero and positive values

- char(1B)           : stores a single character (e.g., 'A')
- signed char        : character type with negative/positive range
- unsigned char      : character type with only positive range (0–255)

- bool(1b)           : stores true (1) or false (0)

- float(4B)          : stores decimal numbers (less precision, ~6 digits)
- double(8B)         : stores decimal numbers (more precision, ~15 digits)
- long double        : stores decimal numbers (highest precision)

- void               : represents no value (used in functions, pointers)

- wchar_t(2B)        : wide character (used for large character sets)
- char16_t           : 16-bit character (Unicode)
- char32_t           : 32-bit character (Unicode)

2) DERIVED
- array              : fixed-size collection of same type elements
- pointer            : stores memory address of another variable
- reference          : another name (alias) for an existing variable
- function           : block of code that performs a task and may return a value

3) USER DEFINED
- struct             : groups different types of variables under one name
- class              : similar to struct but supports data + functions
- union              : stores different data types in same memory location
- enum               : defines a set of named integer constants
- typedef / using    : creates a new name (alias) for an existing type
*/

#include <iostream>
using namespace std;

// ===== USER DEFINED TYPES =====

// struct: group of variables (public by default)
struct Student {
    int id;        // integer member
    char grade;    // character member
};

// class: user-defined type with data + functions (private by default)
class Box {
public:
    int length;    // public data member
};

// union: all members share same memory
union Data {
    int i;         // integer member
    float f;       // float member (shares same memory as i)
};

// enum: named integer constants
enum Day { MON, TUE, WED };

// typedef: alias for existing type
typedef int Integer;

// using: modern alias
using Number = double;


// ===== FUNCTION (DERIVED TYPE) =====
int add(int a, int b) {   // function taking two ints
    return a + b;         // returns sum
}


int main() {

    // ===== PRIMARY TYPES =====

    int a = 10;                 // integer
    //intiger with modifiers
    short int b = 5;            // smaller integer
    long int c = 100000;        // larger integer
    long long int d = 1000000000; // very large integer
    unsigned int e = 20;        // only non-negative

    char ch = 'A';              // character
    bool flag = true;           // boolean (true/false)

    float f = 3.14f;            // single precision
    double d1 = 3.14159;        // double precision
    long double ld = 3.1415926535; // high precision

    wchar_t w = L'A';           // wide character
    char16_t c16 = u'A';        // 16-bit character
    char32_t c32 = U'A';        // 32-bit character

    void* vptr = nullptr;       // void pointer (generic pointer)

    // ===== DERIVED TYPES =====

    int arr[3] = {1, 2, 3};     // array of integers

    int x = 10;
    int* p = &x;                // pointer storing address of x

    int y = 20;
    int& lref = y;              // lvalue reference (alias of y)

    int&& rref = 30;            // rvalue reference (binds to temporary)

    // ===== USER DEFINED TYPES =====

    Student s = {1, 'A'};       // struct object

    Box box;                    // class object
    box.length = 15;            // accessing member

    Data data;
    data.i = 100;               // using union (only one active member)

    Day today = MON;            // enum variable

    Integer num = 50;           // typedef alias
    Number pi = 3.14;           // using alias

    // ===== FUNCTION CALL =====
    int result = add(2, 3);     // calling function

    // ===== OUTPUT =====

    cout << "int: " << a << endl;
    cout << "char: " << ch << endl;
    cout << "bool: " << flag << endl;

    cout << "float: " << f << endl;
    cout << "double: " << d1 << endl;
    cout << "long double: " << ld << endl;

    cout << "array[0]: " << arr[0] << endl;
    cout << "pointer value (*p): " << *p << endl;

    cout << "lvalue reference: " << lref << endl;
    cout << "rvalue reference: " << rref << endl;

    cout << "struct id: " << s.id << endl;
    cout << "class length: " << box.length << endl;
    cout << "union value: " << data.i << endl;

    cout << "enum (MON=0): " << today << endl;

    cout << "typedef Integer: " << num << endl;
    cout << "using Number: " << pi << endl;

    cout << "function add: " << result << endl;

    return 0;
}