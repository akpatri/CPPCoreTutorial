/*
deque means double ended queue
Insertion and deletion can happen from both ends
Header file: #include <deque>
Syntax: deque<data_type> deque_name;
Example: deque<int> dq;
Important points:
1. Dynamic size
2. Fast insertion and deletion from both ends
3. Supports indexing
4. Combination of vector and queue features
*/

#include <iostream>
#include <deque>
using namespace std;
int main()
{
    // ================= CREATE =================
    deque<int> dq; // empty deque
    dq.push_back(10); // push_back() inserts at end
    dq.push_back(20);
    dq.push_front(5); // push_front() inserts at beginning
    dq.push_front(1);
    cout << "Deque elements: ";
    for(int x : dq)
    {
        cout << x << " ";
    } // Output: 1 5 10 20
    cout << endl << endl;

    // ================= READ =================
    cout << "dq[1]: " << dq[1] << endl; // [] accesses element using index // Output: dq[1]: 5
    cout << "dq.at(2): " << dq.at(2) << endl; // at() safely accesses element // Output: dq.at(2): 10
    cout << "dq.front(): " << dq.front() << endl; // front() returns first element // Output: dq.front(): 1
    cout << "dq.back(): " << dq.back() << endl; // back() returns last element // Output: dq.back(): 20
    cout << "dq.size(): " << dq.size() << endl; // size() returns total elements // Output: dq.size(): 4
    cout << "dq.empty(): " << dq.empty() << endl; // empty() checks deque is empty or not // Output: dq.empty(): 0
    cout << endl;

    // ================= UPDATE =================
    dq[1] = 500; // update value using index
    cout << "After update: ";
    for(int x : dq)
    {
        cout << x << " ";
    } // Output: 1 500 10 20
    cout << endl << endl;

    // insert() inserts element at specific position
    dq.insert(dq.begin() + 2, 99);
    cout << "After insert(): ";
    for(int x : dq)
    {
        cout << x << " ";
    } // Output: 1 500 99 10 20
    cout << endl << endl;

    // ================= DELETE =================
    dq.pop_front(); // pop_front() removes first element
    cout << "After pop_front(): ";
    for(int x : dq)
    {
        cout << x << " ";
    } // Output: 500 99 10 20
    cout << endl << endl;
    dq.pop_back(); // pop_back() removes last element
    cout << "After pop_back(): ";
    for(int x : dq)
    {
        cout << x << " ";
    } // Output: 500 99 10
    cout << endl << endl;
    dq.erase(dq.begin() + 1); // erase() removes element from specific position
    cout << "After erase(): ";
    for(int x : dq)
    {
        cout << x << " ";
    } // Output: 500 10
    cout << endl << endl;
    dq.clear(); // clear() removes all elements
    cout << "dq.empty(): " << dq.empty() << endl; // Output: dq.empty(): 1

    return 0;
}