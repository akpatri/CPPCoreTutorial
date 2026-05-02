#include <iostream>     /* for input/output */
#include <vector>       /* for std::vector */
#include <algorithm>    /* for sorting algorithms */
using namespace std;

/*
    ===================== STL SORTING ALGORITHMS =====================

    1. sort()            -> sorts entire range (ascending by default)
    2. stable_sort()     -> preserves relative order of equal elements
    3. partial_sort()    -> sorts only a part of the range
    4. nth_element()     -> places nth element in correct position

    ================================================================

    ===================== PARAMETER EXPLANATION =====================

    sort(start_iterator, end_iterator)
    sort(start_iterator, end_iterator, comparator)

    - start_iterator : beginning of range (v.begin())
    - end_iterator   : one past last element (v.end())
    - comparator     : optional, defines custom sorting logic

    comparator(a, b):
        return true  -> a should come BEFORE b
        return false -> b should come BEFORE a
*/

int main() {

    vector<int> v = {40, 10, 30, 20, 50};   // unsorted data

    /* ===================== 1. sort() ===================== */
    sort(v.begin(), v.end());
    // parameters:
    // v.begin() -> start of vector
    // v.end()   -> end (not included)
    // default: ascending order

    cout << "Sorted (Ascending): ";
    for (int x : v) cout << x << " ";
    cout << endl;


    /* ===================== sort() with comparator ===================== */
    sort(v.begin(), v.end(), greater<int>());
    // comparator: greater<int>()
    // means: larger elements come first (descending)

    cout << "Sorted (Descending): ";
    for (int x : v) cout << x << " ";
    cout << endl;


    /* ===================== 2. stable_sort() ===================== */
    vector<pair<int,int>> vp = {{1,100}, {2,200}, {1,300}};

    stable_sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first < b.first;
    });
    // sorts based on first value
    // stable_sort keeps original order of equal elements

    cout << "Stable Sort (by first): ";
    for (auto p : vp) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;


    /* ===================== 3. partial_sort() ===================== */
    vector<int> v2 = {9, 4, 7, 1, 3, 6};

    partial_sort(v2.begin(), v2.begin() + 3, v2.end());
    /*
        parameters:
        start          -> v2.begin()
        middle         -> v2.begin()+3 (first 3 elements will be sorted)
        end            -> v2.end()

        result:
        first 3 elements are smallest and sorted
        rest are unspecified order
    */

    cout << "Partial Sort (first 3 smallest): ";
    for (int x : v2) cout << x << " ";
    cout << endl;


    /* ===================== 4. nth_element() ===================== */
    vector<int> v3 = {9, 4, 7, 1, 3, 6};

    nth_element(v3.begin(), v3.begin() + 2, v3.end());
    /*
        parameters:
        start          -> v3.begin()
        nth position   -> v3.begin()+2 (3rd smallest element)
        end            -> v3.end()

        result:
        element at index 2 is correctly placed
        elements before it are smaller (unsorted)
        elements after it are larger (unsorted)
    */

    cout << "nth_element (3rd smallest at index 2): ";
    for (int x : v3) cout << x << " ";
    cout << endl;


    /*
        ===================== IMPORTANT NOTES =====================
        - sort()           -> fastest general purpose (IntroSort)
        - stable_sort()    -> uses MergeSort (extra memory)
        - partial_sort()   -> useful for top-K problems
        - nth_element()    -> O(n), best for kth smallest/largest

        Time Complexity:
        sort()         -> O(n log n)
        stable_sort()  -> O(n log n)
        partial_sort() -> O(n log k)
        nth_element()  -> O(n)
    */

    return 0;   // end program
}