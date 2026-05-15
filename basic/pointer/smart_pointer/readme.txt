============================================================
                SMART POINTER IN C++
============================================================

SMART_POINTER
│
├── SMART POINTER
│   │
│   ├── Special C++ object for automatic memory management
│   │      -> automatically handles new/delete
│   │
│   ├── Introduced in:
│   │      C++11
│   │
│   ├── Header File:
│   │      #include <memory>
│   │
│   ├── Solves:
│   │      ├── Memory Leak
│   │      │      -> memory allocated but never deleted
│   │      │
│   │      ├── Dangling Pointer
│   │      │      -> pointer points to deleted memory
│   │      │
│   │      ├── Double Delete
│   │      │      -> deleting same memory twice
│   │      │
│   │      └── Manual delete problem
│   │             -> programmer forgets delete
│   │
│   └── Follows:
│          RAII Principle
│          -> resource automatically released in destructor
│


├────────────────────────────────────────────────────────────
│
├── RAII
│   │
│   ├── Full Form:
│   │      Resource Acquisition Is Initialization
│   │
│   ├── Meaning:
│   │      -> resource acquired during object creation
│   │      -> resource released during object destruction
│   │
│   ├── Example:
│   │
│   │      Constructor
│   │           │
│   │           └── acquires memory/resource
│   │
│   │      Destructor
│   │           │
│   │           └── releases memory/resource
│   │
│   └── Smart pointers follow RAII automatically
│


├────────────────────────────────────────────────────────────
│
├── TYPES OF SMART POINTER
│   │
│   ├── 1. unique_ptr
│   │      -> single ownership
│   │
│   ├── 2. shared_ptr
│   │      -> multiple ownership
│   │
│   └── 3. weak_ptr
│          -> non-owning observer
│


├────────────────────────────────────────────────────────────
│
├── UNIQUE_PTR
│   │
│   ├── Ownership:
│   │      Single Ownership
│   │      -> only ONE unique_ptr owns object
│   │
│   ├── Points To:
│   │      Directly points to object/value memory
│   │
│   ├── Example:
│   │      unique_ptr<int> ptr;
│   │
│   ├── Creation:
│   │      make_unique<Type>()
│   │      -> safest and recommended way
│   │
│   ├── Important Points:
│   │      ├── Only one owner allowed
│   │      │
│   │      ├── Copy NOT allowed
│   │      │      -> prevents multiple ownership
│   │      │
│   │      ├── move() transfers ownership
│   │      │      -> old pointer becomes nullptr
│   │      │
│   │      ├── Fastest smart pointer
│   │      │      -> no reference counting overhead
│   │      │
│   │      └── Automatically deletes object
│   │             -> when pointer goes out of scope
│   │
│   ├── Main Functions:
│   │      │
│   │      ├── get()
│   │      │      -> returns raw pointer
│   │      │
│   │      ├── release()
│   │      │      -> releases ownership
│   │      │      -> manual delete required afterward
│   │      │
│   │      ├── reset()
│   │      │      -> deletes old object
│   │      │      -> optionally assigns new object
│   │      │
│   │      ├── swap()
│   │      │      -> swaps ownership between pointers
│   │      │
│   │      └── move()
│   │             -> transfers ownership safely
│   │
│   ├── Internally:
│   │
│   │      unique_ptr
│   │           │
│   │           ▼
│   │      Object Address
│   │
│   ├── Example Flow:
│   │
│   │      unique_ptr<int> p1
│   │               │
│   │               ▼
│   │             [10]
│   │
│   ├── move() Flow:
│   │
│   │      BEFORE:
│   │
│   │      p1 ───► [10]
│   │
│   │      AFTER:
│   │
│   │      p2 ───► [10]
│   │
│   │      p1 = nullptr
│   │
│   └── Best Use:
│          When only ONE owner required
│


├────────────────────────────────────────────────────────────
│
├── SHARED_PTR
│   │
│   ├── Ownership:
│   │      Shared Ownership
│   │      -> multiple shared_ptr can own same object
│   │
│   ├── Points To:
│   │      Directly points to object/value memory
│   │
│   ├── Example:
│   │      shared_ptr<int> ptr;
│   │
│   ├── Creation:
│   │      make_shared<Type>()
│   │      -> recommended creation method
│   │
│   ├── Important Points:
│   │      ├── Multiple owners allowed
│   │      │
│   │      ├── Copy allowed
│   │      │      -> every copy increases reference count
│   │      │
│   │      ├── Uses reference counting
│   │      │      -> tracks total owners
│   │      │
│   │      ├── Object deleted when count = 0
│   │      │      -> automatic cleanup
│   │      │
│   │      └── Slightly slower than unique_ptr
│   │             -> because of reference counting
│   │
│   ├── Main Functions:
│   │      │
│   │      ├── use_count()
│   │      │      -> returns total owners count
│   │      │
│   │      ├── get()
│   │      │      -> returns raw pointer
│   │      │
│   │      ├── reset()
│   │      │      -> removes ownership
│   │      │
│   │      ├── swap()
│   │      │      -> swaps ownership
│   │      │
│   │      └── unique()
│   │             -> checks only one owner exists
│   │
│   ├── Internally:
│   │
│   │      shared_ptr p1 ───┐
│   │                        │
│   │      shared_ptr p2 ───┼──► Object Address
│   │                        │
│   │      shared_ptr p3 ───┘
│   │
│   │      Reference Count = 3
│   │
│   ├── Reference Count Flow:
│   │
│   │      p1 created
│   │
│   │      Count = 1
│   │
│   │      p2 = p1
│   │
│   │      Count = 2
│   │
│   │      p2.reset()
│   │
│   │      Count = 1
│   │
│   ├── Object Deletion:
│   │
│   │      Count becomes 0
│   │             │
│   │             ▼
│   │      Destructor automatically called
│   │
│   └── Best Use:
│          When multiple owners need same resource
│


