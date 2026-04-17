#include <iostream> //for standard libarary
#include "MyLib.h" //to include custom lib

using namespace std;
using namespace MyLib;

int main()
{
    int a = 10, b = 5;

    cout << "Add: " << add(a, b) << endl;
    cout << "Sub: " << sub(a, b) << endl;
    cout << "Mul: " << mul(a, b) << endl;

    return 0;
}

//compilation: g++ main.cpp MyLib.cpp -o app