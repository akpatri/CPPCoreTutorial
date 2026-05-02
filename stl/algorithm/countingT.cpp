#include <iostream>     /* for input/output */
#include <vector>       /* for vector container */
#include <algorithm>    /* for count algorithms */
using namespace std;

/*
    ===================== COUNTING ALGORITHMS =====================

    1. count()     -> counts exact value
    2. count_if()  -> counts based on condition (predicate)

    ===============================================================

    ===================== PARAMETER EXPLANATION =====================

    count(start, end, value)

        start -> beginning iterator
        end   -> ending iterator (not included)
        value -> value to count

    count_if(start, end, condition)

        condition(x) -> returns true if element should be counted
*/

int main()
{
    vector<int> v = {10, 20, 10, 30, 40, 10, 50};   // sample data



    // ================= count() =================
    /*
        counts how many times VALUE appears
    */
    int total10 = count(v.begin(), v.end(), 10);
    // v.begin() -> start
    // v.end()   -> end
    // 10        -> value to count

    cout << "count(10): " << total10 << endl;
    cout << endl;



    // ================= count_if() =================
    /*
        counts elements satisfying condition
    */
    int greaterThan20 = count_if(v.begin(), v.end(),
    [](int x)
    {
        return x > 20;   // condition: count numbers > 20
    });

    cout << "count_if(x > 20): " << greaterThan20 << endl;
    cout << endl;



    // ================= count even numbers =================
    /*
        condition: x % 2 == 0  → even numbers
    */
    int evenCount = count_if(v.begin(), v.end(),
    [](int x)
    {
        return x % 2 == 0;   // even check
    });

    cout << "Even numbers: " << evenCount << endl;
    cout << endl;



    // ================= count odd numbers =================
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    int oddCount = count_if(nums.begin(), nums.end(),
    [](int x)
    {
        return x % 2 != 0;   // odd check
    });

    cout << "Odd numbers: " << oddCount << endl;
    cout << endl;



    // ================= count vowels =================
    /*
        string also supports iterators
    */
    string str = "education";

    int vowelCount = count_if(str.begin(), str.end(),
    [](char ch)
    {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        // condition: check vowel
    });

    cout << "Vowels: " << vowelCount << endl;
    cout << endl;



    // ================= count negative numbers =================
    vector<int> arr = {-10, 20, -5, 30, -1};

    int negativeCount = count_if(arr.begin(), arr.end(),
    [](int x)
    {
        return x < 0;   // condition: negative values
    });

    cout << "Negative numbers: " << negativeCount << endl;



    /*
        ===================== IMPORTANT NOTES =====================
        - count()       -> checks equality
        - count_if()    -> uses condition (flexible)

        Time Complexity:
        count()      -> O(n)
        count_if()   -> O(n)

        Tip:
        - Use count_if() when logic is involved
        - Works with any container (vector, string, array, etc.)
    */

    return 0;
}