/*
-------------------- DIFFERENCE BETWEEN CLASS AND STRUCTURE --------------------

Definition:
- Both class and structure are user-defined data types used to group variables and functions.

Key Differences:

1. Default Access Specifier:
   - struct → members are PUBLIC by default
   - class  → members are PRIVATE by default

2. Default Inheritance:
   - struct → PUBLIC inheritance by default
   - class  → PRIVATE inheritance by default

3. Usage (General Convention):
   - struct → used for simple data grouping (like records)
   - class  → used for full object-oriented programming (data + functions)

4. Encapsulation:
   - struct → less strict (since members are public by default)
   - class  → supports strong encapsulation (private members)

5. Functionality:
   - In C++: BOTH can have
        ✔ data members
        ✔ member functions
        ✔ constructors/destructors
        ✔ access specifiers (public, private, protected)
   - So technically they are almost the same except defaults

Conclusion:
- Main difference is DEFAULT ACCESS and INHERITANCE behavior.
- In modern C++, difference is mostly by convention, not capability.

----------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstring> // for strcpy
#include <cstdlib> // for malloc/free
using namespace std;

/* -------------------- STRUCTURE DECLARATION -------------------- */
/*
Syntax:
    struct struct_name {
        data_type member1;
        data_type member2;
        ...
    };
Explanation:
    - A structure groups different data types into one unit.
*/

struct Student
{
    int id;
    char name[50];
    float marks;
} default_obj1, default_obj2; //optionally you can create instance simulataneously

int main()
{

    /* --STRUCTURE VARIABLE DECLARATION-- */
    Student s1; // declaring structure variable

    /*-- INITIALIZATION-- */
    s1.id = 101;
    strcpy(s1.name, "Asish");
    s1.marks = 89.5;

    /*--ACCESSING MEMBERS-- */
    // Syntax: object.member
    cout << "Student Details:\n";
    cout << s1.id << " " << s1.name << " " << s1.marks << endl;

    /*--POINTER TO STRUCTURE-- */
    /*
    Syntax: struct_name* ptr = &object;
    Access using pointer: ptr->member
    */
    Student *ptr = &s1;
    cout << "\nUsing Pointer:\n";
    cout << ptr->id << " " << ptr->name << " " << ptr->marks << endl;

    /*-- ARRAY OF STRUCTURES-- */
    // Used to store multiple records
    Student arr[2];
    arr[0].id = 1;
    strcpy(arr[0].name, "A");
    arr[0].marks = 80;

    arr[1].id = 2;
    strcpy(arr[1].name, "B");
    arr[1].marks = 90;

    cout << "\nArray of Structures:\n";
    for (int i = 0; i < 2; i++)
    {
        cout << arr[i].id << " " << arr[i].name << " " << arr[i].marks << endl;
    }

    /* --DYNAMIC STRUCTURE (malloc)--*/
    //- Allocate structure dynamically
    Student *dyn = (Student *)malloc(sizeof(Student));

    dyn->id = 200;
    strcpy(dyn->name, "Dynamic");
    dyn->marks = 95;

    cout << "\nDynamic Structure:\n";
    cout << dyn->id << " " << dyn->name << " " << dyn->marks << endl;

    /*-- MULTIPLE STRUCTURES (calloc)-- */
    //- Allocate multiple structures - Initialized to zero
    Student *list = (Student *)calloc(2, sizeof(Student));

    list[0].id = 301;
    strcpy(list[0].name, "X");
    list[0].marks = 70;

    list[1].id = 302;
    strcpy(list[1].name, "Y");
    list[1].marks = 75;

    cout << "\nMultiple Structures (calloc):\n";
    for (int i = 0; i < 2; i++)
    {
        cout << list[i].id << " " << list[i].name << " " << list[i].marks << endl;
    }

    /*--FREE MEMORY-- */
    free(dyn);
    free(list);

    return 0;
}