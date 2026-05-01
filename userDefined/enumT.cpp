#include <iostream>
using namespace std;

// == ENUM IN C++ (ENHANCED COMPLETE CHEAT SHEET) ==


// -- BASIC ENUM DECLARATION --
// enum = user-defined type with named integer constants
// default underlying type is int
enum Day
{
    SUN = 0,   // explicitly assigned → 0
    MON,       // auto → 1
    TUE,       // auto → 2
    WED = 10,  // manually set → 10
    THU,       // auto → 11
    FRI,       // auto → 12
    SAT        // auto → 13
} weekday, days; // optional global instances (rarely used)

// final values: SUN=0, MON=1, TUE=2, WED=10, THU=11, FRI=12, SAT=13


// -- ENUM WITH CUSTOM UNDERLYING TYPE --
// useful for memory optimization or low-level programming
enum Status : char
{
    OK = 1,
    FAIL = 0
};


// -- ENUM WITH DUPLICATE VALUES (ALLOWED) --
enum Test
{
    A = 1,
    B = 1,  // allowed → same value as A
    C = 2
};


// -- STRONGLY TYPED ENUM (MODERN C++) --
// avoids implicit int conversion and name conflicts
enum class Color
{
    RED,
    GREEN,
    BLUE
};


// -- FUNCTION TO PRINT ENUM AS TEXT --
void printDay(Day d)
{
    switch (d)
    {
        case SUN: cout << "Sunday"; break;
        case MON: cout << "Monday"; break;
        case TUE: cout << "Tuesday"; break;
        case WED: cout << "Wednesday"; break;
        case THU: cout << "Thursday"; break;
        case FRI: cout << "Friday"; break;
        case SAT: cout << "Saturday"; break;
        default:  cout << "Invalid Day"; // handles invalid enum values safely
    }
}


int main()
{
    // -- DECLARATION & INITIALIZATION --
    Day today = MON;           // direct initialization
    Day tomorrow = Day::THU;   // scope resolution (optional in plain enum)

    // -- ASSIGNMENT --
    today = FRI;               // assigning another enum value

    // -- PRINTING ENUM (INTEGER) --
    // enums are stored as integers internally
    cout << "FRI value: " << today << endl; // prints 12

    // -- PRINTING ENUM (TEXT) --
    cout << "FRI as text: ";
    printDay(today);
    cout << endl;

    // -- TYPE CASTING (INT → ENUM) --
    // no safety check → invalid values possible
    Day d = (Day)2;            // 2 → TUE

    cout << "Casted value (2): ";
    printDay(d);
    cout << endl;

    // -- LOOP THROUGH ENUM --
    // enums are not iterable → use integer loop
    cout << "\nEnum values (integers):\n";
    for (int i = SUN; i <= SAT; i++)
    {
        cout << i << " ";
    }

    cout << "\nEnum values (names):\n";
    for (int i = SUN; i <= SAT; i++)
    {
        printDay((Day)i);      // cast int → enum
        cout << " ";
    }
    cout << endl;

    // -- SWITCH WITH ENUM --
    // enums are commonly used in switch-case
    switch (today)
    {
        case MON: cout << "Monday\n"; break;
        case FRI: cout << "Friday\n"; break;
        default:  cout << "Other day\n";
    }

    // -- COMPARISON OPERATIONS --
    // enums support comparisons (internally integers)
    if (today == FRI)
    {
        cout << "Comparison works: It's Friday\n";
    }

    // -- ARRAY INDEXING USING ENUM --
    // enums can act as array indices
    string shortNames[] = {"Sun", "Mon", "Tue", "?", "?", "?", "?"};
    cout << "Indexing example: " << shortNames[TUE] << endl;

    // -- SIZE OF ENUM --
    // usually same as int (4 bytes), but may vary
    cout << "Size of Day enum: " << sizeof(Day) << " bytes\n";

    // -- INVALID ENUM VALUE --
    // compiler allows out-of-range values → dangerous
    Day invalid = (Day)100;
    cout << "Invalid enum test: ";
    printDay(invalid);
    cout << endl;

    // -- ENUM CLASS USAGE --
    Color c = Color::RED;

    // cout << c; ❌ not allowed (no implicit conversion)

    cout << "Enum class value (explicit cast): " << (int)c << endl;

    // -- BITMASK ENUM (FLAGS USAGE) --
    // used in systems programming (permissions, options)
    enum Permission
    {
        READ  = 1,   // 001
        WRITE = 2,   // 010
        EXEC  = 4    // 100
    };

    int p = READ | WRITE; // combine flags

    if (p & READ)         // check flag
    {
        cout << "Read permission granted\n";
    }

    return 0;
}


// -- IMPORTANT NOTES --
// enum values are constants (cannot modify at runtime)
// default values auto-increment unless manually overridden
// multiple names can share same integer value
// enum is NOT type-safe → implicit conversion to int allowed
// enum class is type-safe and scoped → preferred in modern C++
// invalid values can be assigned via casting → must validate manually
// useful in switch-case, flags, indexing, state representation