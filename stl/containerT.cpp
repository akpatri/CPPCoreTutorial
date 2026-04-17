#include<iostream>
#include<vector>
#include<array>
#include<bitset>
#include<deque>
#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main(){

    // ============================================================
    // ARRAY
    // fixed size, contiguous memory (like C array)
    // order: insertion order (no reordering)
    // access: O(1), insert/delete: not supported (fixed size)
    // use: when size is known at compile time
    // ============================================================
    array<int, 3> arr = {1,2,3};
    cout << arr[0] << endl;


    // ============================================================
    // BITSET
    // fixed-size sequence of bits (0/1)
    // order: index-based (not sorted)
    // optimized for bit operations (AND, OR, XOR)
    // use: flags, binary manipulation
    // ============================================================
    bitset<4> bs("1010");
    bs.set(1);        // set bit at index
    bs.reset(2);      // clear bit
    cout << bs << endl;


    // ============================================================
    // VECTOR
    // dynamic array (resizable), contiguous memory
    // order: insertion order maintained
    // access: O(1), push_back: amortized O(1), insert middle: O(n)
    // use: default go-to container
    // ============================================================
    vector<int> v = {1,2,3};
    v.push_back(4);
    cout << v[0] << endl;


    // ============================================================
    // DEQUE
    // double-ended dynamic array (not strictly contiguous)
    // order: insertion order
    // fast insert/remove at both ends: O(1)
    // random access: O(1)
    // use: when push_front + push_back needed
    // ============================================================
    deque<int> dq = {1,2,3};
    dq.push_front(0);
    dq.push_back(4);


    // ============================================================
    // LIST
    // doubly linked list
    // order: insertion order
    // no random access (no index), traversal O(n)
    // insert/delete anywhere: O(1) (if iterator known)
    // use: frequent middle insert/delete
    // ============================================================
    list<int> li = {1,2,3};
    li.push_back(4);
    li.remove(2);


    // ============================================================
    // FORWARD_LIST
    // singly linked list (less memory than list)
    // order: insertion order
    // only forward traversal
    // insert/delete: O(1) with iterator
    // use: memory-sensitive linked list
    // ============================================================
    forward_list<int> fl = {1,2,3};
    fl.push_front(0);


    // ============================================================
    // SET
    // ordered unique elements (implemented using balanced BST)
    // order: always sorted (ascending by default)
    // duplicates: NOT allowed
    // insert/search/delete: O(log n)
    // use: sorted unique collection
    // ============================================================
    set<int> st = {3,1,2};  // stored as 1,2,3
    st.insert(4);


    // ============================================================
    // MAP
    // ordered key-value pairs (balanced BST)
    // order: sorted by key
    // keys: unique
    // insert/search/delete: O(log n)
    // use: sorted dictionary
    // ============================================================
    map<int,string> mp;
    mp[2] = "two";
    mp[1] = "one";   // stored as key order: 1,2


    // ============================================================
    // UNORDERED_SET
    // hash-based set
    // order: NO order (random bucket order)
    // duplicates: NOT allowed
    // avg complexity: O(1), worst: O(n)
    // use: fastest lookup, no sorting needed
    // ============================================================
    unordered_set<int> ust = {3,1,2};


    // ============================================================
    // UNORDERED_MAP
    // hash-based key-value
    // order: NO order
    // keys: unique
    // avg insert/search/delete: O(1)
    // use: fast dictionary
    // ============================================================
    unordered_map<int,string> ump;
    ump[1] = "one";


    // ============================================================
    // STACK
    // LIFO (Last In First Out)
    // only top element accessible
    // operations: push, pop, top
    // use: recursion simulation, expression eval
    // ============================================================
    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();


    // ============================================================
    // QUEUE
    // FIFO (First In First Out)
    // insert at back, remove from front
    // operations: push, pop, front, back
    // use: BFS, scheduling
    // ============================================================
    queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();


    return 0;
}