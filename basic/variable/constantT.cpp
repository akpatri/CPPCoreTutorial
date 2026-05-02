/*
    2 ways: using const, macro
        const: const <datatype> <variable_name>= <value>; or <datatype> const <variable_name> =<value>
        macro: #define <identifier> <value>
    it should be initilized while declaration, and cant be changed further
    Best practice: constant variable should be in uppcase

*/
#include<iostream>
using namespace std;
#define PI 3.14 // macro constant → no type, replaced before compilation

int main(){
    const int var1=10;
    int const var2=20;
    cout<<"macro constant: "<<PI<<endl;
    cout<<"using const"<<var1<<var2<<endl;
}