├────────────────────────────────────────────────────────────
│
├── WEAK_PTR
│   │
│   ├── Ownership:
│   │      No Ownership
│   │      -> only observes object
│   │
│   ├── Points To:
│   │      Observes shared_ptr object
│   │
│   ├── IMPORTANT:
│   │      weak_ptr works ONLY with shared_ptr
│   │
│   ├── weak_ptr DOES NOT work with:
│   │      unique_ptr
│   │      -> because unique_ptr has exclusive ownership
│   │
│   ├── Example:
│   │      weak_ptr<int> wp;
│   │
│   ├── Important Points:
│   │      ├── Does NOT own object
│   │      │
│   │      ├── Does NOT increase reference count
│   │      │      -> object deletion not affected
│   │      │
│   │      ├── Used to avoid cyclic dependency
│   │      │      -> prevents memory leak
│   │      │
│   │      ├── Cannot directly access object
│   │      │      -> must use lock()
│   │      │
│   │      └── Uses lock() for temporary access
│   │
│   ├── Main Functions:
│   │      │
│   │      ├── lock()
│   │      │      -> converts weak_ptr to shared_ptr
│   │      │
│   │      ├── expired()
│   │      │      -> checks object still exists or not
│   │      │
│   │      ├── reset()
│   │      │      -> removes observation
│   │      │
│   │      └── owner_before()
│   │             -> compares ownership order
│   │
│   ├── Internally:
│   │
│   │      shared_ptr sp ───────► Object
│   │
│   │      weak_ptr wp ---------> observes object
│   │
│   │      weak_ptr does NOT own object
│   │
│   ├── lock() Flow:
│   │
│   │      weak_ptr
│   │          │
│   │      lock()
│   │          │
│   │          ▼
│   │      temporary shared_ptr
│   │
│   │      -> temporary reference count increases
│   │
│   ├── expired():
│   │
│   │      expired() = 0
│   │           -> object exists
│   │
│   │      expired() = 1
│   │           -> object destroyed
│   │
│   └── Best Use:
│          To observe shared object safely
│


├────────────────────────────────────────────────────────────
│
├── REFERENCE COUNTING
│   │
│   ├── Used by:
│   │      shared_ptr
│   │
│   ├── NOT used by:
│   │      unique_ptr
│   │      weak_ptr
│   │
│   ├── Purpose:
│   │      -> tracks total owners of object
│   │
│   ├── Example:
│   │
│   │      shared_ptr<int> p1
│   │
│   │      Count = 1
│   │
│   │      shared_ptr<int> p2 = p1;
│   │
│   │      Count = 2
│   │
│   │      p2.reset();
│   │
│   │      Count = 1
│   │
│   └── Object deleted when count becomes 0
│


├────────────────────────────────────────────────────────────
│
├── CYCLIC DEPENDENCY
│   │
│   ├── Problem:
│   │      Two shared_ptr objects point to each other
│   │
│   ├── Result:
│   │      Reference count never becomes 0
│   │
│   ├── Causes:
│   │      Memory Leak
│   │
│   ├── Wrong Structure:
│   │
│   │      shared_ptr A ───► B
│   │             ▲          │
│   │             │          ▼
│   │             └──────────┘
│   │
│   │      -> both objects keep each other alive
│   │
│   ├── Solution:
│   │      Use weak_ptr
│   │
│   ├── Correct Structure:
│   │
│   │      shared_ptr A ───► B
│   │             ▲
│   │             │
│   │         weak_ptr
│   │
│   │      -> weak_ptr does not increase count
│   │
│   └── weak_ptr breaks cyclic dependency
│


├────────────────────────────────────────────────────────────
│
├── COMPARISON
│   │
│   ├───────────────┬────────────┬────────────┬────────────
│   │ Feature       │ unique_ptr │ shared_ptr │ weak_ptr
│   ├───────────────┼────────────┼────────────┼────────────
│   │ Ownership     │ Single     │ Shared     │ No Owner
│   │ Copy Allowed  │ No         │ Yes        │ Yes
│   │ Move Allowed  │ Yes        │ Yes        │ Yes
│   │ Ref Counting  │ No         │ Yes        │ No
│   │ Auto Delete   │ Yes        │ Yes        │ No
│   │ Speed         │ Fastest    │ Slower     │ Fast
│   │ Direct Access │ Yes        │ Yes        │ No
│   └───────────────┴────────────┴────────────┴────────────
│


└────────────────────────────────────────────────────────────