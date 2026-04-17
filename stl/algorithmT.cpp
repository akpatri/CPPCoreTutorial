#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>   // C++20
using namespace std;

int main()
{
    vector<int> v = {5, 2, 8, 2, 3, 7, 2};

    // ============================================================
    // 🔷 NON-MODIFYING OPERATIONS
    // ============================================================

    // count
    cout << "Count of 2: " << count(v.begin(), v.end(), 2) << endl;

    // find
    auto it = find(v.begin(), v.end(), 8);
    if(it != v.end()) cout << "Found 8\n";

    // all_of / any_of
    cout << "All >0: " << all_of(v.begin(), v.end(), [](int x){ return x > 0; }) << endl;
    cout << "Any >5: " << any_of(v.begin(), v.end(), [](int x){ return x > 5; }) << endl;


    // ============================================================
    // 🔷 MODIFYING OPERATIONS
    // ============================================================

    vector<int> v2(v.size());

    // copy
    copy(v.begin(), v.end(), v2.begin());

    // transform (square each element)
    transform(v.begin(), v.end(), v.begin(), [](int x){ return x * x; });

    // remove (logical remove, doesn't shrink container)
    auto newEnd = remove(v.begin(), v.end(), 4);
    v.erase(newEnd, v.end());


    // ============================================================
    // 🔷 SORTING OPERATIONS
    // ============================================================

    sort(v.begin(), v.end());   // ascending
    cout << "Sorted: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // binary_search (requires sorted)
    cout << "Binary search 9: " << binary_search(v.begin(), v.end(), 9) << endl;


    // ============================================================
    // 🔷 PARTITIONING
    // ============================================================

    partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

    cout << "Partitioned (even first): ";
    for(int x : v) cout << x << " ";
    cout << endl;


    // ============================================================
    // 🔷 MIN/MAX
    // ============================================================

    cout << "Min: " << *min_element(v.begin(), v.end()) << endl;
    cout << "Max: " << *max_element(v.begin(), v.end()) << endl;


    // ============================================================
    // 🔷 PERMUTATION
    // ============================================================

    next_permutation(v.begin(), v.end());
    cout << "Next permutation: ";
    for(int x : v) cout << x << " ";
    cout << endl;


    // ============================================================
    // 🔷 RANGES (C++20)
    // cleaner syntax (no iterators)
    // ============================================================

    /*
    vector<int> r = {1,2,3,4,5};

    // std::ranges::sort
    std::ranges::sort(r);

    // std::ranges::find
    auto rit = std::ranges::find(r, 3);
    if(rit != r.end()) cout << "Found 3 using ranges\n";

    // std::ranges::for_each
    cout << "Ranges for_each: ";
    std::ranges::for_each(r, [](int x){ cout << x << " "; });
    cout << endl;
    */

    return 0;
}