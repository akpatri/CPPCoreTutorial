/*
Header File: #include <fstream>
Namespace: using namespace std;

File Stream Classes
-------------------
ifstream -> input file stream -> used for reading file
default mode -> ios::in

ofstream -> output file stream -> used for writing file
default mode -> ios::out

fstream -> input + output file stream -> used for both reading and writing
default mode -> ios::in | ios::out

Opening a File
--------------
1. Using constructor: ofstream fout("data.txt");

2. Using open():
ofstream fout;
fout.open("data.txt");

3. Syntax: object.open(filename, mode);
Example: file.open("abc.txt", ios::out | ios::app);

File Open Modes
----------------
1. ios::in      -> open file for reading
2. ios::out     -> open file for writing, creates file if not present, old content may be removed
3. ios::app     -> append data at end only
4. ios::ate     -> pointer moves to end immediately after opening, writing can still happen anywhere
5. ios::trunc   -> delete old content of file
6. ios::binary  -> open file in binary format instead of text format

Combining Modes
----------------
Use | operator to combine modes
Example:
ios::in | ios::out
ios::out | ios::binary
ios::in | ios::out | ios::app

File Pointers
---------------
get pointer -> used while reading from file
put pointer -> used while writing into file

Special Functions
------------------
get(ch)        -> read single character from file
put(ch)        -> write single character into file
getline()      -> read complete line from file
read()         -> read binary data
write()        -> write binary data
tellg()        -> returns current position of get pointer
tellp()        -> returns current position of put pointer
seekg(pos)     -> move get pointer to given position i.e. while reading
seekp(pos)     -> move put pointer to given position i.e. while writing
close()        -> close file
is_open()      -> check whether file opened successfully

Pointer Position Constants
---------------------------
ios::beg -> beginning of file
ios::cur -> current pointer position
ios::end -> end of file

Important Notes
----------------
ifstream opens file in read mode automatically.
ofstream opens file in write mode automatically.
fstream opens file in read + write mode automatically.
ofstream with ios::out usually removes old content.
ios::app always writes at end of file.
Binary mode is mainly used for images, audio, video, etc.
Always close file after use.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // opening file using constructor
    ofstream file1("constructor.txt");           // file opened immediately
    file1 << "Opened using constructor" << endl; // write data
    file1.close();                               // close file

    // opening file using open()
    ofstream file2;                            // create object
    file2.open("open_function.txt", ios::out); // open file manually
    file2 << "Opened using open()" << endl;    // write data
    file2.close();                             // close file

    // append mode
    ofstream appFile;                     // create object
    appFile.open("append.txt", ios::app); // open in append mode
    appFile << "new line added" << endl;  // data added at end
    appFile.close();                      // close file

    // trunc mode
    ofstream truncFile("trunc.txt", ios::trunc); // old content deleted
    truncFile << "old content removed" << endl;  // new data written
    truncFile.close();                           // close file

    // binary mode
    ofstream binaryFile("number.bin", ios::binary); // open binary file
    int num = 500;                                  // integer data
    binaryFile.write((char *)&num, sizeof(num));    // write binary data
    binaryFile.close();                             // close file

    // get() function
    ofstream temp("get.txt"); // create sample file
    temp << "ABC";
    temp.close();
    ifstream fin("get.txt");                     // open file for reading
    char ch;                                     // character variable
    fin.get(ch);                                 // read one character
    cout << "First character : " << ch << endl;  // print character
    fin.get(ch);                                 // read next character
    cout << "Second character : " << ch << endl; // print character
    fin.close();                                 // close file

    // put() function
    ofstream fout("put.txt"); // open file
    // write single characters
    fout.put('A');
    fout.put('B');
    fout.put('C');
    fout.close(); // close file
    cout << "Characters written using put()" << endl;

    // tellg()
    ifstream tg("get.txt");                                    // open file for reading
    cout << "Initial get pointer : " << tg.tellg() << endl;    // current position before reading
    tg.get(ch);                                                // read one character
    cout << "After reading one char : " << tg.tellg() << endl; // position after reading one character
    tg.close();                                                // close file

    // tellp()
    ofstream tp("tellp.txt");                               // open file
    cout << "Initial put pointer : " << tp.tellp() << endl; // current position
    tp << "HELLO";                                          // write data
    cout << "After writing HELLO : " << tp.tellp() << endl; // position after writing
    tp.close();                                             // close file

    // seekg()
    ifstream sg("get.txt");                          // open file
    sg.seekg(1, ios::beg);                           // move get pointer to second character
    sg.get(ch);                                      // read character
    cout << "Character at index 1 : " << ch << endl; // print character
    sg.close();                                      // close file

    // seekp()
    fstream sp("seekp.txt", ios::out | ios::in | ios::trunc); // create file
    sp << "HELLO";                                            // write initial data
    sp.seekp(1, ios::beg);                                    // move put pointer to index 1
    sp.put('A');                                              // overwrite character
    sp.seekg(0);                                              // move pointer to beginning for reading
    string data;                                              // string variable
    sp >> data;                                               // read complete word
    cout << "Modified text : " << data << endl;               // print modified data
    sp.close();                                               // close file

    // ios::beg
    ifstream begFile("get.txt");                   // open file
    begFile.seekg(2, ios::beg);                    // move pointer from beginning
    begFile.get(ch);                               // read character
    cout << "ios::beg character : " << ch << endl; // print character
    begFile.close();                               // close file

    // ios::cur
    ifstream curFile("get.txt");                   // open file
    curFile.get(ch);                               // read one character
    curFile.seekg(1, ios::cur);                    // move one step forward from current position
    curFile.get(ch);                               // read character
    cout << "ios::cur character : " << ch << endl; // print character
    curFile.close();                               // close file

    // ios::end
    ifstream endFile("get.txt");                   // open file
    endFile.seekg(-1, ios::end);                   // move one step backward from end
    endFile.get(ch);                               // read character
    cout << "ios::end character : " << ch << endl; // print character
    endFile.close();                               // close file

    // checking file open success
    ifstream check;        // create object
    check.open("get.txt"); // try opening file
    // check success
    if (check.is_open())
    {
        cout << "File opened successfully" << endl;
    }
    else
    {
        cout << "File opening failed" << endl;
    }
    check.close(); // close file

    /*********************************************************************
        SUMMARY
    *********************************************************************/

    cout << endl;

    cout << "===== SUMMARY =====" << endl;

    cout << "ifstream  -> read" << endl;
    cout << "ofstream  -> write" << endl;
    cout << "fstream   -> read + write" << endl;

    cout << endl;

    cout << "ios::in     -> read mode" << endl;
    cout << "ios::out    -> write mode" << endl;
    cout << "ios::app    -> append mode" << endl;
    cout << "ios::trunc  -> erase old content" << endl;
    cout << "ios::binary -> binary mode" << endl;

    cout << endl;

    cout << "get()   -> read one char" << endl;
    cout << "put()   -> write one char" << endl;

    cout << "tellg() -> get pointer position" << endl;
    cout << "tellp() -> put pointer position" << endl;

    cout << "seekg() -> move get pointer" << endl;
    cout << "seekp() -> move put pointer" << endl;

    cout << endl;

    cout << "ios::beg -> beginning" << endl;
    cout << "ios::cur -> current position" << endl;
    cout << "ios::end -> end position" << endl;

    return 0;
}