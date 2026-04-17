#include <iostream>
#include <new>   // for nothrow
using namespace std;

int main()
{
    // ============================================================
    // 🔷 1. SINGLE OBJECT ALLOCATION
    // ============================================================
    int* p = new int;      // uninitialized
    *p = 10;

    cout << "Single value: " << *p << endl;

    delete p;              // free memory


    // ============================================================
    // 🔷 2. INITIALIZED ALLOCATION
    // ============================================================
    int* p2 = new int(50);   // direct initialization
    cout << "Initialized value: " << *p2 << endl;

    delete p2;


    // ============================================================
    // 🔷 3. ARRAY ALLOCATION
    // ============================================================
    int* arr = new int[3];   // allocate array

    for(int i = 0; i < 3; i++)
        arr[i] = i + 1;

    cout << "Array values: ";
    for(int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;   // IMPORTANT: use delete[]


    // ============================================================
    // 🔷 4. NOTHROW (NO EXCEPTION ON FAILURE)
    // ============================================================
    int* safe = new(nothrow) int[1000000000000];

    if (safe == nullptr)
        cout << "Allocation failed (no exception)\n";

    delete[] safe;


    // ============================================================
    // 🔷 5. DYNAMIC OBJECT (CLASS)
    // ============================================================
    struct Demo {
        int x;
        Demo(int v) : x(v) {}
        void show() { cout << "Demo: " << x << endl; }
    };

    Demo* obj = new Demo(99);   // constructor called
    obj->show();

    delete obj;   // destructor called automatically


    // ============================================================
    // 🔷 6. KEY NOTES
    // ============================================================
    // new  → allocates + constructs
    // delete → destructs + deallocates
    // delete[] → for arrays only
    // mismatch → undefined behavior

    return 0;
}