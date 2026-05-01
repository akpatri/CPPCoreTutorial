#include <iostream>
using namespace std;

// ============================================================
// 🔷 FORWARD DECLARATIONS (for friend examples)
// ============================================================

class Box;
class Helper;

// ============================================================
// 🔷 CLASS DEFINITION
// → members = fields (data) + methods (functions)
// ============================================================

class Box
{
private:                        // accessible only inside class
    int length;
    int* data;                 // dynamic memory (for deep/shallow copy demo)

protected:                     // accessible in derived classes
    int width;

public:                        // accessible everywhere
    int height;

    static int count;          // static member → shared across objects

    // ========================================================
    // 🔷 NESTED TYPE
    // ========================================================
    struct Meta
    {
        int id;
    };


   

    // move constructor
    Box(Box&& other)
    {
        length = other.length;
        width = other.width;
        height = other.height;

        data = other.data;              // steal resource
        other.data = nullptr;           // avoid double delete
        count++;
    }

    // ========================================================
    // 🔷 METHOD DECLARATION (defined outside)
    // ========================================================

    void display() const;

    // ========================================================
    // 🔷 OPERATOR OVERLOADING
    // ========================================================

    Box operator+(const Box& b)        // operator overloading
    {
        return Box(length + b.length,
                   width + b.width,
                   height + b.height);
    }

    // ========================================================
    // 🔷 FRIENDS
    // ========================================================

    friend void showLength(Box b);     // friend non-member function
    friend class Helper;              // friend class
    friend void Helper::modify(Box&); // friend member function

    // ========================================================
    // 🔷 DESTRUCTOR
    // ========================================================

    ~Box()
    {
        delete data;                  // free dynamic memory
    }
};

// ============================================================
// 🔷 STATIC MEMBER INITIALIZATION
// ============================================================

int Box::count = 0;

// ============================================================
// 🔷 MEMBER FUNCTION DEFINED OUTSIDE CLASS
// → uses scope resolution operator ::
// ============================================================

void Box::display() const
{
    cout << "L=" << length
         << " W=" << width
         << " H=" << height
         << " Data=" << (data ? *data : 0)
         << endl;
}

// ============================================================
// 🔷 FRIEND CLASS
// ============================================================

class Helper
{
public:
    void modify(Box& b)        // friend member function
    {
        b.length = 999;        // accessing private member
    }
};

// ============================================================
// 🔷 FRIEND NON-MEMBER FUNCTION
// ============================================================

void showLength(Box b)
{
    cout << "Length (friend): " << b.length << endl;
}

// ============================================================
// 🔷 FUNCTION OVERLOADING (STATIC POLYMORPHISM)
// ============================================================

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

// ============================================================
// 🔷 ABSTRACT CLASS (INTERFACE)
// ============================================================

class Shape
{
public:
    virtual double area() = 0;    // pure virtual → abstract class
};

class Rectangle : public Shape
{
    int l, w;
public:
    Rectangle(int l, int w) : l(l), w(w) {}

    double area() override       // runtime polymorphism
    {
        return l * w;
    }
};

// ============================================================
// 🔷 PASSING OBJECTS
// ============================================================

void byValue(Box b)         // copy constructor called
{
    b.display();
}

void byReference(Box& b)    // no copy
{
    b.display();
}

void byPointer(Box* b)      // pointer access
{
    b->display();
}

// ============================================================
// 🔷 MAIN
// ============================================================

int main()
{
    // ========================================================
    // 🔷 OBJECT CREATION
    // ========================================================

    Box b1;                 // default constructor
    Box b2(1,2,3);          // parameterized constructor

    // ========================================================
    // 🔷 COPY & MOVE
    // ========================================================

    Box b3 = b2;            // copy constructor (deep copy)
    Box b4 = Box(5,5,5);    // move constructor (temporary)

    // ========================================================
    // 🔷 OPERATOR OVERLOADING
    // ========================================================

    Box b5 = b2 + b3;

    // ========================================================
    // 🔷 ACCESS METHODS
    // ========================================================

    b2.display();

    Box* ptr = &b2;         // pointer to object
    ptr->display();         // access via pointer

    Box& ref = b2;          // reference to object
    ref.display();          // access via reference

    // ========================================================
    // 🔷 PASSING OBJECTS
    // ========================================================

    byValue(b2);
    byReference(b2);
    byPointer(&b2);

    // ========================================================
    // 🔷 FRIEND USAGE
    // ========================================================

    showLength(b2);

    Helper h;
    h.modify(b2);

    // ========================================================
    // 🔷 STATIC MEMBER
    // ========================================================

    cout << "Object count: " << Box::count << endl;

    // ========================================================
    // 🔷 FUNCTION OVERLOADING
    // ========================================================

    cout << add(2,3) << endl;
    cout << add(2.5,3.5) << endl;

    // ========================================================
    // 🔷 ABSTRACT CLASS
    // ========================================================

    Shape* s = new Rectangle(3,4);  // base pointer
    cout << "Area: " << s->area() << endl;
    delete s;

    return 0;
}