/*
===============================================================================
FILE HANDLING – READ OPERATIONS (COMPLETE)
-------------------------------------------------------------------------------
COVERS:
- File reading using ifstream
- Reading methods:
    • get()        → character by character
    • getline()    → line by line
    • >> operator  → word by word
    • loop usage   → full file reading
- Pointer functions:
    • tellg() → current read position
    • seekg() → move read pointer
- Pointer directions:
    • ios::beg → from beginning
    • ios::cur → from current
    • ios::end → from end
- File checking:
    • is_open()

STREAM STATE (cin as boolean):
    cin.good() → no error
    cin.fail() → invalid input
    cin.bad()  → serious error
    cin.eof()  → end of input
===============================================================================
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ------------------ SAMPLE FILE ------------------
    ofstream temp("sample.txt");
    temp << "ABC\nHELLO\nWORLD";
    temp.close();

    // ------------------ get() ------------------
    ifstream fin("sample.txt");

    char ch;
    fin.get(ch);
    cout << "First char: " << ch << endl;

    fin.get(ch);
    cout << "Second char: " << ch << endl;

    fin.close();

    // ------------------ getline() ------------------
    ifstream lineFile("sample.txt");

    string line1;
    getline(lineFile, line1);
    cout << "First line: " << line1 << endl;

    getline(lineFile, line1);
    cout << "Second line: " << line1 << endl;

    lineFile.close();

    // ------------------ tellg() ------------------
    ifstream tg("sample.txt");

    cout << "Initial position: " << tg.tellg() << endl;
    tg.get(ch);
    cout << "After reading 1 char: " << tg.tellg() << endl;

    tg.close();

    // ------------------ seekg() ------------------
    ifstream sg("sample.txt");

    sg.seekg(2, ios::beg);   // move to index 2
    sg.get(ch);
    cout << "Character at index 2: " << ch << endl;

    sg.close();

    // ------------------ ios::cur ------------------
    ifstream curFile("sample.txt");

    curFile.get(ch);             // move to index 1
    curFile.seekg(2, ios::cur);  // move +2 → index 3
    curFile.get(ch);
    cout << "ios::cur char: " << ch << endl;

    curFile.close();

    // ------------------ ios::end ------------------
    ifstream endFile("sample.txt");

    endFile.seekg(-1, ios::end); // last character
    endFile.get(ch);
    cout << "Last char: " << ch << endl;

    endFile.close();

    // ------------------ is_open() ------------------
    ifstream check("sample.txt");

    if (check.is_open())
        cout << "File opened successfully\n";
    else
        cout << "File open failed\n";

    check.close();

    // ------------------ FULL FILE (CHAR BY CHAR) ------------------
    ifstream charFile("sample.txt");

    char c;
    cout << "\nFull file (char by char): ";
    while (charFile.get(c))
    {
        cout << c;
    }
    charFile.close();

    // ------------------ WORD BY WORD ------------------
    ifstream wordFile("sample.txt");

    string word;
    cout << "\n\nWord by word:\n";

    while (wordFile >> word)
    {
        cout << word << endl;
    }
    wordFile.close();

    // ------------------ LINE BY LINE (FULL FILE) ------------------
    ifstream file("sample.txt");

    string line2;
    cout << "\nLine by line:\n";

    while (getline(file, line2))
    {
        cout << line2 << endl;
    }
    file.close();

    // ------------------ INPUT (WORD BY WORD) ------------------
    string inputWord;
    cout << "\nEnter words (Ctrl+D / Ctrl+Z to stop):\n";

    while (cin >> inputWord)
    {
        cout << inputWord << endl;
    }

    // ------------------ INPUT (LINE BY LINE) ------------------
    cin.clear();              // reset after previous loop
    cin.ignore(1000, '\n');   // clear buffer

    string inputLine;
    cout << "\nEnter lines (Ctrl+D / Ctrl+Z to stop):\n";

    while (getline(cin, inputLine))
    {
        cout << inputLine << endl;
    }

    // ------------------ SUMMARY ------------------
    cout << "\n===== READ SUMMARY =====\n";
    cout << "get()      -> character reading\n";
    cout << "getline()  -> line reading\n";
    cout << ">>         -> word reading\n";
    cout << "tellg()    -> pointer position\n";
    cout << "seekg()    -> move pointer\n";
    cout << "ios::beg   -> beginning\n";
    cout << "ios::cur   -> current\n";
    cout << "ios::end   -> end\n";

    return 0;
}