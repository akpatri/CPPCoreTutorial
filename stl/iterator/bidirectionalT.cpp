/**
 * ============================================================
 * 🔷 BIDIRECTIONAL ITERATOR (C++)
 * ============================================================
 *
 * CONCEPT:
 *   An iterator that can move in BOTH directions:
 *     → forward (++it)
 *     ← backward (--it)
 *
 *   Unlike forward iterator (only ++),
 *   this supports going back also.
 *
 * USED IN:
 *   list, set, multiset, map, multimap
 *
 * NOT USED IN:
 *   vector, deque (they use random access iterator)
 *
 *
 * SYNTAX:
 *   container<int>::iterator it;
 *
 *   it = container.begin();   // start
 *   it = container.end();     // end (after last)
 *
 *   ++it;   // move forward
 *   --it;   // move backward
 *
 *
 * KEY IDEA:
 *   "Iterator behaves like a pointer that can go both directions"
 *
 * ============================================================
 */

#include <iostream>
#include <list>     // list uses bidirectional iterator
using namespace std;

int main() {

    // ============================================================
    // 🔷 1. CREATE CONTAINER
    // ============================================================

    list<int> l = {10, 20, 30, 40};   // list supports bidirectional iterator


    // ============================================================
    // 🔷 2. DECLARE ITERATOR
    // ============================================================

    list<int>::iterator it;   // iterator for list


    // ============================================================
    // 🔷 3. FORWARD TRAVERSAL
    // ============================================================

    cout << "Forward: ";

    for (it = l.begin(); it != l.end(); ++it)   // start → end
        cout << *it << " ";   // *it gives value

    cout << endl;


    // ============================================================
    // 🔷 4. BACKWARD TRAVERSAL
    // ============================================================

    cout << "Backward: ";

    it = l.end();   // points AFTER last element

    --it;   // move to last valid element

    for (;; --it) {   // infinite loop, break manually
        cout << *it << " ";

        if (it == l.begin())   // stop when first reached
            break;
    }

    cout << endl;


    // ============================================================
    // 🔷 5. DEMO: MOVING BOTH DIRECTIONS
    // ============================================================

    it = l.begin();   // points to 10

    ++it;   // now at 20
    cout << "After ++ : " << *it << endl;

    --it;   // back to 10
    cout << "After -- : " << *it << endl;


    return 0;
}