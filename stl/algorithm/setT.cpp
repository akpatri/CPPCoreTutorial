#include <iostream>     /* for input/output */
#include <vector>       /* for std::vector */
#include <algorithm>    /* for set algorithms */
using namespace std;

/*
    ===================== STL SET OPERATIONS =====================

    Perform mathematical set operations on SORTED ranges

    ============================================================

    ===================== PARAMETER PATTERN =====================

    algo(start1, end1, start2, end2, destination)

    start1, end1 -> first sorted range
    start2, end2 -> second sorted range
    destination  -> where result will be stored
*/

int main() {

    vector<int> A = {1, 2, 3, 4, 5};   // MUST be sorted
    vector<int> B = {3, 4, 5, 6, 7};   // MUST be sorted

    vector<int> result;   // destination container



    // ===================== 1. set_union() =====================
    /*
        set_union(start1, end1, start2, end2, dest)

        result = ALL elements from both ranges
        duplicates handled → appears max times
    */
    result.clear();   // clear previous data

    set_union(A.begin(), A.end(),
              B.begin(), B.end(),
              back_inserter(result));   // auto push_back

    cout << "Union: ";
    for (int x : result) cout << x << " ";
    cout << endl;



    // ===================== 2. set_intersection() =====================
    /*
        set_intersection(...)

        result = COMMON elements only
    */
    result.clear();

    set_intersection(A.begin(), A.end(),
                     B.begin(), B.end(),
                     back_inserter(result));

    cout << "Intersection: ";
    for (int x : result) cout << x << " ";
    cout << endl;



    // ===================== 3. set_difference() =====================
    /*
        set_difference(A, B)

        result = elements in A but NOT in B
    */
    result.clear();

    set_difference(A.begin(), A.end(),
                   B.begin(), B.end(),
                   back_inserter(result));

    cout << "A - B: ";
    for (int x : result) cout << x << " ";
    cout << endl;



    // ===================== 4. set_symmetric_difference() =====================
    /*
        set_symmetric_difference(...)

        result = elements in A or B BUT NOT BOTH
    */
    result.clear();

    set_symmetric_difference(A.begin(), A.end(),
                             B.begin(), B.end(),
                             back_inserter(result));

    cout << "Symmetric Difference: ";
    for (int x : result) cout << x << " ";
    cout << endl;



    /*
        ===================== IMPORTANT NOTES =====================

        ✔ MUST HAVE SORTED INPUT ⚠️
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());

        ✔ back_inserter()
            - dynamically inserts elements
            - avoids manual resizing

        ✔ Handling duplicates:
            union                -> max(freqA, freqB)
            intersection         -> min(freqA, freqB)
            difference           -> freqA - freqB
            symmetric_difference -> abs(freqA - freqB)

        ✔ Time Complexity:
            O(n + m)

        ✔ Trick:
            If using set<int> instead of vector,
            sorting is automatically handled
    */

    return 0;
}