#include <iostream>     /* for input/output */
#include <vector>       /* for vector */
#include <algorithm>    /* for relational algorithms */
using namespace std;

/*
    ===================== RELATIONAL ALGORITHMS =====================

    Used to COMPARE:
    - values
    - ranges (containers)

    Properties:
    1. Do NOT modify data
    2. Return bool / pair
    3. Used in conditions

    ================================================================

    ===================== PARAMETER PATTERN =====================

    algo(start1, end1, start2, end2)

    start1, end1 -> first range
    start2, end2 -> second range
*/

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};
    vector<int> c = {1, 2, 4};



    // ================= equal() =================
    /*
        equal(start1, end1, start2)

        compares two ranges element by element
    */
    bool result1 = equal(a.begin(), a.end(), b.begin());

    cout << "equal(a, b): " << result1 << endl;

    cout << "\n";



    // ================= mismatch() =================
    /*
        mismatch(start1, end1, start2)

        returns pair of iterators
        first mismatch position
    */
    auto p = mismatch(a.begin(), a.end(), c.begin());

    cout << "mismatch(): " << *p.first << " " << *p.second << endl;

    cout << "\n";



    // ================= lexicographical_compare() =================
    /*
        lexicographical_compare(start1, end1, start2, end2)

        works like dictionary comparison:
        first smaller element decides result
    */
    bool result2 = lexicographical_compare(
        a.begin(), a.end(),
        c.begin(), c.end()
    );

    cout << "lexicographical_compare(): " << result2 << endl;

    cout << "\n";



    // ================= is_permutation() =================
    /*
        is_permutation(start1, end1, start2)

        checks both ranges contain SAME elements
        (order does NOT matter)
    */
    vector<int> x = {1, 2, 3};
    vector<int> y = {3, 2, 1};

    bool result3 = is_permutation(x.begin(), x.end(), y.begin());

    cout << "is_permutation(): " << result3 << endl;

    cout << "\n";



    // ================= includes() =================
    /*
        includes(start1, end1, start2, end2)

        checks if RANGE2 is inside RANGE1

        IMPORTANT:
        - both ranges MUST be sorted
    */
    vector<int> big = {1, 2, 3, 4, 5};
    vector<int> small = {2, 3};

    bool result4 = includes(
        big.begin(), big.end(),
        small.begin(), small.end()
    );

    cout << "includes(): " << result4 << endl;

    cout << "\n";



    // ================= container comparison operators =================
    /*
        ==  -> equal
        !=  -> not equal
        <   -> lexicographical compare
    */
    vector<int> p1 = {1, 2, 3};
    vector<int> p2 = {1, 2, 3};
    vector<int> p3 = {1, 2, 5};

    cout << "(p1 == p2): " << (p1 == p2) << endl;
    cout << "(p1 != p3): " << (p1 != p3) << endl;
    cout << "(p1 < p3): " << (p1 < p3) << endl;
    cout << "(p3 > p1): " << (p3 > p1) << endl;

    cout << "\n";



    // ================= min() =================
    /*
        min(a, b) -> returns smaller value
    */
    cout << "min(10, 20): " << min(10, 20) << endl;

    cout << "\n";



    // ================= max() =================
    /*
        max(a, b) -> returns larger value
    */
    cout << "max(10, 20): " << max(10, 20) << endl;

    cout << "\n";



    // ================= minmax() =================
    /*
        minmax(a, b)

        returns pair:
        first  -> minimum
        second -> maximum
    */
    auto ans = minmax(50, 100);

    cout << "minmax(): " << ans.first << " " << ans.second << endl;



    /*
        ===================== IMPORTANT NOTES =====================
        - equal()           -> strict element comparison
        - mismatch()        -> debugging tool (find difference)
        - includes()        -> requires SORTED ranges ⚠️
        - lexicographical   -> used in <, > comparisons

        Return Types:
        equal()            -> bool
        mismatch()         -> pair<iterator, iterator>
        minmax()           -> pair<value, value>
    */

    return 0;
}