#include <iostream>     /* for input/output */
#include <vector>       /* for vector */
#include <algorithm>    /* for mutating algorithms */
using namespace std;

/*
    ===================== MUTATING ALGORITHMS =====================

    These algorithms MODIFY original container data

    Common Operations:
    - fill / generate     -> assign values
    - transform           -> modify values
    - replace / remove    -> update/delete values
    - reverse / rotate    -> rearrange
    - swap                -> exchange values

    ===============================================================

    ===================== PARAMETER PATTERN =====================

    algo(start, end, extra...)

    start -> beginning iterator
    end   -> ending iterator (not included)
    extra -> depends on algorithm (value / count / function / position)
*/

int main()
{
    // ================= fill() =================
    /*
        fill(start, end, value)
    */
    vector<int> v1(5);

    fill(v1.begin(), v1.end(), 100);   // set all elements = 100

    cout << "fill(): ";
    for(int x : v1) cout << x << " ";
    cout << "\n\n";



    // ================= fill_n() =================
    /*
        fill_n(start, count, value)
    */
    vector<int> v2 = {1, 2, 3, 4, 5};

    fill_n(v2.begin(), 3, 999);   // first 3 elements = 999

    cout << "fill_n(): ";
    for(int x : v2) cout << x << " ";
    cout << "\n\n";



    // ================= generate() =================
    /*
        generate(start, end, generator_function)
    */
    vector<int> v3(5);
    int n = 1;

    generate(v3.begin(), v3.end(),
    [&n]()
    {
        return n++;   // generate sequence
    });

    cout << "generate(): ";
    for(int x : v3) cout << x << " ";
    cout << "\n\n";



    // ================= generate_n() =================
    /*
        generate_n(start, count, generator_function)
    */
    vector<int> v4(5);
    int x = 10;

    generate_n(v4.begin(), 5,
    [&x]()
    {
        return x += 10;   // generate values
    });

    cout << "generate_n(): ";
    for(int y : v4) cout << y << " ";
    cout << "\n\n";



    // ================= transform() =================
    /*
        transform(start, end, dest, operation)

        dest -> where result is stored (can be same container)
    */
    vector<int> v5 = {1, 2, 3, 4};

    transform(v5.begin(), v5.end(), v5.begin(),
    [](int x)
    {
        return x * 2;   // modify each element
    });

    cout << "transform(): ";
    for(int x : v5) cout << x << " ";
    cout << "\n\n";



    // ================= replace() =================
    /*
        replace(start, end, old_val, new_val)
    */
    vector<int> v6 = {10, 20, 30, 20};

    replace(v6.begin(), v6.end(), 20, 200);

    cout << "replace(): ";
    for(int x : v6) cout << x << " ";
    cout << "\n\n";



    // ================= replace_if() =================
    /*
        replace_if(start, end, condition, new_val)
    */
    replace_if(v6.begin(), v6.end(),
    [](int x)
    {
        return x > 100;   // condition
    }, 999);

    cout << "replace_if(): ";
    for(int x : v6) cout << x << " ";
    cout << "\n\n";



    // ================= remove() =================
    /*
        remove(start, end, value)

        NOTE:
        - does NOT erase elements
        - shifts unwanted values to end
        - use erase() to actually delete
    */
    vector<int> v7 = {10, 20, 30, 20, 40};

    auto newEnd = remove(v7.begin(), v7.end(), 20);  // returns new logical end

    cout << "remove(): ";
    for(int x : v7) cout << x << " ";
    cout << "\n";

    v7.erase(newEnd, v7.end());   // ACTUAL deletion

    cout << "after erase(): ";
    for(int x : v7) cout << x << " ";
    cout << "\n\n";



    // ================= remove_if() =================
    /*
        remove_if(start, end, condition)
    */
    vector<int> v8 = {1, 2, 3, 4, 5, 6};

    auto newEnd2 = remove_if(v8.begin(), v8.end(),
    [](int x)
    {
        return x % 2 == 0;   // remove even numbers
    });

    v8.erase(newEnd2, v8.end());   // actual deletion

    cout << "remove_if(): ";
    for(int x : v8) cout << x << " ";
    cout << "\n\n";



    // ================= reverse() =================
    /*
        reverse(start, end)
    */
    vector<int> v9 = {1, 2, 3, 4, 5};

    reverse(v9.begin(), v9.end());

    cout << "reverse(): ";
    for(int x : v9) cout << x << " ";
    cout << "\n\n";



    // ================= rotate() =================
    /*
        rotate(start, middle, end)

        middle -> new starting position
    */
    vector<int> v10 = {1, 2, 3, 4, 5};

    rotate(v10.begin(), v10.begin() + 2, v10.end());

    cout << "rotate(): ";
    for(int x : v10) cout << x << " ";
    cout << "\n\n";



    // ================= swap() =================
    /*
        swap(a, b)
    */
    int a = 10, b = 20;

    swap(a, b);

    cout << "swap(): " << a << " " << b << "\n\n";



    // ================= swap_ranges() =================
    /*
        swap_ranges(start1, end1, start2)
    */
    vector<int> v11 = {1, 2, 3};
    vector<int> v12 = {10, 20, 30};

    swap_ranges(v11.begin(), v11.end(), v12.begin());

    cout << "swap_ranges() v11: ";
    for(int x : v11) cout << x << " ";
    cout << "\n";

    cout << "swap_ranges() v12: ";
    for(int x : v12) cout << x << " ";
    cout << "\n\n";



    // ================= shuffle =================
    /*
        random_shuffle(start, end)  [deprecated]
        use: shuffle(start, end, generator)
    */
    vector<int> v13 = {1, 2, 3, 4, 5};

    random_shuffle(v13.begin(), v13.end());   // random order

    cout << "random_shuffle(): ";
    for(int x : v13) cout << x << " ";

    return 0;
}