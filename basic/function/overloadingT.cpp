/*
    any modification of pareter having same function_name is called function overloading
    condition: different no. of argument (or) type of argument
*/
#include<iostream>
using namespace std;

// 🔷 Function 1: two integers
int add(int a, int b){
    return a + b;
}

// 🔷 Function 2: three integers
int add(int a, int b, int c){
    return a + b + c;
}

// 🔷 Function 3: two doubles
double add(double a, double b){
    return a + b;
}

int main(){

    cout << "Add 2 integers: " << add(2, 3) << endl;        // calls int, int
    cout << "Add 3 integers: " << add(1, 2, 3) << endl;     // calls int, int, int
    cout << "Add 2 doubles: " << add(2.5, 3.5) << endl;     // calls double, double

    return 0;
}