#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ============================================================
    // 🔷 CONSTRUCTOR / ASSIGNMENT
    // ============================================================
    string s1 = "Hello";
    string s2("World");
    string s3 = s1;     // copy
    s3 = "New String";  // assignment

    cout << s1 << " " << s2 << " " << s3 << endl;


    // ============================================================
    // 🔷 ITERATORS
    // ============================================================
    cout << "\nForward: ";
    for(auto it = s1.begin(); it != s1.end(); ++it)
        cout << *it;

    cout << "\nReverse: ";
    for(auto it = s1.rbegin(); it != s1.rend(); ++it)
        cout << *it;
    cout << endl;


    // ============================================================
    // 🔷 CAPACITY
    // ============================================================
    cout << "\nSize: " << s1.size();
    cout << "\nLength: " << s1.length();
    cout << "\nCapacity: " << s1.capacity();

    s1.reserve(50);     // increase capacity
    s1.resize(3);       // shrink string
    cout << "\nAfter resize: " << s1;

    cout << "\nEmpty? " << s1.empty() << endl;

    s1.clear();         // remove all
    cout << "After clear, empty? " << s1.empty() << endl;


    // ============================================================
    // 🔷 ELEMENT ACCESS
    // ============================================================
    string s = "ABCDE";

    cout << "\n\nIndex [1]: " << s[1];
    cout << "\nAt(2): " << s.at(2);
    cout << "\nFront: " << s.front();
    cout << "\nBack: " << s.back() << endl;


    // ============================================================
    // 🔷 MODIFIERS
    // ============================================================
    string m = "Hello";

    m += " World";          // append
    m.push_back('!');       // add char
    m.insert(5, " C++");    // insert
    m.erase(5, 4);          // erase
    m.replace(0, 5, "Hi");  // replace

    cout << "\nModified: " << m << endl;

    m.pop_back();           // remove last char


    // ============================================================
    // 🔷 STRING OPERATIONS
    // ============================================================
    string str = "Hello World Hello";

    cout << "\nFind 'World': " << str.find("World");
    cout << "\nrfind 'Hello': " << str.rfind("Hello");

    cout << "\nFirst of 'o': " << str.find_first_of('o');
    cout << "\nLast of 'o': " << str.find_last_of('o');

    cout << "\nSubstring: " << str.substr(6, 5);

    cout << "\nCompare: " << str.compare("Hello World Hello") << endl;


    // ============================================================
    // 🔷 C-STRING ACCESS
    // ============================================================
    const char* cstr = str.c_str();
    cout << "\nC-string: " << cstr << endl;


    // ============================================================
    // 🔷 COPY
    // ============================================================
    char buffer[10];
    str.copy(buffer, 5, 0);   // copy first 5 chars
    buffer[5] = '\0';

    cout << "Copied: " << buffer << endl;


    return 0;
}