/*
===============================================================================
FILE HANDLING – WRITE OPERATIONS (COMPLETE)
-------------------------------------------------------------------------------
COVERS:
- File opening (constructor, open())
- Modes: ios::out, ios::app, ios::trunc, ios::binary
- Writing methods:
    • put()        → character by character
    • << operator  → word / line writing
    • loop usage   → char / word / line writing
    • string write → entire content
- Pointer functions:
    • tellp() → current write position
    • seekp() → move write pointer
===============================================================================
file.put('c') → character writing
file<<"word" → word writing
file<<line<<endl → line writing
fullFile<<all_content; → full content writing
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // =========================
    // 1. Constructor (ios::out)
    // =========================
    ofstream file1("constructor.txt");
    file1 << "Opened using constructor" << endl;
    file1.close();

    // =========================
    // 2. open() function
    // =========================
    ofstream file2;
    file2.open("open_function.txt", ios::out);
    file2 << "Opened using open()" << endl;
    file2.close();

    // =========================
    // 3. Append mode
    // =========================
    ofstream appFile;
    appFile.open("append.txt", ios::app);
    appFile << "New line added" << endl;
    appFile.close();

    // =========================
    // 4. Truncate mode
    // =========================
    ofstream truncFile("trunc.txt", ios::trunc);
    truncFile << "Old content removed" << endl;
    truncFile.close();

    // =========================
    // 5. Binary write
    // =========================
    ofstream binaryFile("number.bin", ios::binary);
    int num = 500;
    binaryFile.write((char *)&num, sizeof(num));
    binaryFile.close();

    // =========================
    // 6. put() function
    // =========================
    ofstream fout("put.txt");
    fout.put('A');
    fout.put('B');
    fout.put('C');
    fout.close();

    cout << "Characters written using put()" << endl;

    // -------------------------------------------------------------------------
    // 1. CHARACTER BY CHARACTER (LOOP)
    // -------------------------------------------------------------------------
    ofstream charFile("char.txt");

    string str = "ABCDEF";

    for (int i = 0; i < str.length(); i++)
    {
        charFile.put(str[i]); // write one character at a time
    }

    charFile.close();

    // -------------------------------------------------------------------------
    // 2. WORD BY WORD (LOOP)
    // -------------------------------------------------------------------------
    ofstream wordFile("word.txt");

    string words[] = {"Hello", "World", "C++"};

    for (int i = 0; i < 3; i++)
    {
        wordFile << words[i] << " ";
    }

    wordFile.close();

    // -------------------------------------------------------------------------
    // 3. LINE BY LINE (LOOP)
    // -------------------------------------------------------------------------
    ofstream lineFile("line.txt");

    string lines[] = {"First line", "Second line", "Third line"};

    for (int i = 0; i < 3; i++)
    {
        lineFile << lines[i] << endl;
    }

    lineFile.close();

    // -------------------------------------------------------------------------
    // 4. ENTIRE CONTENT (LOOP BUILD)
    // -------------------------------------------------------------------------
    ofstream fullFile("full.txt");

    string content = "";
    string data[] = {"ABC", "HELLO", "WORLD"};

    for (int i = 0; i < 3; i++)
    {
        content += data[i] + "\n"; // build full content
    }

    fullFile << content;

    fullFile.close();

    // =========================
    // 7. tellp()
    // =========================
    ofstream tp("tellp.txt");
    cout << "Initial put pointer: " << tp.tellp() << endl;

    tp << "HELLO";
    cout << "After writing HELLO: " << tp.tellp() << endl;

    tp.close();

    // =========================
    // 8. seekp()
    // =========================
    fstream sp("seekp.txt", ios::out | ios::in | ios::trunc);

    sp << "HELLO";
    sp.seekp(1, ios::beg); // move to index 1
    sp.put('A');           // overwrite

    sp.close();

    cout << "seekp() modification done" << endl;

    // =========================
    // SUMMARY
    // =========================
    cout << "\n===== WRITE SUMMARY =====\n";
    cout << "ofstream -> write\n";
    cout << "ios::out -> write mode\n";
    cout << "ios::app -> append\n";
    cout << "ios::trunc -> erase old content\n";
    cout << "ios::binary -> binary write\n";
    cout << "put() -> write one character\n";
    cout << "tellp() -> current write position\n";
    cout << "seekp() -> move write pointer\n";

    return 0;
}