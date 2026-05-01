#include <iostream>
#include <cstdlib> // Required for malloc, calloc, realloc, free
using namespace std;

int main()
{

    /* -------------------- malloc -------------------- */
    /*
    Syntax: pointer = (type*) malloc(size_in_bytes);
    Explanation:
        - Allocates a continious block of memory of given size (in bytes).
        - Returns a void pointer → must typecast.
        - Memory is NOT initialized (contains garbage values ❌).
        - Takes ONLY 1 argument → total size in bytes.

        Key Difference:
        - Fastest allocation
        - No default initialization

        Use Case:
        - When you will manually assign values later.
    */
    int size = 5;

    int *p1 = (int *)malloc(size * sizeof(int)); // allocate memory for 5 integers

    if (p1 == NULL)
    {
        cout << "malloc failed\n";
    }
    else
    {
        cout << "malloc allocated memory\n";
    }

    /* -------- CREATE (initialize malloc memory) -------- */
    for (int i = 0; i < size; i++)
    {
        p1[i] = (i + 1) * 10; // 10,20,30,40,50
    }

    /* -------- READ -------- */
    cout << "\n[malloc READ]\n";
    for (int i = 0; i < size; i++)
    {
        cout << p1[i] << " ";
    }
    cout << endl;

    /* -------- UPDATE -------- */
    p1[2] = 999;

    cout << "[malloc UPDATE]\n";
    for (int i = 0; i < size; i++)
    {
        cout << p1[i] << " ";
    }
    cout << endl;

    /* -------------------- calloc -------------------- */
    /*
    Syntax: pointer = (type*) calloc(number_of_elements, size_of_each_element);
    Explanation:
        - Allocates memory for multiple elements at continious location i.e same as malloc
        - Initializes all bytes to 0 (✅ zero-initialized).
        - Takes 2 arguments → number of elements + size of each element.

        Key Difference:
        - Slower than malloc (because of initialization)
        - Safer (no garbage values)
        - Directly usable without manual initialization

        Use Case:
        - When you need clean (zeroed) memory.
    */

    int *p2 = (int *)calloc(size, sizeof(int)); // allocate 5 integers, initialized to 0

    if (p2 == NULL)
    {
        cout << "calloc failed\n";
    }
    else
    {
        cout << "calloc allocated memory\n";
    }

    /* -------- READ (calloc gives 0s) -------- */
    cout << "\n[calloc READ]\n";
    for (int i = 0; i < size; i++)
    {
        cout << p2[i] << " "; // all 0
    }
    cout << endl;

    /* -------- UPDATE -------- */
    for (int i = 0; i < size; i++)
    {
        p2[i] = i + 1; // 1,2,3,4,5
    }

    cout << "[calloc UPDATE]\n";
    for (int i = 0; i < size; i++)
    {
        cout << p2[i] << " ";
    }
    cout << endl;

    /* -------------------- realloc -------------------- */
    /*
    Syntax: pointer = (type*) realloc(existing_pointer, new_size_in_bytes);
    Explanation:
        - Resizes previously allocated memory (malloc/calloc).
        - Takes 2 arguments → existing pointer + new size.
        - May move memory to a new location.
        - Old data is preserved (up to min(old_size, new_size)).
        - New memory (if expanded) is NOT initialized ❌.

        Key Difference:
        - Used for resizing (not initial allocation)
        - Can expand or shrink memory dynamically

        Use Case:
        - When size requirement changes at runtime.
    */
    int newSize = 10;

    /* -------- SAFE REALLOC -------- */
    int *temp = (int *)realloc(p1, newSize * sizeof(int));

    if (temp == NULL)
    {
        cout << "realloc failed\n";
    }
    else
    {
        p1 = temp;
        cout << "realloc resized memory\n";
    }

    /* -------- CREATE NEW ELEMENTS AFTER REALLOC -------- */
    for (int i = size; i < newSize; i++)
    {
        p1[i] = (i + 1) * 10; // fill new memory
    }

    size = newSize;

    /* -------- READ AFTER REALLOC -------- */
    cout << "\n[realloc READ]\n";
    for (int i = 0; i < size; i++)
    {
        cout << p1[i] << " ";
    }
    cout << endl;

    /* -------- DELETE (LOGICAL DELETE) -------- */
    int deleteIndex = 3;

    for (int i = deleteIndex; i < size - 1; i++)
    {
        p1[i] = p1[i + 1];
    }

    size--;

    cout << "[DELETE after realloc]\n";
    for (int i = 0; i < size; i++)
    {
        cout << p1[i] << " ";
    }
    cout << endl;

    /* -------------------- free -------------------- */
    /*
    Syntax: free(pointer);
    Explanation:
        - Deallocates memory allocated by malloc/calloc/realloc.
        - Prevents memory leaks.
        - Does not set pointer to NULL automatically (you must do it).
        Use Case:
        - Always required after dynamic allocation.
    */

    free(p1);
    free(p2);

    p1 = NULL;
    p2 = NULL;

    cout << "\nMemory freed successfully\n";

    return 0;
}