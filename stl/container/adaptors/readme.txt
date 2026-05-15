CONTAINER ADAPTERS
│
├── Description
│      ├── Built on existing STL containers
│      ├── Provide more restricted interface
│      ├── Hide unnecessary operations
│      ├── No direct iterator access
│      └── Used for specific data-handling behavior
│
├── Main Container Adapters
│      ├── stack
│      ├── queue
│      └── priority_queue
│
├── stack
│      │
│      ├── Description
│      │     ├── LIFO (Last In First Out)
│      │     ├── insertion/removal from top only
│      │     └── default underlying container -> deque
│      │
│      ├── Header
│      │     └── <stack>
│      │
│      ├── Initialization
│      │     ├── direct list initialization not supported
│      │     ├── cannot use {1,2,3}
│      │     └── elements inserted using push()
│      │
│      ├── Features
│      │     ├── top element accessible
│      │     ├── insertion at top only
│      │     ├── deletion from top only
│      │     └── restricted access container
│      │
│      ├── Functions
│      │     ├── push()
│      │     ├── pop()
│      │     ├── top()
│      │     ├── size()
│      │     ├── empty()
│      │     └── swap()
│      │
│      ├── Restrictions
│      │     ├── no iterator support
│      │     ├── no begin()
│      │     ├── no end()
│      │     ├── no range-based for loop
│      │     ├── no indexing
│      │     ├── no []
│      │     ├── no random access
│      │     └── cannot access middle elements
│      │
│      └── Notes
│            ├── used in recursion handling
│            ├── expression evaluation
│            └── undo operations
│
├── queue
│      │
│      ├── Description
│      │     ├── FIFO (First In First Out)
│      │     ├── insertion at rear
│      │     ├── deletion from front
│      │     └── default underlying container -> deque
│      │
│      ├── Header
│      │     └── <queue>
│      │
│      ├── Initialization
│      │     ├── direct list initialization not supported
│      │     └── elements inserted using push()
│      │
│      ├── Features
│      │     ├── front() access supported
│      │     ├── back() access supported
│      │     ├── insertion from rear only
│      │     └── deletion from front only
│      │
│      ├── Functions
│      │     ├── push()
│      │     ├── pop()
│      │     ├── front()
│      │     ├── back()
│      │     ├── size()
│      │     ├── empty()
│      │     └── swap()
│      │
│      ├── Restrictions
│      │     ├── no iterator support
│      │     ├── no begin()
│      │     ├── no end()
│      │     ├── no range-based for loop
│      │     ├── no indexing
│      │     ├── no []
│      │     ├── no random access
│      │     └── cannot access middle elements
│      │
│      └── Notes
│            ├── used in scheduling
│            ├── buffering
│            └── BFS traversal
│
└── priority_queue
       │
       ├── Description
       │     ├── Highest priority element removed first
       │     ├── internally heap-based
       │     ├── default -> max heap
       │     └── default underlying container -> vector
       │
       ├── Header
       │     └── <queue>
       │
       ├── Initialization
       │     ├── direct list initialization not supported
       │     └── elements inserted using push()
       │
       ├── Features
       │     ├── top() gives highest priority element
       │     ├── automatic heap ordering
       │     ├── max heap by default
       │     └── min heap possible using comparator
       │
       ├── Functions
       │     ├── push()
       │     ├── pop()
       │     ├── top()
       │     ├── size()
       │     ├── empty()
       │     └── swap()
       │
       ├── Restrictions
       │     ├── no iterator support
       │     ├── no begin()
       │     ├── no end()
       │     ├── no range-based for loop
       │     ├── no indexing
       │     ├── no []
       │     ├── cannot access internal heap directly
       │     └── only highest priority accessible
       │
       └── Notes
             ├── implemented using heap algorithms
             ├── useful in scheduling algorithms
             ├── used in Dijkstra / Huffman coding
             └── top() complexity -> O(1)



DIFFERENCES
│
├── stack
│      ├── LIFO
│      ├── insertion/removal at top
│      └── top() used
│
├── queue
│      ├── FIFO
│      ├── insertion rear, deletion front
│      └── front()/back() used
│
└── priority_queue
       ├── priority-based removal
       ├── heap internally
       ├── largest element first by default
       └── top() gives highest priority



COMMON RESTRICTIONS OF CONTAINER ADAPTERS
│
├── no iterator support
├── no begin()/end()
├── no range-based loop
├── no direct traversal
├── no indexing
├── no []
└── restricted interface intentionally provided