#include <iostream>     /* for input/output operations */
#include <vector>       /* for std::vector container */
#include <algorithm>    /* for STL searching algorithms */
using namespace std;

/*
    ===================== STL SEARCHING ALGORITHMS =====================

    Used to SEARCH elements or positions

    ================================================================

    ===================== PARAMETER PATTERN =====================

    algo(start, end, value / condition)

    start -> beginning iterator
    end   -> ending iterator (NOT included)
    value -> element to search
    condition -> function returning true/false
*/

int main() {

    vector<int> v = {10, 20, 30, 40, 50};   // sorted container (important)



    // ===================== 1. find() =====================
    /*
        find(start, end, value)

        returns iterator to first occurrence
        if not found -> returns end()
    */
    auto it = find(v.begin(), v.end(), 30);

    if (it != v.end())   // ALWAYS check before dereferencing
        cout << "Found at index: " << it - v.begin() << endl;  // index calculation
    else
        cout << "Not Found\n";



    // ===================== 2. find_if() =====================
    /*
        find_if(start, end, condition)

        condition(x) -> return true → element selected
    */
    auto it2 = find_if(v.begin(), v.end(),
    [](int x)
    {
        return x > 25;   // condition
    });

    if (it2 != v.end())
        cout << "First element > 25: " << *it2 << endl;



    // ===================== 3. binary_search() =====================
    /*
        binary_search(start, end, value)

        returns bool (true/false)
        REQUIREMENT: data must be SORTED
    */
    bool exists = binary_search(v.begin(), v.end(), 40);

    cout << "40 exists? " << (exists ? "Yes" : "No") << endl;



    // ===================== 4. lower_bound() =====================
    /*
        lower_bound(start, end, value)

        returns iterator to FIRST element >= value
    */
    auto lb = lower_bound(v.begin(), v.end(), 30);

    if (lb != v.end())
        cout << "Lower bound index: " << lb - v.begin() << endl;



    // ===================== 5. upper_bound() =====================
    /*
        upper_bound(start, end, value)

        returns iterator to FIRST element > value
    */
    auto ub = upper_bound(v.begin(), v.end(), 30);

    if (ub != v.end())
        cout << "Upper bound index: " << ub - v.begin() << endl;



    /*
        ===================== IMPORTANT NOTES =====================

        ✔ find(), find_if()
            - work on UNSORTED data
            - linear search (O(n))

        ✔ binary_search(), lower_bound(), upper_bound()
            - REQUIRE SORTED data ⚠️
            - logarithmic (O(log n))

        ✔ Difference:
            binary_search() -> only checks existence
            lower_bound()   -> gives position (>= value)
            upper_bound()   -> gives position (> value)

        ✔ Trick:
            count of element = upper_bound - lower_bound
    */

    return 0;
}