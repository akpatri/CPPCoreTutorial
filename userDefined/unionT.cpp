/*
STRUCT:
- Separate memory for each member
- All members can store values at the same time
- Larger memory usage

UNION:
- Shared memory for all members
- Only one member valid at a time
- Memory efficient
*/
#include <iostream>
#include <cstring>
using namespace std;

/* -------------------- UNION DECLARATION -------------------- */

union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{

    /* -------------------- UNION VARIABLE -------------------- */

    Data d;

    /* -------------------- ASSIGN VALUES -------------------- */

    d.i = 10;
    cout << "Integer: " << d.i << endl;

    d.f = 3.14;
    cout << "Float: " << d.f << endl;

    /*
    ⚠️ Important:
    - Previous value (i) is overwritten because memory is shared
    */

    strcpy(d.str, "Hello");
    cout << "String: " << d.str << endl;

    /*
    Now only 'str' is valid.
    Accessing i or f now gives garbage/undefined values.
    */

    /* -------------------- POINTER TO UNION -------------------- */

    Data *ptr = &d;

    cout << "\nUsing Pointer:\n";
    cout << ptr->str << endl;

    /* -------------------- ARRAY OF UNION -------------------- */

    Data arr[2];

    arr[0].i = 100;
    arr[1].f = 5.5;

    cout << "\nArray of Union:\n";
    cout << arr[0].i << endl;
    cout << arr[1].f << endl;

    return 0;
}