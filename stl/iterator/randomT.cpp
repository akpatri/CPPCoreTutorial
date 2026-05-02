/**
 * ============================================================
 * 🔷 RANDOM ACCESS ITERATOR (C++)
 * ============================================================
 *
 * CONCEPT:
 *   Most powerful iterator.
 *   Can move:
 *     → forward (++it)
 *     ← backward (--it)
 *     → jump any distance (it + n, it - n)
 *     → direct access (it[n])
 *
 * USED IN:
 *   vector, deque, array
 *
 *
 * SYNTAX:
 *   container<int>::iterator it;
 *
 *   it = container.begin();   // start
 *   it = container.end();     // end
 *
 *   ++it;       // next
 *   --it;       // previous
 *   it + n;     // jump forward
 *   it - n;     // jump backward
 *   it[n];      // direct access
 *
 *
 * KEY IDEA:
 *   "Iterator behaves like pointer with full access (like array)"
 *
 * ============================================================
 */

#include <iostream>
#include <vector>   // vector uses random access iterator
using namespace std;

int main() {

    // ============================================================
    // 🔷 1. CREATE CONTAINER
    // ============================================================

    vector<int> v = {10, 20, 30, 40, 50};  
    // vector → supports random access


    // ============================================================
    // 🔷 2. DECLARE ITERATOR
    // ============================================================

    vector<int>::iterator it;  
    // iterator for vector


    // ============================================================
    // 🔷 3. FORWARD TRAVERSAL
    // ============================================================

    cout << "Forward: ";

    for (it = v.begin(); it != v.end(); ++it)  
        cout << *it << " ";

    cout << endl;


    // ============================================================
    // 🔷 4. BACKWARD TRAVERSAL
    // ============================================================

    cout << "Backward: ";

    for (it = v.end() - 1; it >= v.begin(); --it)  
        cout << *it << " ";

    cout << endl;


    // ============================================================
    // 🔷 5. RANDOM JUMP (KEY FEATURE)
    // ============================================================

    it = v.begin();   // points to 10

    it = it + 2;   // jump 2 positions → now at 30
    cout << "Jump +2: " << *it << endl;

    it = it - 1;   // go back → now at 20
    cout << "Jump -1: " << *it << endl;


    // ============================================================
    // 🔷 6. DIRECT ACCESS
    // ============================================================

    it = v.begin();

    cout << "it[3]: " << it[3] << endl;  
    // same as v[3] → 40


    // ============================================================
    // 🔷 7. DISTANCE BETWEEN ITERATORS
    // ============================================================

    auto start = v.begin();
    auto end = v.end();

    cout << "Distance: " << end - start << endl;  
    // number of elements


    return 0;
}