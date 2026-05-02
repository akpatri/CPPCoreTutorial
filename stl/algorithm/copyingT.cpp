#include <iostream>     /* for I/O */
#include <vector>       /* for vector */
#include <algorithm>    /* for STL copy algorithms */
using namespace std;

/*
    ===================== COPY FAMILY (STL) =====================

    General Syntax Pattern:
    algorithm(start, end, destination, extra params...)

    start       -> beginning iterator (source)
    end         -> ending iterator (source, not included)
    destination -> where result will be stored
    extra       -> depends on algorithm (count / value / condition)

    ============================================================
*/

int main()
{
    vector<int> v1 = {10, 20, 30, 40};   // source container



    // ================= copy() =================
    /*
        copy(start, end, dest)

        start -> v1.begin()
        end   -> v1.end()
        dest  -> v2.begin()

        copies ALL elements from source → destination
    */
    vector<int> v2(4);   // destination must have enough size

    copy(v1.begin(), v1.end(), v2.begin());   // full copy

    cout << "copy(): ";
    for(int x : v2) cout << x << " ";
    cout << "\n\n";



    // ================= copy_n() =================
    /*
        copy_n(start, count, dest)

        start -> where to start
        count -> number of elements
        dest  -> destination start
    */
    vector<int> v3(2);

    copy_n(v1.begin(), 2, v3.begin());   // copy first 2 elements

    cout << "copy_n(): ";
    for(int x : v3) cout << x << " ";
    cout << "\n\n";



    // ================= copy_if() =================
    /*
        copy_if(start, end, dest, condition)

        condition(x) -> if true, element is copied
    */
    vector<int> v4;

    copy_if(v1.begin(), v1.end(), back_inserter(v4),   // auto push_back
    [](int x)
    {
        return x > 20;   // condition
    });

    cout << "copy_if(): ";
    for(int x : v4) cout << x << " ";
    cout << "\n\n";



    // ================= copy_backward() =================
    /*
        copy_backward(start, end, dest_end)

        dest_end -> END of destination (reverse filling)
        useful when ranges overlap
    */
    vector<int> v5 = {1, 2, 3, 4, 5, 6};

    copy_backward(v1.begin(), v1.end(), v5.end());  // fill from back

    cout << "copy_backward(): ";
    for(int x : v5) cout << x << " ";
    cout << "\n\n";



    // ================= move() =================
    /*
        move(start, end, dest)

        moves elements instead of copying
        source elements become "empty/valid but unspecified"
    */
    vector<string> names1 = {"Ali", "John", "Sam"};
    vector<string> names2(3);

    move(names1.begin(), names1.end(), names2.begin());  // move data

    cout << "move(): ";
    for(string x : names2) cout << x << " ";
    cout << "\n\n";



    // ================= move_backward() =================
    /*
        move_backward(start, end, dest_end)

        same as copy_backward but moves instead of copies
    */
    vector<int> v6 = {1, 2, 3, 4, 5, 6};

    move_backward(v1.begin(), v1.end(), v6.end());

    cout << "move_backward(): ";
    for(int x : v6) cout << x << " ";
    cout << "\n\n";



    // ================= reverse_copy() =================
    /*
        reverse_copy(start, end, dest)

        copies elements in reverse order
    */
    vector<int> v7(4);

    reverse_copy(v1.begin(), v1.end(), v7.begin());

    cout << "reverse_copy(): ";
    for(int x : v7) cout << x << " ";
    cout << "\n\n";



    // ================= replace_copy() =================
    /*
        replace_copy(start, end, dest, old_val, new_val)

        replaces old_val with new_val WHILE copying
    */
    vector<int> v8(4);

    replace_copy(v1.begin(), v1.end(), v8.begin(), 20, 200);

    cout << "replace_copy(): ";
    for(int x : v8) cout << x << " ";
    cout << "\n\n";



    // ================= replace_copy_if() =================
    /*
        replace_copy_if(start, end, dest, condition, new_val)

        replaces elements satisfying condition
    */
    vector<int> v9(4);

    replace_copy_if(v1.begin(), v1.end(), v9.begin(),
    [](int x)
    {
        return x > 20;   // condition
    }, 999);

    cout << "replace_copy_if(): ";
    for(int x : v9) cout << x << " ";
    cout << "\n\n";



    // ================= remove_copy() =================
    /*
        remove_copy(start, end, dest, value)

        copies everything EXCEPT given value
    */
    vector<int> v10;

    remove_copy(v1.begin(), v1.end(), back_inserter(v10), 20);

    cout << "remove_copy(): ";
    for(int x : v10) cout << x << " ";
    cout << "\n\n";



    // ================= remove_copy_if() =================
    /*
        remove_copy_if(start, end, dest, condition)

        removes elements satisfying condition
    */
    vector<int> v11;

    remove_copy_if(v1.begin(), v1.end(), back_inserter(v11),
    [](int x)
    {
        return x > 20;
    });

    cout << "remove_copy_if(): ";
    for(int x : v11) cout << x << " ";
    cout << "\n\n";



    // ================= unique_copy() =================
    /*
        unique_copy(start, end, dest)

        copies only UNIQUE CONSECUTIVE elements
        (important: works on consecutive duplicates only)
    */
    vector<int> nums = {10, 10, 20, 20, 30, 30};
    vector<int> v12;

    unique_copy(nums.begin(), nums.end(), back_inserter(v12));

    cout << "unique_copy(): ";
    for(int x : v12) cout << x << " ";

    return 0;
}