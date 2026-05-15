SEQUENTIAL CONTAINERS
│
├── Description
│      ├── Store elements in insertion order
│      ├── Elements arranged sequentially
│      ├── Access generally based on position
│      └── Internally implemented using array or linked list
│
├── array
│      │
│      ├── Description
│      │     ├── Fixed-size sequential container
│      │     ├── Contiguous memory
│      │     └── Fast random access
│      │
│      ├── Header
│      │     └── <array>
│      │
│      ├── Initialization
│      │     └── array<int,3> a = {1,2,3};
│      │
│      ├── Features
│      │     ├── supports indexing
│      │     ├── supports []
│      │     ├── supports at()
│      │     ├── fixed size
│      │     └── compile-time size
│      │
│      ├── Iterator / Loop
│      │     ├── Random Access Iterator
│      │     ├── begin()
│      │     ├── end()
│      │     └── range-based loop supported
│      │
│      ├── Functions
│      │     ├── at()
│      │     ├── front()
│      │     ├── back()
│      │     ├── size()
│      │     ├── fill()
│      │     ├── swap()
│      │     └── data()
│      │
│      ├── Restrictions
│      │     ├── size cannot grow
│      │     ├── size cannot shrink
│      │     └── insertion/deletion not flexible
│      │
│      └── Notes
│            ├── fastest access among sequential containers
│            └── behaves similar to normal array
│
├── vector
│      │
│      ├── Description
│      │     ├── Dynamic array
│      │     ├── Contiguous memory
│      │     ├── Size can grow/shrink
│      │     └── Fast random access
│      │
│      ├── Header
│      │     └── <vector>
│      │
│      ├── Initialization
│      │     └── vector<int> v = {1,2,3};
│      │
│      ├── Features
│      │     ├── supports indexing
│      │     ├── supports []
│      │     ├── supports at()
│      │     ├── push_back() efficient
│      │     └── automatic resizing
│      │
│      ├── Iterator / Loop
│      │     ├── Random Access Iterator
│      │     ├── begin()
│      │     ├── end()
│      │     └── range-based loop supported
│      │
│      ├── Functions
│      │     ├── push_back()
│      │     ├── pop_back()
│      │     ├── insert()
│      │     ├── erase()
│      │     ├── size()
│      │     ├── capacity()
│      │     ├── reserve()
│      │     ├── shrink_to_fit()
│      │     └── clear()
│      │
│      ├── Restrictions
│      │     ├── insertion/deletion in middle costly
│      │     ├── push_front() not available
│      │     └── reallocation may invalidate iterator
│      │
│      └── Notes
│            ├── most commonly used sequential container
│            └── preferred when random access required
│
├── deque
│      │
│      ├── Description
│      │     ├── Double Ended Queue
│      │     ├── Dynamic size
│      │     ├── Fast insertion/removal at both ends
│      │     └── Random access supported
│      │
│      ├── Header
│      │     └── <deque>
│      │
│      ├── Initialization
│      │     └── deque<int> d = {1,2,3};
│      │
│      ├── Features
│      │     ├── supports indexing
│      │     ├── supports []
│      │     ├── supports at()
│      │     ├── push_front()
│      │     └── push_back()
│      │
│      ├── Iterator / Loop
│      │     ├── Random Access Iterator
│      │     ├── begin()
│      │     ├── end()
│      │     └── range-based loop supported
│      │
│      ├── Functions
│      │     ├── push_front()
│      │     ├── push_back()
│      │     ├── pop_front()
│      │     ├── pop_back()
│      │     ├── insert()
│      │     ├── erase()
│      │     ├── front()
│      │     └── back()
│      │
│      ├── Restrictions
│      │     ├── memory not fully contiguous
│      │     ├── slower random access than vector
│      │     └── insertion in middle costly
│      │
│      └── Notes
│            ├── useful for front and back operations
│            └── combines advantages of vector and list
│
├── list
│      │
│      ├── Description
│      │     ├── Doubly Linked List
│      │     ├── Non-contiguous memory
│      │     ├── Fast insertion/deletion
│      │     └── Sequential access only
│      │
│      ├── Header
│      │     └── <list>
│      │
│      ├── Initialization
│      │     └── list<int> l = {1,2,3};
│      │
│      ├── Features
│      │     ├── bidirectional traversal
│      │     ├── push_front()
│      │     ├── push_back()
│      │     ├── no indexing
│      │     └── no []
│      │
│      ├── Iterator / Loop
│      │     ├── Bidirectional Iterator
│      │     ├── begin()
│      │     ├── end()
│      │     └── range-based loop supported
│      │
│      ├── Functions
│      │     ├── push_front()
│      │     ├── push_back()
│      │     ├── pop_front()
│      │     ├── pop_back()
│      │     ├── insert()
│      │     ├── erase()
│      │     ├── splice()
│      │     ├── merge()
│      │     ├── remove()
│      │     └── reverse()
│      │
│      ├── Restrictions
│      │     ├── no random access
│      │     ├── cannot use arr[i]
│      │     ├── higher memory usage
│      │     └── slower traversal
│      │
│      └── Notes
│            ├── efficient for frequent insertion/deletion
│            └── poor choice for random access
│
└── forward_list
       │
       ├── Description
       │     ├── Singly Linked List
       │     ├── Forward traversal only
       │     ├── Less memory usage
       │     └── Sequential access only
       │
       ├── Header
       │     └── <forward_list>
       │
       ├── Initialization
       │     └── forward_list<int> fl = {1,2,3};
       │
       ├── Features
       │     ├── forward traversal only
       │     ├── push_front()
       │     ├── no indexing
       │     ├── no []
       │     └── lightweight linked list
       │
       ├── Iterator / Loop
       │     ├── Forward Iterator
       │     ├── begin()
       │     ├── end()
       │     └── range-based loop supported
       │
       ├── Functions
       │     ├── push_front()
       │     ├── pop_front()
       │     ├── insert_after()
       │     ├── erase_after()
       │     ├── before_begin()
       │     └── clear()
       │
       ├── Restrictions
       │     ├── cannot move backward
       │     ├── no random access
       │     ├── no size()
       │     └── no back()
       │
       └── Notes
             ├── memory efficient linked list
             └── useful when only forward traversal needed