/*
===============================================================================
FILE HANDLING – FILE POINTERS (CURSOR OPERATIONS)
-------------------------------------------------------------------------------
COVERS:
- tellg() → get pointer position (reading)
- tellp() → put pointer position (writing)
- seekg() → move read pointer
- seekp() → move write pointer
- Pointer directions:
    • ios::beg → from beginning
    • ios::cur → from current position
    • ios::end → from end
===============================================================================
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;

    // ------------------ SAMPLE FILE ------------------
    ofstream init("sample.txt");
    init << "ABCDEF";          // file content
    init.close();

    // ------------------ tellg() ------------------
    ifstream tg("sample.txt");

    cout << "Initial get pointer : " << tg.tellg() << endl; // usually 0

    tg.get(ch);  // read 1 character
    cout << "After reading one char : " << tg.tellg() << endl; // moves forward

    tg.close();

    // ------------------ tellp() ------------------
    ofstream tp("tellp.txt");

    cout << "Initial put pointer : " << tp.tellp() << endl; // usually 0

    tp << "HELLO";   // write 5 characters
    cout << "After writing HELLO : " << tp.tellp() << endl; // should be 5

    tp.close();

    // ------------------ seekg() ------------------
    ifstream sg("sample.txt");

    sg.seekg(2, ios::beg);   // move to index 2 (0-based)
    sg.get(ch);
    cout << "seekg (index 2) : " << ch << endl; // prints 'C'

    sg.close();

    // ------------------ seekp() ------------------
    fstream sp("seekp.txt", ios::in | ios::out | ios::trunc);

    sp << "HELLO";           // initial content
    sp.seekp(1, ios::beg);   // move to index 1
    sp.put('A');             // overwrite 'E' → HALLO

    sp.seekg(0);             // move to beginning for reading
    string data;
    sp >> data;

    cout << "After seekp modification : " << data << endl;

    sp.close();

    // ------------------ ios::beg ------------------
    ifstream begFile("sample.txt");

    begFile.seekg(3, ios::beg); // index 3
    begFile.get(ch);
    cout << "ios::beg : " << ch << endl; // 'D'

    begFile.close();

    // ------------------ ios::cur ------------------
    ifstream curFile("sample.txt");

    curFile.get(ch);              // index 0 → 1
    curFile.seekg(2, ios::cur);   // move +2 → index 3
    curFile.get(ch);
    cout << "ios::cur : " << ch << endl; // 'D'

    curFile.close();

    // ------------------ ios::end ------------------
    ifstream endFile("sample.txt");

    endFile.seekg(-1, ios::end);  // last character
    endFile.get(ch);
    cout << "ios::end : " << ch << endl; // 'F'

    endFile.close();

    return 0;
}