#include <iostream>
#include <string>
#include <sstream>   // for stringstream
#include <cstring>   // for strcpy
using namespace std;

int main() {
    // ============================================================
    // 🔷 1. STRING → INTEGER / DOUBLE
    // ============================================================
    string s1 = "123";
    /** stoi(string)
     *  Responsibility: string → int
     *  Param: numeric string
     */
    int n1 = stoi(s1);
    cout << "string → int: " << n1 << endl;

    /** stod(string)
     *  Responsibility: string → double
     */
    double d1 = stod("12.34");
    cout << "string → double: " << d1 << endl;



    // ============================================================
    // 🔷 2. INTEGER / DOUBLE → STRING
    // ============================================================

    /** to_string(value)
     *  Responsibility: number → string
     */
    string s2 = to_string(456);
    cout << "int → string: " << s2 << endl;



    // ============================================================
    // 🔷 3. STRING ↔ CHAR (single character)
    // ============================================================

    string str = "Hello";

    /** string → char
     *  Access character using index
     */
    char ch = str[0];
    cout << "string → char: " << ch << endl;

    /** char → string
     *  string(1, char)
     *  Param:
     *    1 → number of times
     *    char → character
     */
    string s3 = string(1, 'A');
    cout << "char → string: " << s3 << endl;


    // ============================================================
    // 🔷 4. STRING ↔ CHAR ARRAY (C-style string)
    // ============================================================
    /* 
     * string → char*
     *  c_str() → returns const char*
     */
    const char* cstr = str.c_str();
    cout << "string → char*: " << cstr << endl;

    /** char* → string
     *  string(char*)
     */
    string s4 = string("World");
    cout << "char* → string: " << s4 << endl;



    // ============================================================
    // 🔷 5. CHAR ↔ INTEGER (ASCII)
    // ============================================================
    char c = 'A';
    /** char → int
     *  gives ASCII value
     */
    int ascii = int(c);
    cout << "char → int: " << ascii << endl;

    /** int → char
     *  ASCII → character
     */
    char c2 = char(66);
    cout << "int → char: " << c2 << endl;

    // ============================================================
    // 🔷 6. STRING ↔ NUMBER using stringstream
    // ============================================================
    /** stringstream
     *  Flexible conversion tool
     */

    string s5 = "789";
    stringstream ss(s5);

    int n2;
    ss >> n2;   // extract int
    cout << "stringstream string → int: " << n2 << endl;

    /** number → string using stringstream */
    stringstream ss2;
    ss2 << 999;
    string s6 = ss2.str();
    cout << "stringstream int → string: " << s6 << endl;

    // ============================================================
    // 🔷 7. C-STYLE TYPECAST
    // ============================================================
    /** (type)value
     *  Old style (less safe)
     */
    double x = (double)5 / 2;
    cout << "C-style cast: " << x << endl;

    // ============================================================
    // 🔷 8. C++ STYLE TYPECAST
    // ============================================================
    /** static_cast<type>(value)
     *  Safe & recommended
     */
    double y = static_cast<double>(5) / 2;
    cout << "static_cast: " << y << endl;

    // ============================================================
    // 🔷 9. STRING → C-STYLE MUTABLE ARRAY
    // ============================================================
    /** copy string into char array
     *  strcpy(destination, source)
     */
    char arr[20];
    strcpy(arr, str.c_str());
    cout << "string → char array: " << arr << endl;

    return 0;
}