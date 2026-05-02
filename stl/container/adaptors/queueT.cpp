/*
queue follows FIFO rule. FIFO = First In First Out
Header file: #include <queue>

Syntax:queue<data_type> queue_name;
Example: queue<int> q;
Important points:
1. Insertion happens at rear
2. Deletion happens from front
3. No direct indexing
4. Works like real life queue
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // ================= CREATE =================
    queue<int> q; // empty queue
    q.push(10);   // push() inserts element at rear
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Elements inserted using push()" << endl;
    /*
    Queue:
    Front -> 10 20 30 40 <- Rear
    */
    cout << endl;

    // ================= READ =================
    cout << "q.front(): " << q.front() << endl; // front() returns first element// Output: q.front(): 10
    cout << "q.back(): " << q.back() << endl;   // back() returns last element // Output: q.back(): 40
    cout << "q.size(): " << q.size() << endl;   // size() returns total elements // Output: q.size(): 4
    cout << "q.empty(): " << q.empty() << endl; // empty() checks queue is empty or not // Output: q.empty(): 0
    cout << endl;

    // ================= UPDATE =================
    // queue does not support direct update using index
    // We can modify front element
    q.front() = 100; // update front element
    cout << "Updated front: " << q.front() << endl;
    // Output: Updated front: 100
    /*
    Queue:
    Front -> 100 20 30 40 <- Rear
    */
    cout << endl;

    // ================= DELETE =================
    q.pop(); // pop() removes front element
    cout << "After pop(), new front: " << q.front() << endl;
    // Output: After pop(), new front: 20
    /*
    Queue:
    Front -> 20 30 40 <- Rear
    */
    cout << endl;

    // ================= TRAVERSING =================
    queue<int> temp = q; // copy queue because original queue changes during traversal
    cout << "Queue elements: ";

    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    } // Output: 20 30 40
    cout << endl
         << endl;

    // ================= CLEAR QUEUE =================
    while (!q.empty()) // remove all elements
    {
        q.pop();
    }
    cout << "q.empty(): " << q.empty() << endl; // Output: q.empty(): 1

    return 0;
}