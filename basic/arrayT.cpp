/*
Accessing arr[m][n][o][p] using pointer:

arr[i][j][k][l] : *(*(*(*(arr + i) + j) + k) + l)

Rule:
For each dimension → add (+ index): to get its address
At the end → apply * (dereference) same number of times
*/

#include<iostream>
using namespace std;

// 🔷 FUNCTION 1: WITHOUT POINTERS
void arrayWithOutPointer(){
    int ar[3]; // implictly: {0,0,0}
    ar[2]=3; //updating array element
    cout << ar[0] << endl; //Access using normal indexing

    int arr[] = {1, 2, 3}; //Declaration + Initialization: size automatically infered
    cout << "Normal Array Access using for:" << endl;
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
    }
    cout << "Normal Array Access using for-in:" << endl;
    for(int value : arr){
        cout << value << " ";
    }
    cout << endl;

    // 🔹 2D Array
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "2D Array Access:" << endl;
    cout << matrix[0][1] << endl; // 2
    
}



// 🔷 FUNCTION 2: WITH POINTERS
void arrayWithPointer(){

    int arr[3] = {1, 2, 3};

    // 🔹 Array behaves like pointer
    cout << "Using Array as Pointer:" << endl;
    cout << arr << endl;      // address of 1st element
    cout << *arr << endl;     // arr[0]
    cout << *(arr + 1) << endl; //arr[1]
    

    // 🔹 Pointer with array
    int* pArr = arr;
    cout << "Pointer Access:" << endl;
    cout << *pArr << endl; //arr[0]
    cout << *(pArr + 1) << endl; //arr[1]

    // 🔹 Array of pointers
    int x = 100, y = 200, z = 300;
    int* ptrArr[3] = { &x, &y, &z };
    cout << "Array of Pointers:" << endl;
    cout << *ptrArr[0] << endl;


    // 🔹 Pointer to array
    int (*ptrToArr)[3] = &arr;
    cout << "Pointer to Array:" << endl;
    cout << (*ptrToArr)[0] << endl;
    cout << (*ptrToArr)[1] << endl;

    // 🔹 2D Array pointer access
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "2D Pointer Access:" << endl;
    cout << *(*(matrix + 1) + 2) << endl; //matrix[1][2]

    // 🔹 Pointer to 2D array
    int (*pMat)[3] = matrix;

    cout << pMat[0][0] << endl;
    cout << pMat[1][2] << endl;

    // 🔹 Double pointer simulation
    int* rows[2];
    rows[0] = matrix[0];
    rows[1] = matrix[1];

    cout << "Double Pointer Style:" << endl;
    cout << rows[1][1] << endl; // 5
}


int main(){

    cout << "===== WITHOUT POINTER =====" << endl;
    arrayWithOutPointer();

    cout << "\n===== WITH POINTER =====" << endl;
    arrayWithPointer();

    return 0;
}