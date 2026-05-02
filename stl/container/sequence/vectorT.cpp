/*
vector stores dynamic-size elements of same data type

Header file:
#include <vector>

Syntax:
vector<data_type> vector_name;

Example:
vector<int> v;
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ================= CREATE =================

    vector<int> v; // empty vector

    vector<int> v2 = {10, 20, 30}; // vector with values

    vector<int> v3(5); // vector of size 5 with default value 0

    vector<int> v4(5, 100); // vector of size 5 with value 100

    cout << "v4 elements: ";

    for (int x : v4)
    {
        cout << x << " ";
    }

    // Output: 100 100 100 100 100

    cout << endl
         << endl;

    // push_back() inserts element at end

    v2.push_back(40);

    v2.push_back(50);

    cout << "After push_back(): ";

    for (int x : v2)
    {
        cout << x << " ";
    }

    // Output: 10 20 30 40 50

    cout << endl
         << endl;

    // insert() inserts element at specific position

    v2.insert(v2.begin() + 1, 99);

    cout << "After insert(): ";

    for (int x : v2)
    {
        cout << x << " ";
    }

    // Output: 10 99 20 30 40 50

    cout << endl
         << endl;

    // ================= READ =================

    cout << "v2[0]: " << v2[0] << endl; // [] accesses element using index
    // Output: v2[0]: 10

    cout << "v2.at(2): " << v2.at(2) << endl; // at() safely accesses element
    // Output: v2.at(2): 20

    cout << "v2.front(): " << v2.front() << endl; // front() returns first element
    // Output: v2.front(): 10

    cout << "v2.back(): " << v2.back() << endl; // back() returns last element
    // Output: v2.back(): 50

    cout << "v2.size(): " << v2.size() << endl; // size() returns total elements
    // Output: v2.size(): 6

    cout << "v2.capacity(): " << v2.capacity() << endl; // capacity() returns allocated memory
    // Output: compiler dependent

    cout << "v2.empty(): " << v2.empty() << endl; // empty() checks vector is empty or not
    // Output: v2.empty(): 0

    cout << endl;

    // ================= UPDATE =================

    v2[1] = 500; // update value using index

    cout << "After update: ";

    for (int x : v2)
    {
        cout << x << " ";
    }

    // Output: 10 500 20 30 40 50

    cout << endl
         << endl;

    // ================= DELETE =================

    v2.pop_back(); // pop_back() removes last element

    cout << "After pop_back(): ";

    for (int x : v2)
    {
        cout << x << " ";
    }

    // Output: 10 500 20 30 40

    cout << endl
         << endl;

    // erase() removes element from specific position

    v2.erase(v2.begin() + 2);

    cout << "After erase(): ";

    for (int x : v2)
    {
        cout << x << " ";
    }

    // Output: 10 500 30 40

    cout << endl
         << endl;

    // clear() removes all elements

    v2.clear();

    cout << "Size after clear(): " << v2.size() << endl;
    // Output: Size after clear(): 0

    cout << "v2.empty(): " << v2.empty() << endl;
    // Output: v2.empty(): 1

    cout << endl;

    // ================= 2D VECTOR =================

    vector<vector<int>> matrix =
        {
            {1, 2, 3},
            {4, 5, 6}};

    cout << "2D vector:" << endl;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    /*
    Output:
    1 2 3
    4 5 6
    */

    return 0;
}