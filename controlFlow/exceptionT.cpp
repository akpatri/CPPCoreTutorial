#include <iostream>
#include <exception>
using namespace std;
// 🔷 C++ Exception Handling Keywords Cheat Sheet
// try        → block that may generate exception
// catch      → handles exception
// catch(...) → catch-all handler (any type of exception)
// throw      → used to throw an exception
// noexcept   → specifies function will NOT throw (if violated → terminate)
// noexcept(false) → function may throw exception(same as default)
// exception  → base class for standard exceptions (std::exception)
// what()     → virtual function returning error message
// throw;     → rethrow current exception
// ============================================================
// 🔷 OLD / DEPRECATED (DO NOT USE)
// throw(type) → old exception specification (removed in modern C++)


// 🔷 Custom Exception
class MyException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Custom error!";
    }
};

int main()
{
    try
    {
        // 🔷 NESTED TRY
        try
        {
            throw MyException();        // throw custom exception
        }
        catch (const MyException& e)
        {
            cout << "Inner catch: " << e.what() << endl;
            throw;                      // rethrow to outer block
        }

        // (this line will not execute after throw)
        cout << "After inner try\n";
    }
    catch (const exception& e)          // specific/base handler
    {
        cout << "Outer catch: " << e.what() << endl;
    }
    catch (...)                         // catch-all (must be last)
    {
        cout << "Unknown exception\n";
    }

    return 0;
}