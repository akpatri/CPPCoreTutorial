/*
========================================================
                    STACK IN C++
========================================================

Definition:
- stack is a container adapter that follows LIFO rule
- LIFO = Last In First Out
- Last inserted element comes out first

Header File:
    #include <stack>

Syntax:
    stack<data_type> stack_name;

Example:
    stack<int> st;

Internal Working:
- Elements are inserted and removed only from TOP
- No direct indexing allowed like array/vector
- By default internally uses deque container

Main Functions:
1. push(x)   -> insert element at top
2. pop()     -> remove top element
3. top()     -> access top element
4. size()    -> total number of elements
5. empty()   -> checks stack is empty or not

Important Notes:
- pop() does NOT return removed element
- top() can be updated
- Traversing requires copying because original stack changes after pop()
- Accessing top() on empty stack causes undefined behavior

Time Complexity:
- push()  -> O(1)
- pop()   -> O(1)
- top()   -> O(1)
- size()  -> O(1)
- empty() -> O(1)

Example Stack:
        40 <- Top
        30
        20
        10

========================================================
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
    cout << "st.top(): " << st.top() << endl;     // top() returns top element
    cout << "st.size(): " << st.size() << endl;   // size() returns total elements
    cout << "st.empty(): " << st.empty() << endl; // empty() checks stack is empty or not
    cout << endl;

    // ================= UPDATE =================
    st.top() = 100;                              // update top element
    cout << "Updated top: " << st.top() << endl;
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
    cout << "After pop(), new top: " << st.top() << endl;
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
    }

    // Output: 30 20 10
    cout << endl
         << endl;

    // ================= CLEAR STACK =================
    while (!st.empty()) // remove all elements
    {
        st.pop();
    }

    cout << "st.empty(): " << st.empty() << endl;

    return 0;
}