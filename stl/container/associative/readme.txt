ASSOCIATIVE CONTAINERS
│
├── Description
│      ├── Store elements using KEY instead of insertion order
│      ├── Elements may be:
│      │      ├── sorted
│      │      └── unordered
│      ├── Used for efficient:
│      │      ├── search
│      │      ├── insertion
│      │      └── deletion
│      └── Two categories:
│             ├── ordered
│             └── unordered
│
├── ORDERED ASSOCIATIVE CONTAINERS
│      │
│      ├── Description
│      │     ├── Elements automatically sorted by key
│      │     ├── Internally implemented using balanced BST
│      │     │      └── usually Red-Black Tree
│      │     ├── search  -> O(log n)
│      │     ├── insert  -> O(log n)
│      │     └── erase   -> O(log n)
│      │
│      ├── set
│      │     ├── header -> <set>
│      │     ├── stores values only
│      │     ├── unique elements only
│      │     ├── elements immutable
│      │     ├── sorted automatically
│      │     ├── no []
│      │     └── no duplicates
│      │
│      ├── multiset
│      │     ├── header -> <set>
│      │     ├── stores values only
│      │     ├── duplicate values allowed
│      │     ├── elements immutable
│      │     ├── sorted automatically
│      │     └── no []
│      │
│      ├── map
│      │     ├── header -> <map>
│      │     ├── stores key-value pairs
│      │     ├── unique keys only
│      │     ├── sorted by key
│      │     ├── key immutable
│      │     ├── value mutable
│      │     ├── supports []
│      │     └── value_type = pair<const Key, T>
│      │
│      └── multimap
│            ├── header -> <map>
│            ├── stores key-value pairs
│            ├── duplicate keys allowed
│            ├── sorted by key
│            ├── key immutable
│            └── no []
│
├── UNORDERED ASSOCIATIVE CONTAINERS
│      │
│      ├── Description
│      │     ├── Elements not stored in sorted order
│      │     ├── Internally implemented using hash table
│      │     ├── average search  -> O(1)
│      │     ├── average insert  -> O(1)
│      │     ├── average erase   -> O(1)
│      │     └── worst case      -> O(n)
│      │
│      ├── unordered_set
│      │     ├── header -> <unordered_set>
│      │     ├── stores values only
│      │     ├── unique elements only
│      │     ├── no ordering
│      │     └── no []
│      │
│      ├── unordered_multiset
│      │     ├── header -> <unordered_set>
│      │     ├── duplicate values allowed
│      │     ├── no ordering
│      │     └── no []
│      │
│      ├── unordered_map
│      │     ├── header -> <unordered_map>
│      │     ├── stores key-value pairs
│      │     ├── unique keys only
│      │     ├── no ordering
│      │     ├── supports []
│      │     └── value_type = pair<const Key, T>
│      │
│      └── unordered_multimap
│            ├── header -> <unordered_map>
│            ├── duplicate keys allowed
│            ├── no ordering
│            ├── key-value pairs
│            └── no []
│
├── List / Uniform Initialization
│      ├── set<int> s = {1,2,3};
│      ├── multiset<int> ms = {1,1,2};
│      ├── map<int,string> mp = {{1,"One"},{2,"Two"}};
│      └── unordered_map<int,string> ump = {{1,"One"},{2,"Two"}};
│
├── Iterator / Loop Support
│      │
│      ├── Supported in all associative containers
│      │
│      ├── Functions
│      │     ├── begin()
│      │     └── end()
│      │
│      ├── Loop
│      │     └── range-based for loop supported
│      │
│      ├── Ordered containers
│      │     └── Bidirectional Iterator
│      │
│      └── Unordered containers
│            └── Forward Iterator
│
├── Common Functions / Members
│      │
│      ├── Functions
│      │     ├── insert()
│      │     ├── erase()
│      │     ├── find()
│      │     ├── count()
│      │     ├── size()
│      │     ├── empty()
│      │     ├── clear()
│      │     ├── begin()
│      │     ├── end()
│      │     ├── at(key)         -> map/unordered_map only
│      │     └── [key]           -> map/unordered_map only
│      │
│      └── Member Types
│            ├── key_type
│            ├── mapped_type
│            ├── value_type
│            ├── iterator
│            ├── const_iterator
│            ├── size_type
│            └── allocator_type
│
├── Restrictions
│      │
│      ├── Common Restrictions
│      │     ├── no random access
│      │     ├── no indexing
│      │     ├── cannot use arr[i]
│      │     ├── cannot use it + 1
│      │     └── traversal through iterator only
│      │
│      ├── set / multiset
│      │     ├── elements immutable
│      │     ├── no []
│      │     └── values only
│      │
│      ├── map / unordered_map
│      │     ├── key immutable
│      │     ├── value mutable
│      │     ├── [] inserts default value if key absent
│      │     └── unique keys only
│      │
│      ├── multimap / unordered_multimap
│      │     ├── duplicate keys allowed
│      │     ├── no []
│      │     └── access through iterator/equal_range()
│      │
│      └── unordered containers
│            ├── no ordering guarantee
│            ├── rehashing may rearrange elements
│            ├── rehashing may invalidate iterators
│            └── worst case complexity O(n)
│
├── Differences
│      │
│      ├── ordered vs unordered
│      │     ├── ordered   -> sorted + tree-based
│      │     └── unordered -> hash-based + faster average access
│      │
│      ├── set vs map
│      │     ├── set -> values only
│      │     └── map -> key-value pairs
│      │
│      └── normal vs multi
│            ├── normal -> duplicates not allowed
│            └── multi  -> duplicates allowed
│
└── Important Notes
       ├── associative containers are key-based containers
       ├── map elements use:
       │      ├── first  -> key
       │      └── second -> value
       ├── only map/unordered_map support []
       ├── ordered containers useful for sorted traversal
       └── unordered containers useful for faster average lookup