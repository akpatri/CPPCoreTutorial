#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <ranges>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5};

    // ============================================================
    // 🔷 BASIC ITERATORS (begin / end)
    // ============================================================
    auto it = v.begin();     // iterator to first element
    cout << "First element: " << *it << endl;


    // ============================================================
    // 🔷 advance / next / prev
    // ============================================================
    advance(it, 2);          // move iterator forward by 2
    cout << "After advance(2): " << *it << endl;

    auto it2 = next(v.begin(), 3);   // does not modify original
    cout << "next(begin,3): " << *it2 << endl;

    auto it3 = prev(v.end());        // last element
    cout << "prev(end): " << *it3 << endl;


    // ============================================================
    // 🔷 distance
    // ============================================================
    cout << "Distance: " << distance(v.begin(), v.end()) << endl;


    // ============================================================
    // 🔷 REVERSE ITERATOR
    // ============================================================
    cout << "Reverse: ";
    for(auto rit = v.rbegin(); rit != v.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;


    // ============================================================
    // 🔷 INSERT ITERATOR (back_inserter)
    // ============================================================
    vector<int> dest;

    copy(v.begin(), v.end(), back_inserter(dest));
    // automatically pushes elements

    cout << "Copied using back_inserter: ";
    for(int x : dest) cout << x << " ";
    cout << endl;


    // ============================================================
    // 🔷 ITERATOR CATEGORY DIFFERENCE
    // ============================================================
    list<int> lst = {10,20,30};

    auto lit = lst.begin();
    // advance(lit,2); ✔ works
    // lit + 2 ❌ not allowed (no random access)


    // ============================================================
    // 🔷 RANGES (C++20)
    // ============================================================
    /*
    cout << "Ranges for_each: ";
    ranges::for_each(v, [](int x){ cout << x << " "; });
    cout << endl;

    // ranges::advance
    auto rit2 = v.begin();
    ranges::advance(rit2, 4);
    cout << "ranges::advance → " << *rit2 << endl;

    cout << "ranges::distance: "
         << ranges::distance(v) << endl;
    */

    // ============================================================
    // 🔷 DATA / SIZE
    // ============================================================
    cout << "Size: " << size(v) << endl;
    cout << "First via data(): " << *(data(v)) << endl;


    return 0;
}