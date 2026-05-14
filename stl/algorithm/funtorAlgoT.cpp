#include <iostream>
#include <functional> // required for functors
using namespace std;

int main()
{
    // ============================================================
    // 🔷 ARITHMETIC FUNCTORS
    // ============================================================

    // plus<int>() -> addition

    cout << "plus<int>()(10, 20): ";

    cout << plus<int>()(10, 20) << endl;

    // Output: 30



    // minus<int>() -> subtraction

    cout << "minus<int>()(20, 10): ";

    cout << minus<int>()(20, 10) << endl;

    // Output: 10



    // multiplies<int>() -> multiplication

    cout << "multiplies<int>()(5, 4): ";

    cout << multiplies<int>()(5, 4) << endl;

    // Output: 20



    // divides<int>() -> division

    cout << "divides<int>()(20, 5): ";

    cout << divides<int>()(20, 5) << endl;

    // Output: 4



    // modulus<int>() -> remainder

    cout << "modulus<int>()(20, 3): ";

    cout << modulus<int>()(20, 3) << endl;

    // Output: 2



    // negate<int>() -> unary minus

    cout << "negate<int>()(10): ";

    cout << negate<int>()(10) << endl;

    // Output: -10



    // ============================================================
    // 🔷 RELATIONAL FUNCTORS
    // ============================================================

    // equal_to<int>() -> ==

    cout << "\nequal_to<int>()(10, 10): ";

    cout << equal_to<int>()(10, 10) << endl;

    // Output: 1



    // not_equal_to<int>() -> !=

    cout << "not_equal_to<int>()(10, 20): ";

    cout << not_equal_to<int>()(10, 20) << endl;

    // Output: 1



    // greater<int>() -> >

    cout << "greater<int>()(20, 10): ";

    cout << greater<int>()(20, 10) << endl;

    // Output: 1



    // less<int>() -> <

    cout << "less<int>()(10, 20): ";

    cout << less<int>()(10, 20) << endl;

    // Output: 1



    // greater_equal<int>() -> >=

    cout << "greater_equal<int>()(10, 10): ";

    cout << greater_equal<int>()(10, 10) << endl;

    // Output: 1



    // less_equal<int>() -> <=

    cout << "less_equal<int>()(10, 20): ";

    cout << less_equal<int>()(10, 20) << endl;

    // Output: 1



    // ============================================================
    // 🔷 LOGICAL FUNCTORS
    // ============================================================

    // logical_and<bool>() -> &&

    cout << "\nlogical_and<bool>()(true, true): ";

    cout << logical_and<bool>()(true, true) << endl;

    // Output: 1



    // logical_or<bool>() -> ||

    cout << "logical_or<bool>()(false, true): ";

    cout << logical_or<bool>()(false, true) << endl;

    // Output: 1



    // logical_not<bool>() -> !

    cout << "logical_not<bool>()(true): ";

    cout << logical_not<bool>()(true) << endl;

    // Output: 0



    // ============================================================
    // 🔷 BITWISE FUNCTORS
    // ============================================================

    // bit_and<int>() -> &

    cout << "\nbit_and<int>()(6, 3): ";

    cout << bit_and<int>()(6, 3) << endl;

    // Output: 2



    // bit_or<int>() -> |

    cout << "bit_or<int>()(6, 3): ";

    cout << bit_or<int>()(6, 3) << endl;

    // Output: 7



    // bit_xor<int>() -> ^

    cout << "bit_xor<int>()(6, 3): ";

    cout << bit_xor<int>()(6, 3) << endl;

    // Output: 5



    // bit_not<int>() -> ~

    cout << "bit_not<int>()(5): ";

    cout << bit_not<int>()(5) << endl;

    // Output: -6



    return 0;
}