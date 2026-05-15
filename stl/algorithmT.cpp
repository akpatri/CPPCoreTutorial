/*
========================================================
            STL ALGORITHMS IN C++
========================================================

Definition:
- STL algorithms are ready-made functions provided by C++
- Used for searching, sorting, modifying, counting,
  partitioning, numeric operations, etc.

Header Files:
    #include <algorithm>
    #include <numeric>
    #include <ranges>   // C++20

Important Points:
1. Works using iterators
2. Reduces manual coding
3. Optimized and reusable
4. Most algorithms work on ranges:
       [begin, end)
5. end() points after last element

========================================================
                    MAIN CATEGORIES
========================================================

1. Non-Modifying Algorithms
   - count()
   - find()
   - all_of()
   - any_of()
   - none_of()

2. Modifying Algorithms
   - copy()
   - move()
   - swap()
   - transform()
   - replace()
   - remove()

3. Sorting Algorithms
   - sort()
   - binary_search()
   - merge()

4. Partitioning Algorithms
   - partition()

5. Min / Max Algorithms
   - min_element()
   - max_element()

6. Numeric Algorithms
   - accumulate()

7. Permutation Algorithms
   - next_permutation()

========================================================
                ITERATOR REQUIREMENTS
========================================================

sort()              -> Random access iterator
binary_search()     -> Sorted range required
merge()             -> Both ranges must be sorted
partition()         -> Forward iterator

========================================================
                TIME COMPLEXITY
========================================================

count()             -> O(n)
find()              -> O(n)
sort()              -> O(n log n)
binary_search()     -> O(log n)
replace()           -> O(n)
remove()            -> O(n)
accumulate()        -> O(n)
min_element()       -> O(n)
max_element()       -> O(n)

========================================================
                IMPORTANT NOTES
========================================================

1. remove() does NOT reduce container size
   Use erase() after remove()

2. binary_search() works only on sorted data

3. move() transfers resources instead of copying

4. transform() modifies data using function/lambda

5. partition() does NOT maintain order

========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges> // C++20
using namespace std;

// ================= DISPLAY FUNCTION =================

void display(vector<int> v)
{
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
}

// ================= NON-MODIFYING OPERATIONS =================

void nonModifyingDemo()
{
    cout << "================ NON-MODIFYING =================\n"
         << endl;

    vector<int> v = {5, 2, 8, 2, 3, 7, 2};

    cout << "Original vector: ";

    display(v);

    /*
    Output:
    5 2 8 2 3 7 2
    */

    // count()

    cout << "\nCount of 2: ";

    cout << count(v.begin(), v.end(), 2) << endl;

    /*
    Output:
    3
    */

    // find()

    vector<int>::iterator it;

    it = find(v.begin(), v.end(), 8);

    if (it != v.end())
    {
        cout << "Found 8" << endl;
    }

    /*
    Output:
    Found 8
    */

    // all_of()

    cout << "All > 0: ";

    cout << all_of(
                v.begin(),
                v.end(),
                [](int x)
                {
                    return x > 0;
                })
         << endl;

    /*
    Output:
    1
    */

    // any_of()

    cout << "Any > 5: ";

    cout << any_of(
                v.begin(),
                v.end(),
                [](int x)
                {
                    return x > 5;
                })
         << endl;

    /*
    Output:
    1
    */

    // none_of()

    cout << "None < 0: ";

    cout << none_of(
                v.begin(),
                v.end(),
                [](int x)
                {
                    return x < 0;
                })
         << endl;

    /*
    Output:
    1
    */

    cout << endl;
}

// ================= MODIFYING OPERATIONS =================

void modifyingDemo()
{
    cout << "================ MODIFYING =================\n"
         << endl;

    vector<int> v = {5, 2, 8, 2, 3, 7, 2};

    // copy()

    vector<int> v2(v.size());

    copy(v.begin(), v.end(), v2.begin());

    cout << "After copy(): ";

    display(v2);

    /*
    Output:
    5 2 8 2 3 7 2
    */

    cout << endl;

    // move()

    vector<int> v3(v.size());

    move(v.begin(), v.end(), v3.begin());

    cout << "After move(): ";

    display(v3);

    /*
    Output:
    5 2 8 2 3 7 2
    */

    cout << endl;

    // swap()

    vector<int> a = {1, 2, 3};

    vector<int> b = {10, 20, 30};

    swap(a, b);

    cout << "After swap()" << endl;

    cout << "a: ";

    display(a);

    cout << "b: ";

    display(b);

    /*
    Output:
    a: 10 20 30
    b: 1 2 3
    */

    cout << endl;

    // transform()

    transform(
        v3.begin(),
        v3.end(),
        v3.begin(),
        [](int x)
        {
            return x * x;
        });

    cout << "After transform(): ";

    display(v3);

    /*
    Output:
    25 4 64 4 9 49 4
    */

    cout << endl;

    // replace()

    replace(v3.begin(), v3.end(), 4, 100);

    cout << "After replace(): ";

    display(v3);

    /*
    Output:
    25 100 64 100 9 49 100
    */

    cout << endl;

    // remove()

    vector<int>::iterator newEnd;

    newEnd = remove(v3.begin(), v3.end(), 100);

    v3.erase(newEnd, v3.end());

    cout << "After remove(): ";

    display(v3);

    /*
    Output:
    25 64 9 49
    */

    cout << endl;
}

