/*
QUEUE IN C++

Header File:
#include <queue>

Syntax:
queue<data_type> queue_name;

Example:
queue<int> q;

Description:
Queue is a linear data structure that follows:

FIFO (First In First Out)

Meaning:
- Element inserted first will be removed first.
- Insertion happens from BACK.
- Deletion happens from FRONT.

Real Life Example:
- Ticket Counter
- Printer Queue
- CPU Scheduling
- Customer Service Line

Important Points:
1. FIFO structure
2. No random access
3. Insertion at back
4. Deletion from front
5. Duplicate values allowed

Common Functions:
push()   -> insert element at back
pop()    -> remove front element
front()  -> access first element
back()   -> access last element
size()   -> total elements
empty()  -> check queue empty or not
swap()   -> swap two queues

Time Complexity:
push()   -> O(1)
pop()    -> O(1)
front()  -> O(1)
back()   -> O(1)
size()   -> O(1)
empty()  -> O(1)
*/

#include <iostream>
#include <queue>

using namespace std;


/*
---------------------------------------------------
FUNCTION 1 : BASIC QUEUE OPERATIONS
---------------------------------------------------

push() inserts from back
pop() removes from front
*/

void basicQueueExample()
{
    queue<int> q;

    // inserting elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front Element : " << q.front() << endl;
    cout << "Back Element  : " << q.back() << endl;

    cout << "Queue Elements : ";

    while(!q.empty())
    {
        cout << q.front() << " ";

        // removing front element
        q.pop();
    }

    cout << endl;
}


/*
---------------------------------------------------
FUNCTION 2 : size() AND empty()
---------------------------------------------------

size()  -> returns total elements
empty() -> returns true/false
*/

void sizeAndEmptyExample()
{
    queue<int> q;

    q.push(100);
    q.push(200);

    cout << "Size : " << q.size() << endl;

    if(q.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is NOT Empty" << endl;
    }
}


/*
---------------------------------------------------
FUNCTION 3 : pop()
---------------------------------------------------

pop() removes front element.

NOTE:
pop() does NOT return value.
*/

void popExample()
{
    queue<int> q;

    q.push(11);
    q.push(22);
    q.push(33);

    cout << "Front Before pop : " << q.front() << endl;

    q.pop();

    cout << "Front After pop  : " << q.front() << endl;
}


/*
---------------------------------------------------
FUNCTION 4 : front() AND back()
---------------------------------------------------

front() -> first element
back()  -> last element
*/

void frontAndBackExample()
{
    queue<string> q;

    q.push("Apple");
    q.push("Banana");
    q.push("Mango");

    cout << "Front Element : " << q.front() << endl;
    cout << "Back Element  : " << q.back() << endl;
}


/*
---------------------------------------------------
FUNCTION 5 : swap()
---------------------------------------------------

swap() exchanges data of two queues.
*/

void swapExample()
{
    queue<int> q1;
    queue<int> q2;

    q1.push(1);
    q1.push(2);

    q2.push(100);
    q2.push(200);

    // swapping queues
    q1.swap(q2);

    cout << "Front of q1 : " << q1.front() << endl;
    cout << "Front of q2 : " << q2.front() << endl;
}


/*
---------------------------------------------------
FUNCTION 6 : PRINTING WITHOUT DESTROYING QUEUE
---------------------------------------------------

We use temporary queue.
*/

void printWithoutDestroying()
{
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);

    // copy queue
    queue<int> temp = q;

    cout << "Original Queue : ";

    while(!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << endl;
}


/*
---------------------------------------------------
FUNCTION 7 : USER INPUT EXAMPLE
---------------------------------------------------

Taking elements from user.
*/

void userInputExample()
{
    queue<int> q;

    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter elements : ";

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        q.push(x);
    }

    cout << "Queue Elements : ";

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
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
    cout << "===== BASIC QUEUE =====" << endl;
    basicQueueExample();

    cout << endl;

    cout << "===== SIZE AND EMPTY =====" << endl;
    sizeAndEmptyExample();

    cout << endl;

    cout << "===== POP EXAMPLE =====" << endl;
    popExample();

    cout << endl;

    cout << "===== FRONT AND BACK =====" << endl;
    frontAndBackExample();

    cout << endl;

    cout << "===== SWAP EXAMPLE =====" << endl;
    swapExample();

    cout << endl;

    cout << "===== PRINT WITHOUT DESTROYING =====" << endl;
    printWithoutDestroying();

    cout << endl;

    cout << "===== USER INPUT EXAMPLE =====" << endl;

    // Uncomment below line to run user input example

    // userInputExample();

    return 0;
}