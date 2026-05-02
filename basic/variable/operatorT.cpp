/*
Operator type wrt operads
Unary -> [ ++, --, +, -, !, ~, &, *, sizeof ]
Binary -> [ +, -, *, /, %, <, <=, >, >=, ==, !=,
            &&, ||, &, |, ^, <<, >>,
            =, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>= ]
Ternary -> [ ? : ]

Operators
-- Arithmetic Operators --
Used to perform basic mathematical calculations.
+    : Adds two values (a + b)
-    : Subtracts second value from first (a - b)
*    : Multiplies two values (a * b)
/    : Divides first value by second (a / b)
%    : Returns remainder after division (a % b)

-- Increment / Decrement Operators --
Used to increase or decrease a value by 1.
++   : Increases value by 1 (can be pre or post)
--   : Decreases value by 1 (can be pre or post)

-- Relational Operators --
Used to compare two values; result is true (1) or false (0).
<    : Checks if left value is less than right
<=   : Checks if left value is less than or equal to right
>    : Checks if left value is greater than right
>=   : Checks if left value is greater than or equal to right
==   : Returns true if both values are equal
!=   : Returns true if values are not equal

-- Logical Operators --
Used to combine or invert conditions (mainly in if statements).
&&   : Returns true if both conditions are true
||   : Returns true if at least one condition is true
!    : Reverses the result (true becomes false, false becomes true)

-- Bitwise Operators --
Operate directly on binary (bit-level) representation of data.
&    : AND (1 if both bits are 1)
|    : OR (1 if at least one bit is 1)
^    : XOR (1 if bits are different)
~    : NOT (flips all bits)
<<   : Left shift (moves bits left, multiplies by 2^n)
>>   : Right shift (moves bits right, divides by 2^n)

-- Assignment Operators --
Used to assign values to variables and update them.
=    : Assigns value (a = b)
+=   : Adds and assigns (a = a + b)
-=   : Subtracts and assigns (a = a - b)
*=   : Multiplies and assigns (a = a * b)
/=   : Divides and assigns (a = a / b)
%=   : Modulus and assigns (a = a % b)
&=   : Bitwise AND and assign
|=   : Bitwise OR and assign
^=   : Bitwise XOR and assign
<<=  : Left shift and assign
>>=  : Right shift and assign

-- Conditional Operator --
A shorthand for if-else decision making.
? :  : Syntax → (condition ? value_if_true : value_if_false)

-- Pointer / Memory Operators --
Used for working with memory addresses.
&    : Gets the address of a variable
*    : Accesses value stored at an address (dereference)

-- Special Operator --
sizeof() : Returns memory size (in bytes) of a variable or data type

-- Comma Operator --
Used to separate multiple expressions in a single statement and evaluate them from left to right. The final expression’s value is returned.
, : Evaluates expressions from left to right and returns the value of the last expression 
Example: int var1 = (a = 5, b = 10, a + b); //var1=15

-- Notes --
- Most comparisons return 1 (true) or 0 (false)
- Bitwise operators work at binary level (used in low-level programming)
- Use parentheses () to control evaluation order
*/

#include <iostream>
using namespace std;

void operatorFun() {

    // Arithmetic
    int a = 10, b = 3;
    cout << "Arithmetic: " << (a + b) << " " << (a - b)
         << " " << (a * b) << " " << (a / b) << " " << (a % b) << endl;

    // Increment / Decrement
    int x = 5;
    cout << "Inc/Dec: " << ++x << " " << x-- << endl;

    // Relational
    cout << "Relational: " << (a < b) << " " << (a >= b)
         << " " << (a == b) << " " << (a != b) << endl;

    // Logical
    bool p = true, q = false;
    cout << "Logical: " << (p && q) << " " << (p || q) << " " << (!p) << endl;

    // Bitwise
    cout << "Bitwise: " << (a & b) << " " << (a | b)
         << " " << (a ^ b) << " " << (~a) << endl;
    cout << (a << 1) << " " << (a >> 1) << endl;

    // Assignment
    int c = 7;
    c += 3;
    c -= 2;
    c *= 2;
    c /= 3;
    c %= 2;
    cout << "Assignment: " << c << endl;

    // Conditional (ternary)
    cout << "Ternary: " << ((a > b) ? a : b) << endl;

    // Pointer / Memory
    int *ptr = &a;
    cout << "Pointer: " << *ptr << " address: " << ptr << endl;

    // Special
    cout << "Sizeof int: " << sizeof(a) << endl;

    // Comma operator
    int commaResult = (a = 5, b = 20, a + b);
    //without paranthesis: int c = a = 7, b = 20, a + b; is ((int c = a = 7), (b = 20), (a + b));
    cout << "Comma operator result: " << commaResult << endl;
}

int main() {
    operatorFun();
    return 0;
}

/*
if 2 operand there, which operand execute,, determined by associativity
==order of precendence==
ScopeResolution>Unary > Multiplicative > Additive > Shift > Relational >
Equality > Bitwise > Logical > Ternary > Assignment > Comma

*/

