#include <iostream>
using namespace std;


int main()
{
    int x = 2;

    // -- if(compulsory) / else if(optinal) / else(optional) --
    if (x < 0)
        cout << "Negative\n";
    else if (x == 0)
        cout << "Zero\n";
    else
        cout << "Positive\n";

    // -- SWITCH --
    switch (x) //x must convertable to int
    {
        case 1: cout << "One\n"; break; //case lebels cant be variable,(either constant or rvalue)
        case 2: cout << "Two\n"; break;
        default: cout << "Other\n"; //default can be placed anywhere
    }

   
}