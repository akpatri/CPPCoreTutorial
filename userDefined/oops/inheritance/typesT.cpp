/*
==================== FINAL SUMMARY ====================
BASE MEMBERS:
public    → accessible everywhere
protected → accessible in derived classes only
private   → accessible only inside base class

------------------------------------------------------
PUBLIC INHERITANCE:
Base public    → public
Base protected → protected
Base private   → NOT accessible

------------------------------------------------------
PROTECTED INHERITANCE:
Base public    → protected
Base protected → protected
Base private   → NOT accessible

------------------------------------------------------
PRIVATE INHERITANCE:
Base public    → private
Base protected → private
Base private   → NOT accessible

------------------------------------------------------
MEMORY TRICK:
public inheritance    → "same as base"
protected inheritance → "all become protected"
private inheritance   → "all become private"

======================================================
*/

#include <iostream>
using namespace std;

// BASE CLASS
class Base
{
public:
    int pub = 1; // accessible everywhere
protected:
    int pro = 2; // accessible in derived classes
private:
    int pri = 3; // NOT accessible outside Base
};

// 1. PUBLIC INHERITANCE
class DerivedPublic : public Base
{
public:
    void test()
    {
        cout << "\n[Public Inheritance]\n";
        cout << pub << endl; // ✔ remains public
        cout << pro << endl; // ✔ remains protected (accessible inside class)
        // cout << pri;       // ❌ ERROR (private not accessible)
    }
};

// 2. PROTECTED INHERITANCE
class DerivedProtected : protected Base
{
public:
    void test()
    {
        cout << "\n[Protected Inheritance]\n";
        cout << pub << endl; // ✔ becomes protected
        cout << pro << endl; // ✔ remains protected
        // cout << pri;       // ❌ ERROR
    }
};

// 3. PRIVATE INHERITANCE
class DerivedPrivate : private Base
{
public:
    void test()
    {
        cout << "\n[Private Inheritance]\n";
        cout << pub << endl; // ✔ becomes private
        cout << pro << endl; // ✔ becomes private
        // cout << pri;       // ❌ ERROR
    }
};

// MAIN FUNCTION
int main()
{
    DerivedPublic dp;
    dp.test();
    // access from outside class
    cout << dp.pub << endl; // ✔ still public
    // cout << dp.pro;        // ❌ protected
    // cout << dp.pri;        // ❌ private

    DerivedProtected dprot;
    dprot.test();
    // cout << dprot.pub;     // ❌ now protected (not accessible outside)

    DerivedPrivate dpriv;
    dpriv.test();
    // cout << dpriv.pub;     // ❌ now private

    return 0;
}
