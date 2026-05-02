/**
 * ============================================================
 * 🔷 FORWARD ITERATOR (C++)
 * ============================================================
 *
 * CONCEPT:
 *   An iterator that can move ONLY in ONE direction:
 *     → forward (++it)
 *
 *   It CANNOT move backward (--it ❌)
 *
 * USED IN:
 *   forward_list, unordered_set, unordered_map
 *
 * ALSO SUPPORTED BY:
 *   vector, list, deque (but they have more powerful iterators)
 *
 *
 * SYNTAX:
 *   container<int>::iterator it;
 *
 *   it = container.begin();   // start
 *   it = container.end();     // end (after last)
 *
 *   ++it;   // move forward only
 *
 *
 * KEY IDEA:
 *   "Iterator behaves like a pointer that can move only forward"
 *
 * ============================================================
 */

#include <iostream>
#include <forward_list>   // uses forward iterator
using namespace std;

int main() {

    // ============================================================
    // 🔷 1. CREATE CONTAINER
    // ============================================================

    forward_list<int> fl = {10, 20, 30, 40};  
    // singly linked list → only forward traversal possible


    // ============================================================
    // 🔷 2. DECLARE ITERATOR
    // ============================================================

    forward_list<int>::iterator it;  
    // iterator for forward_list


    // ============================================================
    // 🔷 3. FORWARD TRAVERSAL
    // ============================================================

    cout << "Forward: ";

    for (it = fl.begin(); it != fl.end(); ++it)  
        cout << *it << " ";   // access value

    cout << endl;


    // ============================================================
    // 🔷 4. DEMO: ONLY FORWARD MOVEMENT
    // ============================================================

    it = fl.begin();   // points to first element (10)

    cout << "Start: " << *it << endl;

    ++it;   // move forward to 20
    cout << "After ++ : " << *it << endl;

    ++it;   // move forward to 30
    cout << "After ++ : " << *it << endl;


    // ❌ BACKWARD NOT ALLOWED
    // --it;   // ERROR → forward iterator does not support this


    // ============================================================
    // 🔷 5. INSERT AFTER (special behavior)
    // ============================================================

    /**
     * forward_list does NOT support insert before
     * only insert AFTER a position
     */

    it = fl.begin();   // at 10

    fl.insert_after(it, 15);  
    // insert 15 AFTER 10


    cout << "After insert: ";

    for (auto x : fl)   // range loop
        cout << x << " ";

    cout << endl;


    return 0;
}