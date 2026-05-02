/*
Purpose:
Class template allows a class to work with different data types.
It helps in creating generic classes.

Syntax
-------
template <typename T>
class ClassName
{
    // members
};

or

template <class T>
class ClassName
{
    // members
};
typename and class mean same thing in templates.
Note: Here T should be treated as a datatype that is declared in class.

How Class Template Works
-------------------------
Compiler creates separate class versions automatically for each data type.
Example:
Box<int>      -> int version of class
Box<double>   -> double version of class

Advantages
-----------
1. Code reusability
2. Generic programming
3. Less duplicate code
4. Easier maintenance

Template Data Member
---------------------
Template type can be used as data member type.
Example: T data;

Template Member Function
-------------------------
Template type can also be used inside member functions.
Example:
void show()
{
    cout << data;
}

Creating Object
----------------
Syntax:
ClassName<data_type> object_name;
Example:
Box<int> b1;
Box<float> b2;

Multiple Template Types
------------------------
template <typename T1, typename T2>
Example:
template <typename T1, typename T2>
class Test
{
};

Important Notes
----------------
Class template works at compile time.
Compiler creates separate class versions for different data types.
Template class does not generate code until object is created.
*/
#include <iostream>
using namespace std;

template <typename T> class Box // class template
{
    T data; // template type data member
public:
    // template type parameter
    void setData(T value)
    {
        data = value;
    }

    // template type return type
    T getData()
    {
        return data;
    }
};

int main()
{
    Box<int> b1; // int object
    b1.setData(100); // set integer value
    cout << b1.getData() << endl; // get integer value

    Box<double> b2; // double object
    b2.setData(45.67); // set double value
    cout << b2.getData() << endl; // get double value

    Box<char> b3; // char object
    b3.setData('A'); // set character value
    cout << b3.getData() << endl; // get character value

    return 0;
}