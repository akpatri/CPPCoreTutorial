#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    // ============================================================
    // 🔷 1. tuple (heterogeneous container)
    // ============================================================
    tuple<int, string, double> t1(1, "Hello", 3.14);


    // ============================================================
    // 🔷 2. ELEMENT ACCESS (get)
    // ============================================================
    cout << "First: " << get<0>(t1) << endl;
    cout << "Second: " << get<1>(t1) << endl;
    cout << "Third: " << get<2>(t1) << endl;


    // ============================================================
    // 🔷 3. make_tuple (type deduction)
    // ============================================================
    auto t2 = make_tuple(10, "World", 2.5);


    // ============================================================
    // 🔷 4. tuple_size (compile-time size)
    // ============================================================
    cout << "Size of tuple: "
         << tuple_size<decltype(t2)>::value << endl;


    // ============================================================
    // 🔷 5. tuple_element (type info)
    // ============================================================
    tuple_element<1, decltype(t2)>::type x = "Test";
    cout << "tuple_element<1>: " << x << endl;


    // ============================================================
    // 🔷 6. tie (unpacking)
    // ============================================================
    int a;
    string b;
    double c;

    tie(a, b, c) = t2;   // unpack tuple

    cout << "Unpacked: " << a << " " << b << " " << c << endl;


    // ============================================================
    // 🔷 7. ignore (skip values)
    // ============================================================
    int d;
    string e;

    tie(d, ignore, e) = make_tuple(1, 999, "Skip");

    cout << "Ignore example: " << d << " " << e << endl;


    // ============================================================
    // 🔷 8. tuple_cat (concatenate tuples)
    // ============================================================
    auto t3 = tuple_cat(t1, t2);

    cout << "tuple_cat size: "
         << tuple_size<decltype(t3)>::value << endl;


    // ============================================================
    // 🔷 9. forward_as_tuple (reference forwarding)
    // ============================================================
    int p = 5;
    auto t4 = forward_as_tuple(p);

    get<0>(t4) = 20;   // modifies original p
    cout << "After forward_as_tuple: " << p << endl;


    return 0;
}