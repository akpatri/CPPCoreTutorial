#include <iostream>     /* for input/output */
#include <vector>       /* for vector */
#include <algorithm>    /* for non-mutating algorithms */
using namespace std;

/*
    ===================== NON-MUTATING ALGORITHMS =====================

    These algorithms DO NOT modify original data

    Used for:
    - searching
    - counting
    - checking conditions
    - comparing ranges

    ================================================================

    ===================== PARAMETER PATTERN =====================

    algo(start, end, extra...)

    start -> beginning iterator
    end   -> ending iterator (not included)
    extra -> value / condition / second range
*/

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};



    // ================= find() =================
    /*
        find(start, end, value)

        returns iterator to found element
    */
    auto it1 = find(v.begin(), v.end(), 30);

    if(it1 != v.end())   // check if found
        cout << "30 found\n";

    cout << "\n";



    // ================= find_if() =================
    /*
        find_if(start, end, condition)
    */
    auto it2 = find_if(v.begin(), v.end(),
    [](int x)
    {
        return x > 25;   // condition
    });

    if(it2 != v.end())
        cout << "find_if(): " << *it2 << endl;

    cout << "\n";



    // ================= find_if_not() =================
    /*
        find_if_not(start, end, condition)
    */
    auto it3 = find_if_not(v.begin(), v.end(),
    [](int x)
    {
        return x < 25;
    });

    if(it3 != v.end())
        cout << "find_if_not(): " << *it3 << endl;

    cout << "\n";



    // ================= count() =================
    /*
        count(start, end, value)
    */
    int total = count(v.begin(), v.end(), 20);

    cout << "count(20): " << total << endl;

    cout << "\n";



    // ================= count_if() =================
    /*
        count_if(start, end, condition)
    */
    int evenCount = count_if(v.begin(), v.end(),
    [](int x)
    {
        return x % 2 == 0;
    });

    cout << "count_if(): " << evenCount << endl;

    cout << "\n";



    // ================= all_of() =================
    /*
        all_of(start, end, condition)

        returns true if ALL satisfy condition
    */
    bool allPositive = all_of(v.begin(), v.end(),
    [](int x)
    {
        return x > 0;
    });

    cout << "all_of(): " << allPositive << endl;

    cout << "\n";



    // ================= any_of() =================
    /*
        any_of(start, end, condition)

        returns true if ANY satisfy condition
    */
    bool anyGreater = any_of(v.begin(), v.end(),
    [](int x)
    {
        return x > 45;
    });

    cout << "any_of(): " << anyGreater << endl;

    cout << "\n";



    // ================= none_of() =================
    /*
        none_of(start, end, condition)

        returns true if NONE satisfy condition
    */
    bool noneNegative = none_of(v.begin(), v.end(),
    [](int x)
    {
        return x < 0;
    });

    cout << "none_of(): " << noneNegative << endl;

    cout << "\n";



    // ================= adjacent_find() =================
    /*
        adjacent_find(start, end)

        finds first consecutive duplicate
    */
    vector<int> nums = {1, 2, 2, 3, 4};

    auto it4 = adjacent_find(nums.begin(), nums.end());

    if(it4 != nums.end())
        cout << "adjacent_find(): " << *it4 << endl;

    cout << "\n";



    // ================= search() =================
    /*
        search(start1, end1, start2, end2)

        finds subrange inside range
    */
    vector<int> pattern = {30, 40};

    auto it5 = search(v.begin(), v.end(),
                      pattern.begin(), pattern.end());

    if(it5 != v.end())
        cout << "search(): " << *it5 << endl;

    cout << "\n";



    // ================= search_n() =================
    /*
        search_n(start, end, count, value)

        finds 'count' consecutive occurrences of value
    */
    vector<int> arr = {1, 2, 5, 5, 5, 6};

    auto it6 = search_n(arr.begin(), arr.end(), 3, 5);

    if(it6 != arr.end())
        cout << "search_n(): " << *it6 << endl;

    cout << "\n";



    // ================= equal() =================
    /*
        equal(start1, end1, start2)

        compares two ranges
    */
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};

    bool same = equal(a.begin(), a.end(), b.begin());

    cout << "equal(): " << same << endl;

    cout << "\n";



    // ================= mismatch() =================
    /*
        mismatch(start1, end1, start2)

        returns pair of iterators (first mismatch)
    */
    vector<int> x = {1, 2, 3};
    vector<int> y = {1, 5, 3};

    auto p = mismatch(x.begin(), x.end(), y.begin());

    cout << "mismatch(): " << *p.first << " " << *p.second << endl;

    cout << "\n";



    // ================= lexicographical_compare() =================
    /*
        lexicographical_compare(start1, end1, start2, end2)

        compares like dictionary order
    */
    vector<int> c1 = {1, 2, 3};
    vector<int> c2 = {1, 2, 4};

    bool result = lexicographical_compare(
        c1.begin(), c1.end(),
        c2.begin(), c2.end()
    );

    cout << "lexicographical_compare(): " << result << endl;



    /*
        ===================== IMPORTANT NOTES =====================
        - These algorithms NEVER modify data
        - Always check iterator != end() before dereferencing
        - Return types:
            iterator -> find, search
            bool     -> all_of, any_of, equal
            int      -> count
            pair     -> mismatch
    */

    return 0;
}