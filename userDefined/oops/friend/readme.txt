/*
==================== IMPORTANT POINTS (ENHANCED) ====================

1. friend NON-MEMBER FUNCTION
--------------------------------------------------
- normal function (not part of class)
- declared inside class using 'friend'
- can access private + protected members

SYNTAX:
class A {
    friend void func(A obj);   // declaration
};

void func(A obj) {             // definition (outside class)
    // can access private members of A
}

NOTES:
- called like normal function → func(obj)
- does NOT use object with dot operator
- not in class scope (no this pointer)


2. friend CLASS
--------------------------------------------------
- entire class gets access to private/protected members
- all member functions of friend class can access data

SYNTAX:
class A {
    friend class B;   // B is friend of A
};

class B {
    void fun(A obj) {
        // can access private members of A
    }
};

NOTES:
- friendship is NOT mutual
  (if A is friend of B, B is NOT automatically friend of A)
- friendship is NOT inherited


3. friend MEMBER FUNCTION
--------------------------------------------------
- only specific function of another class is given access
- requires forward declaration

SYNTAX:
class B;   // forward declaration

class A {
    friend void B::fun(A obj);   // specific member function
};

class B {
public:
    void fun(A obj);             // declaration
};

void B::fun(A obj) {
    // can access private members of A
}

NOTES:
- only declared function gets access (not whole class)
- more controlled than friend class


4. GENERAL RULES OF FRIEND
--------------------------------------------------
- friend is NOT a member of class
- declared inside class, defined outside
- can access private + protected data
- no this pointer
- cannot be called using object (for non-member friend)

5. ENCAPSULATION NOTE
--------------------------------------------------
- friend breaks data hiding
- use only when necessary (tight coupling situations)

6. MEMORY TRICK
--------------------------------------------------
friend → "OUTSIDER WITH PERMISSION"

=========================================================
*/