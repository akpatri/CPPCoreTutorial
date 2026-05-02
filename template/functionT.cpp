/*
Purpose:
Function template allows one function to work with different data types.
It helps in code reusability and reduces duplicate code.

Syntax
-------
template <typename T>
return_type function_name(parmType name)
{
    // code
}

or

template <class T>
return_type function_name(parmType name)
{
    // code
}
type_declaration can be replaced with 'T'
typename and class mean same thing in templates.

How Template Works
-------------------
Compiler creates separate functions automatically based on data type.
Example:
max(10, 20)      -> compiler creates int version
max(3.5, 7.2)   -> compiler creates double version

Advantages
-----------
1. Code reusability
2. Less duplicate code
3. Easier maintenance
4. Type independent programming

Function Template with One Type
--------------------------------
template <typename T>
T add(T a, T b)
{
    return a + b;
}
T becomes actual data type during function call.

Function Template with Multiple Types
--------------------------------------
template <typename T1, typename T2>
void show(T1 a, T2 b)
{
    cout << a << " " << b;
}

Template Arguments
-------------------
Explicit type: add<int>(10, 20);

Implicit type: add(10, 20);
Compiler usually detects type automatically.

Important Notes
----------------
Template works at compile time.
Function body should support all operations used by data type.
Templates do not generate code until function is called.
Different data types create different function versions.
*/

#include <iostream>
using namespace std;

// function template
template <typename T> T maximum(T a, T b)
{

    if (a > b)
        return a; // return greater value

    return b;
}

int main()
{

    cout << maximum<int>(10, 20) << endl; // int version

    cout << maximum(5.5, 2.1) << endl; // double version

    cout << maximum('A', 'Z') << endl; // char version

    return 0;
}