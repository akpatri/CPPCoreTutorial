#include <iostream>
using namespace std;

int x = 100; // Global variable;

int main() {
    int x = 50;// Local variable (same name → shadows global)
    cout << "Local x: " << x << endl;      // refers to local variable
    cout << "Global x: " << ::x << endl;   // scope resolution → global variable
    return 0;
}