/*
A C++ program is logically divided into the following sections:

------------------------------------------------------------
1) HEADER SECTION (Preprocessor Directives)
------------------------------------------------------------
Used to include libraries and define macros before compilation.
no need to use ";" at end
#include       : Includes standard/header files
#define         : Defines macros/constants
#ifdef          : Checks if macro is defined
#ifndef         : Checks if macro is not defined
#if             : Conditional compilation
#else           : Alternative condition
#endif          : Ends conditional block

Special Predefined Macros:
__LINE__        : Current line number in code
__FILE__        : Current file name
__DATE__        : Compilation date
__TIME__        : Compilation time

------------------------------------------------------------
2) DECLARATION SECTION
------------------------------------------------------------
Used to declare program elements before use.

class           : Declares user-defined data types
function        : Function prototypes (declaration only)
enum            : Enumeration type declaration
variable        : Variable declarations (global/local)

------------------------------------------------------------
3) DEFINITION SECTION
------------------------------------------------------------
Used to define actual implementation of declared elements.

class           : Class definition (data + functions)
function        : Function body/implementation
enum            : Enum definition with values
variables       : Initialization of variables

------------------------------------------------------------
4) MAIN FUNCTION SECTION
------------------------------------------------------------
Entry point of every C++ program.
using namespace std;
main() function : Execution starts here


------------------------------------------------------------
OVERALL FLOW:
Header → Declaration → Definition → Main Execution

------------------------------------------------------------
NOTE:
- Program execution always starts from main()
- Preprocessor directives are handled before compilation
*/

//Example
/*
------------------------------------------------------------
1) HEADER SECTION (Preprocessor Directives)
------------------------------------------------------------
*/
#include <iostream> //<istream>+<ostream>
#include <cmath>

#define PI 3.14159   // Macro definition

using namespace std;

/*
------------------------------------------------------------
2) DECLARATION SECTION
------------------------------------------------------------
*/

// Function declaration (prototype)
double calculateArea(double radius); //you can directly define function without declaration

// Class declaration : you can directly define class without declaring
class Circle {
public:
    double radius;
    void display();
};

/*
------------------------------------------------------------
3) DEFINITION SECTION
------------------------------------------------------------
*/

// Function definition
double calculateArea(double radius) {
    return PI * radius * radius;
}

// Class function definition
void Circle::display() {
    cout << "Circle radius: " << radius << endl;
    cout << "Area: " << calculateArea(radius) << endl;
}

/*
------------------------------------------------------------
4) MAIN FUNCTION SECTION
------------------------------------------------------------
*/
int main() {

    // Variable declaration
    Circle c;

    float radius;
    cin>>radius;
    // Assign value
    c.radius = radius;
    cerr<<"No error yet"<<endl;
    // Function call
    c.display();

    cout << "Program execution started from main()" << endl;

    return 0;
}