#include <iostream>
using namespace std;

int main()
{
    int x = 10, y = 20;

    // 🔷 1. NON-CAPTURE (cannot use x, y)
    auto nonCapture = [](int a, int b)
    {
        return a + b;   // only parameters allowed
    };
    cout << "nonCapture: " << nonCapture(1,2) << endl;

    // 🔷 2. CAPTURE BY VALUE [=] (read-only copy)
    auto byValue = [=](int a)
    {
        // x += a;     // ❌ not allowed (read-only)
        return a + x + y;
    };
    cout << "byValue: " << byValue(5) << endl;

    // 🔷 3. CAPTURE BY REFERENCE [&] (modifies original)
    auto byRef = [&](int a)
    {
        x += a;        // ✔ modifies original x
        return x + y;
    };
    cout << "byRef: " << byRef(5) << endl;
    cout << "x after byRef: " << x << endl;

    // 🔷 4. MIXED CAPTURE [=, &x]
    auto mixed = [=, &x](int a)
    {
        x += a;        // reference
        return x + y;  // y is copied
    };
    cout << "mixed: " << mixed(5) << endl;

    // 🔷 5. MUTABLE (modify value copy)
    auto mutableLambda = [=]() mutable
    {
        x += 100;      // modifies COPY of x, not original
        return x;
    };
    cout << "mutable: " << mutableLambda() << endl;
    cout << "x after mutable: " << x << endl;

    return 0;
}