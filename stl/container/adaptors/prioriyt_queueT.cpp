/*
PRIORITY QUEUE IN C++
Header File: #include <queue>
Syntax: priority_queue<data_type> pq;
Example: priority_queue<int> pq;
Description: Priority Queue stores elements in sorted priority order.

Default Behavior:
- Largest element stays at the top.
- Internally implemented using Heap.
- Insertion and deletion are fast.

Important Points:
1. Top element always has highest priority.
2. By default -> Max Heap.
3. We can also create Min Heap.
4. Random access is NOT possible.
5. Duplicate values are allowed.

Time Complexity:
push()  -> O(log n)
pop()   -> O(log n)
top()   -> O(1)
empty() -> O(1)
size()  -> O(1)

Common Functions:
push()      -> insert element
pop()       -> remove top element
top()       -> access top element
size()      -> number of elements
empty()     -> check empty or not
swap()      -> swap queues

Types:
1. Max Heap Priority Queue
2. Min Heap Priority Queue
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
---------------------------------------------------
FUNCTION 1 : BASIC MAX HEAP PRIORITY QUEUE
---------------------------------------------------

Default priority queue in C++ is Max Heap.

Largest element always stays at top.
*/

void maxHeapExample()
{
    priority_queue<int> pq;

    // inserting elements
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << "Top Element : " << pq.top() << endl;

    // printing all elements
    cout << "Elements in priority order : ";

    while(!pq.empty())
    {
        cout << pq.top() << " ";

        // remove top element
        pq.pop();
    }

    cout << endl;
}


/*
---------------------------------------------------
FUNCTION 2 : MIN HEAP PRIORITY QUEUE
---------------------------------------------------

To create Min Heap:
Use greater<int>

Smallest element stays at top.
*/

void minHeapExample()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(5);

    cout << "Smallest Element : " << pq.top() << endl;

    cout << "Elements in increasing order : ";

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
}


/*
---------------------------------------------------
FUNCTION 3 : size() AND empty()
---------------------------------------------------

size()  -> total elements
empty() -> returns true/false
*/

void sizeAndEmptyExample()
{
    priority_queue<int> pq;

    pq.push(100);
    pq.push(200);

    cout << "Size : " << pq.size() << endl;

    if(pq.empty())
    {
        cout << "Priority Queue is Empty" << endl;
    }
    else
    {
        cout << "Priority Queue is NOT Empty" << endl;
    }
}


/*
---------------------------------------------------
FUNCTION 4 : pop()
---------------------------------------------------

pop() removes top element.

NOTE:
pop() does NOT return value.
*/

void popExample()
{
    priority_queue<int> pq;

    pq.push(10);
    pq.push(40);
    pq.push(30);

    cout << "Before pop, top : " << pq.top() << endl;

    pq.pop();

    cout << "After pop, top : " << pq.top() << endl;
}


/*
---------------------------------------------------
FUNCTION 5 : swap()
---------------------------------------------------

swap() exchanges data of two queues.
*/

void swapExample()
{
    priority_queue<int> pq1;
    priority_queue<int> pq2;

    pq1.push(10);
    pq1.push(20);

    pq2.push(100);
    pq2.push(200);

    // swapping
    pq1.swap(pq2);

    cout << "Top of pq1 : " << pq1.top() << endl;
    cout << "Top of pq2 : " << pq2.top() << endl;
}


/*
---------------------------------------------------
FUNCTION 6 : PRIORITY QUEUE OF STRINGS
---------------------------------------------------

Priority queue can store any data type.
*/

void stringPriorityQueue()
{
    priority_queue<string> pq;

    pq.push("Apple");
    pq.push("Mango");
    pq.push("Banana");

    cout << "String Priority Queue : ";

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
}


/*
---------------------------------------------------
FUNCTION 7 : CUSTOM INPUT
---------------------------------------------------

Taking user input.
*/

void userInputExample()
{
    priority_queue<int> pq;

    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter elements : ";

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        pq.push(x);
    }

    cout << "Priority Queue Output : ";

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
}


/*
---------------------------------------------------
MAIN FUNCTION
---------------------------------------------------
*/

int main()
{
    cout << "===== MAX HEAP EXAMPLE =====" << endl;
    maxHeapExample();

    cout << endl;

    cout << "===== MIN HEAP EXAMPLE =====" << endl;
    minHeapExample();

    cout << endl;

    cout << "===== SIZE AND EMPTY =====" << endl;
    sizeAndEmptyExample();

    cout << endl;

    cout << "===== POP EXAMPLE =====" << endl;
    popExample();

    cout << endl;

    cout << "===== SWAP EXAMPLE =====" << endl;
    swapExample();

    cout << endl;

    cout << "===== STRING PRIORITY QUEUE =====" << endl;
    stringPriorityQueue();

    cout << endl;

    cout << "===== USER INPUT EXAMPLE =====" << endl;
    // Uncomment below line to run input example

    // userInputExample();

    return 0;
}