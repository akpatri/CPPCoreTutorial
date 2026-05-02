/**
 * ============================================================
 * 🔷 OUTPUT ITERATOR (C++)
 * ============================================================
 *
 * CONCEPT:
 *   An iterator used ONLY for writing data (output).
 *
 *   It can:
 *     → move forward (++it)
 *     → write value (*it = value)
 *
 *   It CANNOT:
 *     ❌ read value (*it for reading not allowed)
 *     ❌ move backward (--it)
 *
 *
 * USED IN:
 *   ostream_iterator (output stream)
 *   back_insert_iterator, front_insert_iterator
 *
 *
 * SYNTAX:
 *   ostream_iterator<int> it(cout, " ");
 *
 *   *it = value;   // write
 *   ++it;          // move forward
 *
 *
 * KEY IDEA:
 *   "Writes data sequentially, one direction only"
 *
 * ============================================================
 */

#include <iostream>
#include <iterator>   // for ostream_iterator
#include <vector>
using namespace std;

int main() {

    // ============================================================
    // 🔷 1. OUTPUT TO SCREEN (ostream_iterator)
    // ============================================================

    /**
     * ostream_iterator<int> out(cout, " ")
     * Params:
     *   cout → output destination
     *   " "  → separator after each value
     */
    ostream_iterator<int> out(cout, " ");

    cout << "Output: ";

    *out = 10;   // write value to cout
    ++out;       // move forward

    *out = 20;
    ++out;

    *out = 30;
    ++out;

    cout << endl;


    // ============================================================
    // 🔷 2. OUTPUT TO CONTAINER (back_insert_iterator)
    // ============================================================

    vector<int> v;

    /**
     * back_inserter(container)
     *   returns output iterator
     *   inserts at end (push_back)
     */
    auto it = back_inserter(v);

    *it = 100;   // v.push_back(100)
    *it = 200;   // v.push_back(200)
    *it = 300;

    cout << "Vector: ";
    for (int x : v)
        cout << x << " ";

    cout << endl;


    // ============================================================
    // 🔷 3. IMPORTANT LIMITATIONS
    // ============================================================

    /**
     * ❌ Cannot read (*it)
     * ❌ Cannot go backward
     * ❌ Only write sequentially
     */


    return 0;
}