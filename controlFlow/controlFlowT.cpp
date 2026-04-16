#include <iostream>
using namespace std;

// 🔷 Compact program showing control flow with minimal meaningful logic

int main()
{
    int x = 2;

    // ---------- IF / ELSE IF / ELSE ----------
    if (x < 0)
        cout << "Negative\n";
    else if (x == 0)
        cout << "Zero\n";
    else
        cout << "Positive\n";

    // ---------- SWITCH ----------
    switch (x)
    {
        case 1: cout << "One\n"; break;
        case 2: cout << "Two\n"; break;
        default: cout << "Other\n";
    }

    // ---------- LOOP (single example for all concepts) ----------
    for (int i = 0; i < 5; i++)
    {
        if (i == 1) continue;   // skip 1
        if (i == 3) break;      // stop at 3

        cout << "i = " << i << endl;
    }

    // ---------- WHILE ----------
    int j = 0;
    while (j < 2)
    {
        cout << "while: " << j++ << endl;
    }

    // ---------- DO-WHILE ----------
    int k = 0;
    do
    {
        cout << "do: " << k++ << endl;
    } while (k < 1);

    // ---------- RANGE FOR ----------
    int arr[] = {1, 2};
    for (int v : arr)
        cout << "val: " << v << endl;

    return 0;   // exit program
}