#include<iostream>
using namespace std;

int main(){
     // -- for loop: when total no of iteratin is known ---
    for (int i = 0; i < 5; i++)
    {
        if (i == 1) continue;   // skip 1
        if (i == 3) break;      // stop at 3

        cout << "i = " << i << endl;
    }

    // -- WHILE: when total no of iteratin is not known --
    int j = 0;
    while (j < 2)
    {
        cout << "while: " << j++ << endl;
    }

    // -- DO-WHILE: if the code executed at least once --
    int k = 0;
    do
    {
        cout << "do: " << k++ << endl;
    } while (k < 1);

    // -- RANGE FOR --
    int arr[] = {1, 2};
    for (int v : arr)
        cout << "val: " << v << endl;

    return 0;   // exit program
}