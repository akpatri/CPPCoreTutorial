#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges> // C++20
using namespace std;

// reusable display function

void display(vector<int> v)
{
    for (int x : v)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    // ================= CREATE =================

    vector<int> v = {5, 2, 8, 2, 3, 7, 2};

    // uniform initialization

    vector<int> nums{10, 20, 30};

    cout << "Original vector: ";

    display(v);

    /*
    Output:
    5 2 8 2 3 7 2
    */

    // ============================================================
    // 🔷 NON-MODIFYING OPERATIONS
    // ============================================================

    // count() counts total occurrences

    cout << "\nCount of 2: ";

    cout << count(v.begin(), v.end(), 2) << endl;

    // Output: 3

    // find() searches value

    // returns iterator if found
    // returns v.end() if not found

    vector<int>::iterator it = find(v.begin(), v.end(), 8);

    if (it != v.end())
    {
        cout << "Found 8" << endl;
    }

    // Output: Found 8

    // all_of() checks condition for all elements

    cout << "All > 0: ";

    cout << all_of(
                v.begin(),
                v.end(),
                [](int x)
                {
                    return x > 0;
                })
         << endl;

    // Output: 1

    // any_of() checks condition for at least one element

    cout << "Any > 5: ";

    cout << any_of(
                v.begin(),
                v.end(),
                [](int x)
                {
                    return x > 5;
                })
         << endl;

    // Output: 1

    // none_of() checks no element satisfies condition

    cout << "None < 0: ";

    cout << none_of(
                v.begin(),
                v.end(),
                [](int x)
                {
                    return x < 0;
                })
         << endl;

    // Output: 1

    // ============================================================
    // 🔷 MODIFYING OPERATIONS
    // ============================================================

    // copy() copies elements

    vector<int> v2(v.size());

    copy(v.begin(), v.end(), v2.begin()); //first, last, where

    cout << "\nAfter copy(): ";

    display(v2);

    /*
    Output:
    5 2 8 2 3 7 2
    */

    // move() moves elements

    vector<int> v3(v.size());

    move(v.begin(), v.end(), v3.begin()); //first, last , where_to_store

    cout << "\nAfter move(): ";

    display(v3);

    /*
    Output:
    5 2 8 2 3 7 2
    */

    // swap() swaps two containers

    vector<int> a = {1, 2, 3};

    vector<int> b = {10, 20, 30};

    swap(a, b);

    cout << "\nAfter swap()" << endl;

    cout << "a: ";

    display(a);

    cout << "b: ";

    display(b);

    /*
    Output:
    a: 10 20 30
    b: 1 2 3
    */

    // transform() modifies elements

    transform(
        v3.begin(),
        v3.end(),
        v3.begin(),
        [](int x)
        {
            return x * x;
        });

    cout << "\nAfter transform():" << endl;

    display(v3);

    /*
    Output:
    25 4 64 4 9 49 4
    */

    // replace() replaces old value with new value

    replace(v3.begin(), v3.end(), 4, 100); //between this range, replace all 4 with 100

    cout << "\nAfter replace():" << endl;

    display(v3);

    /*
    Output:
    25 100 64 100 9 49 100
    */

    // remove() performs logical remove

    // does NOT reduce vector size automatically

    vector<int>::iterator newEnd =
        remove(v3.begin(), v3.end(), 100); //remove all occurance of specific element from range

    v3.erase(newEnd, v3.end());

    cout << "\nAfter remove():" << endl;

    display(v3);

    /*
    Output:
    25 64 9 49
    */

    // ============================================================
    // 🔷 SORTING OPERATIONS
    // ============================================================

    // sort() sorts in ascending order

    sort(v3.begin(), v3.end());

    cout << "\nAfter sort():" << endl;

    display(v3);

    /*
    Output:
    9 25 49 64
    */

    // descending sort using comparator

    sort(
        v3.begin(),
        v3.end(),
        greater<int>());

    cout << "\nDescending sort():" << endl;

    display(v3);

    /*
    Output:
    64 49 25 9
    */

    // binary_search() requires sorted container

    sort(v3.begin(), v3.end());

    cout << "\nBinary search 49: ";

    cout << binary_search(
                v3.begin(),
                v3.end(),
                49)
         << endl;

    // Output: 1

    // merge() merges two sorted ranges

    vector<int> m1 = {1, 3, 5};

    vector<int> m2 = {2, 4, 6};

    vector<int> result(6);

    merge(
        m1.begin(),
        m1.end(),
        m2.begin(),
        m2.end(),
        result.begin());

    cout << "\nAfter merge():" << endl;

    display(result);

    /*
    Output:
    1 2 3 4 5 6
    */

    // ============================================================
    // 🔷 PARTITIONING
    // ============================================================

    // partition() places matching condition first

    partition(
        result.begin(),
        result.end(),
        [](int x)
        {
            return x % 2 == 0;
        });

    cout << "\nAfter partition():" << endl;

    display(result);

    /*
    Example Output:
    6 2 4 3 5 1
    */

    // ============================================================
    // 🔷 MIN / MAX
    // ============================================================

    // min_element() returns iterator to minimum element

    cout << "\nMin: ";

    cout << *min_element(
                result.begin(),
                result.end())
         << endl;

    // Output: 1

    // max_element() returns iterator to maximum element

    cout << "Max: ";

    cout << *max_element(
                result.begin(),
                result.end())
         << endl;

    // Output: 6

    // ============================================================
    // 🔷 NUMERIC OPERATIONS
    // ============================================================

    // accumulate() returns sum

    cout << "\nSum: ";

    cout << accumulate(
                result.begin(),
                result.end(),
                0)
         << endl;

    // Output: 21

    // ============================================================
    // 🔷 PERMUTATION
    // ============================================================

    // next_permutation() creates next lexicographical order

    vector<int> p = {1, 2, 3};

    next_permutation(p.begin(), p.end());

    cout << "\nAfter next_permutation():" << endl;

    display(p);

    /*
    Output:
    1 3 2
    */

    // ============================================================
    // 🔷 ITERATOR NOTES
    // ============================================================

    // vector supports random access iterator

    // ++it -> supported
    // --it -> supported

    // it+2 -> supported
    // it-2 -> supported

    // unlike list/set/map

    // ============================================================
    // 🔷 RANGES (C++20)
    // ============================================================

    /*
    vector<int> r = {5, 4, 3, 2, 1};



    // std::ranges::sort()

    std::ranges::sort(r);



    // std::ranges::find()

    auto rit = std::ranges::find(r, 3);

    if (rit != r.end())
    {
        cout << "Found 3 using ranges" << endl;
    }



    // std::ranges::for_each()

    std::ranges::for_each(
        r,
        [](int x)
        {
            cout << x << " ";
        }
    );
    */

    return 0;
}