// ================= SORTING OPERATIONS =================

void sortingDemo()
{
    cout << "================ SORTING =================\n"
         << endl;

    vector<int> v = {25, 64, 9, 49};

    // sort()

    sort(v.begin(), v.end());

    cout << "Ascending sort(): ";

    display(v);

    /*
    Output:
    9 25 49 64
    */

    cout << endl;

    // descending sort

    sort(v.begin(), v.end(), greater<int>());

    cout << "Descending sort(): ";

    display(v);

    /*
    Output:
    64 49 25 9
    */

    cout << endl;

    // binary_search()

    sort(v.begin(), v.end());

    cout << "Binary search 49: ";

    cout << binary_search(
                v.begin(),
                v.end(),
                49)
         << endl;

    /*
    Output:
    1
    */

    cout << endl;

    // merge()

    vector<int> m1 = {1, 3, 5};

    vector<int> m2 = {2, 4, 6};

    vector<int> result(6);

    merge(
        m1.begin(),
        m1.end(),
        m2.begin(),
        m2.end(),
        result.begin());

    cout << "After merge(): ";

    display(result);

    /*
    Output:
    1 2 3 4 5 6
    */

    cout << endl;
}

// ================= PARTITIONING =================

void partitionDemo()
{
    cout << "================ PARTITION =================\n"
         << endl;

    vector<int> result = {1, 2, 3, 4, 5, 6};

    partition(
        result.begin(),
        result.end(),
        [](int x)
        {
            return x % 2 == 0;
        });

    cout << "After partition(): ";

    display(result);

    /*
    Example Output:
    6 2 4 3 5 1
    */

    cout << endl;
}

// ================= MIN / MAX =================

void minMaxDemo()
{
    cout << "================ MIN / MAX =================\n"
         << endl;

    vector<int> result = {6, 2, 4, 3, 5, 1};

    // min_element()

    cout << "Min: ";

    cout << *min_element(
                result.begin(),
                result.end())
         << endl;

    /*
    Output:
    1
    */

    // max_element()

    cout << "Max: ";

    cout << *max_element(
                result.begin(),
                result.end())
         << endl;

    /*
    Output:
    6
    */

    cout << endl;
}

// ================= NUMERIC OPERATIONS =================

void numericDemo()
{
    cout << "================ NUMERIC =================\n"
         << endl;

    vector<int> result = {1, 2, 3, 4, 5, 6};

    // accumulate()

    cout << "Sum: ";

    cout << accumulate(
                result.begin(),
                result.end(),
                0)
         << endl;

    /*
    Output:
    21
    */

    cout << endl;
}

// ================= PERMUTATION =================

void permutationDemo()
{
    cout << "================ PERMUTATION =================\n"
         << endl;

    vector<int> p = {1, 2, 3};

    next_permutation(p.begin(), p.end());

    cout << "After next_permutation(): ";

    display(p);

    /*
    Output:
    1 3 2
    */

    cout << endl;
}

// ================= ITERATOR NOTES =================

void iteratorDemo()
{
    cout << "================ ITERATOR NOTES =================\n"
         << endl;

    /*
    Vector supports random access iterator

    ++it -> supported
    --it -> supported
    it+2 -> supported
    it-2 -> supported
    */

    vector<int> v = {10, 20, 30, 40};

    vector<int>::iterator it;

    it = v.begin();

    cout << "First value: " << *it << endl;

    ++it;

    cout << "Second value: " << *it << endl;

    it = it + 2;

    cout << "Fourth value: " << *it << endl;

    cout << endl;
}

// ================= MAIN FUNCTION =================

int main()
{
    nonModifyingDemo();

    modifyingDemo();

    sortingDemo();

    partitionDemo();

    minMaxDemo();

    numericDemo();

    permutationDemo();

    iteratorDemo();

    return 0;
}