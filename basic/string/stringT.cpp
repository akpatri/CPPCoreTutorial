#include <iostream>
#include <cstring> // strcat, strlen, strcpy require it
#include <iomanip> // setw, setfill, left, right, fixed, scientific
#include <sstream> // stringstream

using namespace std;

int main()
{
    // C-STRING
    char c1[100] = "Hello"; // "Hello\0" → auto null terminator added
    char c2[100] = "World"; // large buffer → remaining filled with 0

    // reading from console
    char buffer[100]; // temporary storage

    cout << "Read a word :" << endl;
    cin >> buffer; // reads only 1 word (stops at space/newline)

    cout << "Read a sentence :" << endl;
    cin.ignore();             // clears leftover newline from input buffer
    cin.getline(buffer, 100); // reads full line including spaces

    // methods
    strcat(c1, c2);     // joins c2 at end of c1 → "HelloWorld"
    cout << c1 << endl; // OUTPUT: HelloWorld

    cout << strlen(c1) << endl; // OUTPUT: 10 → excludes '\0'

    strcpy(c1, c2);     // copies c2 into c1
    cout << c1 << endl; // OUTPUT: World

    // 🔷 STRING OBJECT BASIC
    string s1 = "Hello";
    string s2("World");
    string s3 = s1 + s2;

    cout << s3 << endl; // OUTPUT: HelloWorld

    // 🔷 INPUT (STRING)
    string input;

    cin >> input;          // reads only first word
    cout << input << endl; // OUTPUT: first word only

    cin.ignore();        // removes leftover '\n'
    getline(cin, input); // reads full line

    cout << input << endl;

    // 🔷 ITERATORS
    string itStr = "ABC";

    for (auto it = itStr.begin(); it != itStr.end(); ++it)
        cout << *it;

    cout << endl; // OUTPUT: ABC

    for (auto it = itStr.rbegin(); it != itStr.rend(); ++it)
        cout << *it;

    cout << endl; // OUTPUT: CBA

    // 🔷 CAPACITY
    string cap = "Hello";

    cout << cap.size() << endl;     // actual characters
    cout << cap.capacity() << endl; // allocated memory

    cap.resize(3);

    cout << cap << endl; // OUTPUT: Hel

    cap.clear();

    cout << cap.empty() << endl; // OUTPUT: 1

    // 🔷 ELEMENT ACCESS
    string e = "ABCDE";

    cout << e[1] << endl;      // OUTPUT: B
    cout << e.at(2) << endl;   // OUTPUT: C
    cout << e.front() << endl; // OUTPUT: A
    cout << e.back() << endl;  // OUTPUT: E

    // 🔷 MODIFIERS
    string m = "Hello";

    m += " World";
    m.push_back('!');

    cout << m << endl; // OUTPUT: Hello World!

    m.pop_back();

    cout << m << endl; // OUTPUT: Hello World

    // 🔷 MODIFY AT POSITION
    m[0] = 'Y';

    cout << m << endl; // OUTPUT: Yello World

    m.at(6) = 'w';

    cout << m << endl; // OUTPUT: Yello world

    // 🔷 INSERT / ERASE / REPLACE
    m.insert(5, " C++");

    cout << m << endl; // OUTPUT: Yello C++ world

    m.erase(5, 4);

    cout << m << endl; // OUTPUT: Yello world

    m.replace(0, 5, "Hi");

    cout << m << endl; // OUTPUT: Hi world

    // 🔷 STRING OPERATIONS
    string op = "Hello World Hello";

    // find operations
    cout << op.find("World") << endl;             // OUTPUT: 6
    cout << op.rfind("Hello") << endl;            // OUTPUT: 12
    cout << op.find('o') << endl;                 // OUTPUT: 4
    cout << op.find_first_of("aeiou") << endl;    // OUTPUT: 1
    cout << op.find_last_of("aeiou") << endl;     // OUTPUT: 16
    cout << op.find_first_not_of("Hel") << endl;  // OUTPUT: 4
    cout << op.find_last_not_of("Hello") << endl; // OUTPUT: 10

    if (op.find("XYZ") == string::npos)
        cout << "Not Found" << endl;

    // substr
    cout << op.substr(6, 5) << endl; // OUTPUT: World

    // compare
    cout << op.compare("Hello World Hello") << endl; // OUTPUT: 0
    cout << op.compare("Hello") << endl;             // OUTPUT: >0
    cout << op.compare("Zebra") << endl;             // OUTPUT: <0
    cout << op.compare("Hello World Hellp") << endl; // OUTPUT: <0

    // 🔷 C-STRING FROM STRING
    string cs = "Hello";

    const char *ptr = cs.c_str();

    cout << ptr << endl;

    // 🔷 COPY
    string cp = "HelloWorld";

    char buf[6];

    cp.copy(buf, 5, 0);

    buf[5] = '\0';

    cout << buf << endl;

    /*
    ===================================================
                STRING FORMATTING METHODS
    ===================================================
    */

    // 🔷 METHOD 1 : CONCATENATION USING +
    string fname = "John";
    int age = 25;

    string result1 = "Name : " + fname + ", Age : " + to_string(age);

    cout << result1 << endl;
    // OUTPUT: Name : John, Age : 25

    // 🔷 METHOD 2 : APPEND()
    string app = "Hello";

    app.append(" World");

    cout << app << endl;
    // OUTPUT: Hello World

    // 🔷 METHOD 3 : USING STRINGSTREAM
    stringstream ss;

    ss << "Name : " << fname << ", Age : " << age;

    string formatted = ss.str();

    cout << formatted << endl;
    // OUTPUT: Name : John, Age : 25

    // 🔷 METHOD 4 : setw() FOR WIDTH
    cout << setw(10) << "Hi" << endl;
    // OUTPUT:        Hi
    // total width = 10

    // 🔷 METHOD 5 : left ALIGNMENT
    cout << left << setw(10) << "Apple" << "123" << endl;
    // OUTPUT: Apple     123

    // 🔷 METHOD 6 : right ALIGNMENT
    cout << right << setw(10) << "Apple" << endl;
    // OUTPUT:      Apple

    // 🔷 METHOD 7 : setfill()
    cout << setfill('*') << setw(10) << "Hi" << endl;
    // OUTPUT: ********Hi

    // reset fill character
    cout << setfill(' ');

    // 🔷 METHOD 8 : fixed
    double pi = 3.1415926535;

    cout << fixed << pi << endl;
    // OUTPUT: 3.141593

    // 🔷 METHOD 9 : setprecision()
    cout << fixed << setprecision(2) << pi << endl;
    // OUTPUT: 3.14

    // 🔷 METHOD 10 : scientific
    cout << scientific << pi << endl;
    // OUTPUT: 3.141593e+00

    // 🔷 METHOD 11 : boolalpha
    bool status = true;

    cout << boolalpha << status << endl;
    // OUTPUT: true

    // 🔷 METHOD 12 : hex, oct, dec
    int num = 100;

    cout << hex << num << endl;
    // OUTPUT: 64

    cout << oct << num << endl;
    // OUTPUT: 144

    cout << dec << num << endl;
    // OUTPUT: 100



    // OUTPUT: Name : Aman, Marks : 95

    // 🔷 METHOD 14 : FORMAT TABLE STYLE OUTPUT
    cout << left << setw(15) << "Name"
         << setw(10) << "Age"
         << setw(10) << "Marks" << endl;

    cout << left << setw(15) << "Rahul"
         << setw(10) << 20
         << setw(10) << 88 << endl;

    cout << left << setw(15) << "Aman"
         << setw(10) << 22
         << setw(10) << 95 << endl;

    /*
    OUTPUT:
    Name           Age       Marks
    Rahul          20        88
    Aman           22        95
    */

     /*
    =========================================================
        STRING TO DIFFERENT DATA TYPES CONVERSION
    =========================================================
    */

    // string -> int
    string strInt = "123";
    int intValue = stoi(strInt);
    cout << intValue << endl; // OUTPUT: 123
    

    // string -> long
    string strLong = "999999";
    long longValue = stol(strLong);
    cout << longValue << endl;  

   // string -> long long
    string strLL = "123456789";
    long long llValue = stoll(strLL);
    cout << llValue << endl;

    // string -> float
    string strFloat = "3.14";
    float floatValue = stof(strFloat);
    cout << floatValue << endl;

    // string -> double
    string strDouble = "99.999";
    double doubleValue = stod(strDouble);
    cout << doubleValue << endl;

    // string -> bool
    string strBool = "1";
    bool boolValue = stoi(strBool);
    cout << boolalpha << boolValue << endl; // OUTPUT: true
    

    // string -> char
    string strChar = "A";
    char charValue = strChar[0];
    cout << charValue << endl; // OUTPUT: A
    

    /*
    =========================================================
        DIFFERENT DATA TYPES TO STRING CONVERSION
    =========================================================
    */

    // int -> string
    int number = 500;
    string intToStr = to_string(number);
    cout << intToStr << endl; // OUTPUT: "500"
    

    // float -> string
    float marks = 95.5;
    string floatToStr = to_string(marks);
    cout << floatToStr << endl;

    // double -> string
    double salary = 12345.678;
    string doubleToStr = to_string(salary);
    cout << doubleToStr << endl;

    // bool -> string
    bool flag = true;
    string boolToStr = flag ? "true" : "false";
    cout << boolToStr << endl;

    // char -> string
    char grade = 'A';
    string charToStr(1, grade); //1 number of time 'A' should appear in string
    cout << charToStr << endl;

    /*
    =========================================================
            STRINGSTREAM CONVERSIONS
    =========================================================
    */

    // int -> string using stringstream
    int value = 1000;

    stringstream ss1;

    ss1 << value;

    string converted = ss1.str();

    cout << converted << endl;

    // string -> int using stringstream
    string strNum = "2000";

    stringstream ss2(strNum);

    int convertedInt;

    ss2 >> convertedInt;

    cout << convertedInt << endl;

    /*
    =========================================================
                    ASCII CONVERSION
    =========================================================
    */

    // char -> int (ASCII)
    char ch = 'A';

    int ascii = ch;

    cout << ascii << endl;
    // OUTPUT: 65

    // int -> char
    int asciiNum = 66;

    char asciiChar = asciiNum;

    cout << asciiChar << endl;
    // OUTPUT: B

    /*
    =========================================================
                STRING <-> C-STRING
    =========================================================
    */

    // string -> c-string
    string normal = "Hello";

    const char *cstr = normal.c_str();

    cout << cstr << endl;

    // c-string -> string
    char arr[] = "World";

    string normalString = arr;

    cout << normalString << endl;

    return 0;
}