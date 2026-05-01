/*
== 1) GENERAL SYNTAX ==
[storage_class] [function_specifier] [type_modifier] [cv_qualifier]
(type | auto | decltype(expr))
[declarator] variable_name [initializer];


== 2) STORAGE (LIFETIME & LINKAGE) ==
auto            → default for local variables (automatic storage)
register        → suggests CPU register (ignored in modern C++)
static          → lifetime = entire program
extern          → declared here, defined elsewhere
thread_local    → separate copy per thread

notes:
- only one storage class is used
- 'mutable' is NOT a storage class (only for class members)


== 3) TYPE / TYPE DEDUCTION ==
type → int, char, float, double, bool, void
        struct / class / enum (user-defined types)

auto → type deduced from initializer (must be initialized)

decltype(expr) → type deduced from expression
notes:
- expression not evaluated
- preserves const and references

type_modifier:
signed → + and -, unsigned → only non-negative
short → smaller size, long → larger size
notes:
- can combine (unsigned long int)
- long double is valid


== 4) QUALIFIERS ==
const → value cannot change
volatile → value may change unexpectedly

notes:
- can combine: const volatile
- const variables must be initialized


== 5) FUNCTION SPECIFIERS ==
constexpr → compile-time constant
inline → allows multiple definitions (mainly globals)


== 6) DECLARATORS ==
* → pointer
& → lvalue reference: cant have void datatype
&& → rvalue reference :cant have void datatype

notes:
- defines how variable refers to data
- can combine in same statement


== 7) INITIALIZATION ==
= value         → copy initialization
(value)         → direct initialization
{value}         → brace initialization

notes:
- optional for normal variables
- required for: const, reference, auto


== 8) MULTIPLE DECLARATION ==
int a, b = 10, *p;


== 9) IMPORTANT RULES ==
- reference must be initialized
- pointer can be nullptr
- const placement matters:
  const type* ptr, type* const ptr, const type* const ptr
- extern: no value = declaration, with value = definition
- local → garbage, static/global → zero-initialized
- order flexible: const unsigned int == unsigned const int
*/

#include <iostream>
using namespace std;

// extern declaration
extern int externalVar;

int main() {
    // == STORAGE ==
    int a = 10; //no need to specify auto: it is by defalut
    register int b = 20;
    static int c = 30;
    thread_local int d = 40;

    // == TYPE / DEDUCTION ==
    int x = 5;
    auto y = 3.14;
    decltype(x) z = 15;
    unsigned long int ul = 100;

    // == QUALIFIERS ==
    const int ci = 50;
    volatile int vi = 60;
    const volatile int cvi = 70;

    // == DECLARATORS ==
    int *ptr = nullptr;
    int val = 10;
    int &ref = val; //ref and val same: or ref is become other name of val
    int &&rref = 25;

    // == INITIALIZATION ==
    int i1 = 1;
    int i2(2);
    int i3{3};

    // == MULTIPLE DECLARATION ==
    int m1, m2 = 10, *mp = nullptr;

    // == CONST POINTER VARIANTS ==
    const int *p1 = &val;
    int *const p2 = &val;
    const int *const p3 = &val;

    // == USING VALUES ==
    ref=rref;
    cout << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << endl;
    cout << "x=" << x << ", y=" << y << ", z=" << z << ", ul=" << ul << endl;
    cout << "ci=" << ci << ", vi=" << vi << ", cvi=" << cvi << endl;
    cout << "ref=" << ref << ", rref=" << rref << endl;
    cout << "i1=" << i1 << ", i2=" << i2 << ", i3=" << i3 << endl;

    return 0;
}

// extern definition
int externalVar = 999; //lvalue=rvalue