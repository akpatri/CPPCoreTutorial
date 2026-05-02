#include <iostream>
#include <cstring> //strcat, strlen, strcpy require it
using namespace std;

int main()
{
    // C-STRING
    char c1[100] = "Hello"; // "World\0" → size = 6 (auto '\0')
    char c2[100] = "World"; // large buffer → remaining filled with 0

    // reading from console
    char buffer[100]; // temporary storage
    cout << "Read a word :" << endl;
    cin >> buffer; // reads only 1 word (stops at space/newline)

    cout << "Read a sentence :" << endl;
    cin.ignore();             // clears leftover newline from input buffer
    cin.getline(buffer, 100); // reads full line including spaces

    // methods
    strcat(c1, c2);     // joins c2 at end of c1 → "Hello" + "World"
    cout << c1 << endl; // OUTPUT: HelloWorld → because strcat appends strings

    cout << strlen(c1) << endl; // OUTPUT: 10 → counts characters (H e l l o W o r l d), excludes '\0'

    strcpy(c1, c2);     // copies c2 into c1 → old data in c1 replaced
    cout << c1 << endl; // OUTPUT: World → because c1 now holds copy of c2

    // 🔷 STRING OBJECT BASIC
    string s1 = "Hello"; // initialization
    string s2("World");  // constructor style
    string s3 = s1 + s2; // '+' operator joins strings
    cout << s3 << endl;  // OUTPUT: HelloWorld → result of concatenation

    // 🔷 INPUT (STRING)
    string input;
    cin >> input;          // reads only until space → stops early
    cout << input << endl; // OUTPUT: Hi → only first word read

    cin.ignore();          // removes leftover '\n' from previous input
    getline(cin, input);   // reads full line including spaces
    cout << input << endl; // OUTPUT: Hello World → full sentence stored

    // 🔷 ITERATORS
    string itStr = "ABC";

    for (auto it = itStr.begin(); it != itStr.end(); ++it)
        cout << *it; // *it gives each character → A, then B, then C
    
    cout << endl; // OUTPUT: ABC → forward traversal

    for (auto it = itStr.rbegin(); it != itStr.rend(); ++it)
        cout << *it; // reverse iterator → starts from end → C, B, A

    cout << endl; // OUTPUT: CBA

    // 🔷 CAPACITY
    string cap = "Hello";
    cout << cap.size() << endl;     // OUTPUT: 5 → actual number of characters
    cout << cap.capacity() << endl; // OUTPUT: depends → internal allocated memory (>= size)
    cap.resize(3);                  // keeps only first 3 characters → removes rest
    cout << cap << endl;            // OUTPUT: Hel → truncated string
    cap.clear();                    // removes all characters → becomes empty
    cout << cap.empty() << endl;    // OUTPUT: 1 (true) → string has no characters

    // 🔷 ELEMENT ACCESS
    string e = "ABCDE";
    cout << e[1] << endl;      // OUTPUT: B → index starts from 0 → e[1] = 'B'
    cout << e.at(2) << endl;   // OUTPUT: C → same as e[2], but with bounds checking
    cout << e.front() << endl; // OUTPUT: A → first character
    cout << e.back() << endl;  // OUTPUT: E → last character

    // 🔷 MODIFIERS
    string m = "Hello"; // initial string
    m += " World";      // append string → "Hello World"
    m.push_back('!');   // add char at end → "Hello World!"
    cout << m << endl;  // OUTPUT: Hello World!
    m.pop_back();       // remove last char '!'
    cout << m << endl;  // OUTPUT: Hello World

    // 🔷 MODIFY AT POSITION
    m[0] = 'Y';        // change index 0 ('H'→'Y') → "Yello World"
    cout << m << endl; // OUTPUT: Yello World
    m.at(6) = 'w';     // safe change index 6 ('W'→'w') → "Yello world"
    cout << m << endl; // OUTPUT: Yello world

    // 🔷 INSERT / ERASE / REPLACE
    m.insert(5, " C++");   // insert at index 5 → shifts right → "Yello C++ world"
    cout << m << endl;     // OUTPUT: Yello C++ world
    m.erase(5, 4);         // remove 4 chars from index 5 (" C++") → "Yello world"
    cout << m << endl;     // OUTPUT: Yello world
    m.replace(0, 5, "Hi"); // replace first 5 chars → "Hi world"
    cout << m << endl;     // OUTPUT: Hi world

    // 🔷 STRING OPERATIONS
    string op = "Hello World Hello"; // indexes: 0..16
    // find
    op.find("World");             // find() → first occurrence of substring → returns 6
    op.rfind("Hello");            // rfind() → last occurrence → returns 12
    op.find('o');                 // find(char) → first 'o' → index 4
    op.find_first_of("aeiou");    // first vowel → 'e' → index 1
    op.find_last_of("aeiou");     // last vowel → 'o' → index 16
    op.find_first_not_of("Hel");  // first char not in {H,e,l} → 'o' → index 4
    op.find_last_not_of("Hello"); // last char not in {H,e,l,o} → 'd' → index 10
    op.find("XYZ");               // returns string::npos → means "not found"    cout << op.substr(6, 5) << endl;                 // OUTPUT: World → take 5 chars from index 6
    // compare
    cout << op.compare("Hello World Hello") << endl; // OUTPUT: 0 → strings are exactly equal
    cout << op.compare("Hello") << endl;             // OUTPUT: > 0 → op is greater (longer or lexicographically larger)
    cout << op.compare("Zebra") << endl;             // OUTPUT: < 0 → op is smaller (since 'H' < 'Z')
    cout << op.compare("Hello World Hellp") << endl; // OUTPUT: < 0 → differs at last char ('o' < 'p')

    // 🔷 C-STRING FROM STRING
    string cs = "Hello";
    const char *ptr = cs.c_str(); // converts string → C-style string (char*)
    cout << ptr << endl;          // OUTPUT: Hello → prints same content

    // 🔷 COPY
    string cp = "HelloWorld";
    char buf[6];
    cp.copy(buf, 5, 0);  // copies 5 chars from index 0 → "Hello"
    buf[5] = '\0';       // manually add null terminator for C-string
    cout << buf << endl; // OUTPUT: Hello → now valid C-string

    return 0;
}