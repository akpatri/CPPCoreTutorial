#include <iostream>
using namespace std;

// ============================================================
// 🔷 NAMESPACE = LOGICAL CONTAINER
// → used to group related code (variables, functions, classes)
// → helps avoid name conflicts (especially in large projects)
// ============================================================

namespace First
{
    int value = 10;                      // variable inside namespace

    void display()                      // function inside namespace
    {
        cout << "First::value = " << value << endl;
    }
}

namespace Second
{
    int value = 20;                      // same name, different namespace

    void display()
    {
        cout << "Second::value = " << value << endl;
    }
}
// ============================================================
// 🔷 NAMESPACE EXTENSION (OPEN NAMESPACE / SPLIT NAMESPACE)
// → same namespace can be defined in multiple blocks/files → compiler combines them into ONE namespace
// ============================================================

// ---------- First Part of Namespace (maybe in p1.cpp)----------
namespace MySpace
{
    int a = 10;

    void func1()
    {
        cout << "func1 from first block, a = " << a << endl;
    }
}

// ---------- Second Part of SAME Namespace (maybe in p2.cpp) ----------
namespace MySpace   // same name → extends previous namespace
{
    int b = 20;

    void func2()
    {
        cout << "func2 from second block, b = " << b << endl;
    }
}

// ============================================================
// 🔷 NESTED NAMESPACE
// ============================================================
namespace Outer
{
    int x = 100;

    namespace Inner
    {
        int y = 200;
    }
}

// ============================================================
// 🔷 ANONYMOUS (UNNAMED) NAMESPACE
// → gives internal linkage (like static global) → accessible only within this file
// ============================================================

namespace
{
    int hidden = 999;
}

// ============================================================
// 🔷 GLOBAL VARIABLE
// ============================================================
int value = 5;                          // global scope
// ============================================================
// 🔷 MAIN
// ============================================================

int main()
{
    // ========================================================
    // 🔷 ACCESS USING SCOPE RESOLUTION OPERATOR ::
    // → used to access members outside current scope
    // ========================================================

    cout << First::value << endl;       // access First namespace variable
    First::display();                  // call First function

    cout << Second::value << endl;     // access Second namespace variable
    Second::display();

    // ========================================================
    // 🔷 GLOBAL SCOPE ACCESS
    // ========================================================

    int value = 50;                    // local variable (shadows global)

    cout << value << endl;             // local value
    cout << ::value << endl;           // global value using scope resolution

    // ========================================================
    // 🔷 NESTED NAMESPACE ACCESS
    // ========================================================

    cout << Outer::x << endl;                  // outer namespace
    cout << Outer::Inner::y << endl;           // nested namespace

    // ========================================================
    // 🔷 USING DIRECTIVE
    // → brings all members of namespace into current scope
    // ========================================================

    using namespace First;
    cout << value << endl;             // now refers to First::value (not global)

    // ========================================================
    // 🔷 USING DECLARATION
    // → brings specific member into scope
    // ========================================================

    using Second::display;
    display();                         // calls Second::display()

    // ========================================================
    // 🔷 ALIAS (SHORT NAME FOR NAMESPACE)
    // ========================================================

    namespace F = First;               // alias
    cout << F::value << endl;

    // ========================================================
    // 🔷 ANONYMOUS NAMESPACE ACCESS
    // ========================================================

    cout << hidden << endl;            // accessible only in this file

    return 0;
}