/*
stack follows LIFO rule. LIFO = Last In First Out
Header file: #include <stack>
Syntax: stack<data_type> stack_name;
Example: stack<int> st;
Important points:
1. Insertion and deletion happen from top
2. No direct indexing
3. Last inserted element comes out first
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // ================= CREATE =================
    stack<int> st; // empty stack
    st.push(10);   // push() inserts element at top
    st.push(20);
    st.push(30);
    st.push(40);
    cout << "Elements inserted using push()" << endl;
    /*
    Stack:
        40  <- Top
        30
        20
        10
    */
    cout << endl;

    // ================= READ =================
    cout << "st.top(): " << st.top() << endl;     // top() returns top element // Output: st.top(): 40
    cout << "st.size(): " << st.size() << endl;   // size() returns total elements // Output: st.size(): 4
    cout << "st.empty(): " << st.empty() << endl; // empty() checks stack is empty or not // Output: st.empty(): 0
    cout << endl;

    // ================= UPDATE =================
    st.top() = 100;                              // update top element
    cout << "Updated top: " << st.top() << endl; // Output: Updated top: 100
    /*
    Stack:
        100 <- Top
         30
         20
         10
    */
    cout << endl;

    // ================= DELETE =================
    st.pop();                                             // pop() removes top element
    cout << "After pop(), new top: " << st.top() << endl; // Output: After pop(), new top: 30
    /*
    Stack:
        30 <- Top
        20
        10
    */
    cout << endl;

    // ================= TRAVERSING =================
    stack<int> temp = st; // copy stack because original stack changes during traversal
    cout << "Stack elements: ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    } // Output: 30 20 10
    cout << endl
         << endl;

    // ================= CLEAR STACK =================
    while (!st.empty()) // remove all elements
    {
        st.pop();
    }
    cout << "st.empty(): " << st.empty() << endl; // Output: st.empty(): 1

    return 0;
}