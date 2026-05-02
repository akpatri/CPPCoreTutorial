/**
 * ============================================================
 * 🔷 INPUT ITERATOR (C++)
 * ============================================================
 *
 * CONCEPT:
 *   An iterator used ONLY for reading data (input).
 *
 *   It can:
 *     → move forward (++it)
 *     → read value (*it)
 *
 *   It CANNOT:
 *     ❌ move backward (--it)
 *     ❌ write/modify data
 *
 *
 * USED IN:
 *   istream_iterator (input stream)
 *
 *
 * SYNTAX:
 *   istream_iterator<int> it(cin);
 *   istream_iterator<int> end;
 *
 *   *it     → read value
 *   ++it    → move to next input
 *
 *
 * KEY IDEA:
 *   "Reads data like a stream, one direction only"
 *
 * ============================================================
 */

#include <iostream>
#include <iterator>   // for istream_iterator
using namespace std;

int main() {

    // ============================================================
    // 🔷 1. DECLARE INPUT ITERATOR
    // ============================================================

    /**
     * istream_iterator<int> it(cin)
     * Param:
     *   cin → input source
     */
    istream_iterator<int> it(cin);  

    /**
     * end iterator → represents end of input
     */
    istream_iterator<int> end;


    // ============================================================
    // 🔷 2. READ INPUT USING ITERATOR
    // ============================================================

    cout << "Enter numbers (Ctrl+D to stop): ";

    while (it != end) {   // until input ends
        cout << "Read: " << *it << endl;   // *it → current value
        ++it;   // move to next input
    }


    // ============================================================
    // 🔷 3. IMPORTANT LIMITATIONS
    // ============================================================

    /**
     * ❌ Cannot go backward
     * ❌ Cannot access random position
     * ❌ Single-pass only (once read, gone)
     */


    return 0;
}