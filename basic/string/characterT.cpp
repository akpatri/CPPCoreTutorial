/*
===============================================================================
C++ CHARACTER MANIPULATION FUNCTIONS ( <cctype> ) - SIGNATURE REFERENCE
===============================================================================

HEADER:
#include <cctype>

NOTE:
→ All functions take int (character promoted to int)
→ Classification → returns int (0 or non-zero)
→ Conversion     → returns int (converted character)

-------------------------------------------------------------------------------
CHARACTER CLASSIFICATION (SIGNATURES)
-------------------------------------------------------------------------------

int isalnum(int ch);   → true if letter OR digit

int isalpha(int ch);   → true if alphabet (A-Z, a-z)

int isdigit(int ch);   → true if digit (0-9)

int isxdigit(int ch);  → true if hexadecimal digit (0-9, A-F, a-f)

int islower(int ch);   → true if lowercase letter

int isupper(int ch);   → true if uppercase letter

int isspace(int ch);   → true if whitespace (space, tab, newline, etc.)

int isblank(int ch);   → true if space or tab

int iscntrl(int ch);   → true if control character

int isprint(int ch);   → true if printable (including space)

int isgraph(int ch);   → true if printable (excluding space)

int ispunct(int ch);   → true if punctuation

-------------------------------------------------------------------------------
CHARACTER CONVERSION (SIGNATURES)
-------------------------------------------------------------------------------

int tolower(int ch);   → returns lowercase equivalent if possible

int toupper(int ch);   → returns uppercase equivalent if possible

-------------------------------------------------------------------------------
PARAMETER + RETURN BEHAVIOR
-------------------------------------------------------------------------------

int ch
→ should be:
     unsigned char value OR EOF
→ passing signed char with negative value → undefined behavior

return (classification)
→ 0      → false
→ non-zero → true

return (conversion)
→ converted character (as int)
→ unchanged if no conversion possible

-------------------------------------------------------------------------------
SAFE USAGE RULE
-------------------------------------------------------------------------------

isalnum((unsigned char)ch);
tolower((unsigned char)ch);

→ prevents undefined behavior for negative char values

===============================================================================
*/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    // ------------------- CLASSIFICATION -------------------

    cout << "\nCharacter Analysis:\n";

    if (isalnum((unsigned char)ch))   // checks letter OR digit
        cout << "Alphanumeric\n";

    if (isalpha((unsigned char)ch))   // checks alphabet
        cout << "Alphabet\n";

    if (isdigit((unsigned char)ch))   // checks digit
        cout << "Digit\n";

    if (islower((unsigned char)ch))   // checks lowercase
        cout << "Lowercase letter\n";

    if (isupper((unsigned char)ch))   // checks uppercase
        cout << "Uppercase letter\n";

    if (isspace((unsigned char)ch))   // checks whitespace
        cout << "Whitespace\n";

    if (ispunct((unsigned char)ch))   // checks punctuation
        cout << "Punctuation\n";

    if (isxdigit((unsigned char)ch))  // checks hex digit
        cout << "Hexadecimal digit\n";

    if (isprint((unsigned char)ch))   // printable character
        cout << "Printable character\n";

    if (iscntrl((unsigned char)ch))   // control character
        cout << "Control character\n";


    // ------------------- CONVERSION -------------------

    cout << "\nConversions:\n";

    char lower = tolower((unsigned char)ch);   // convert to lowercase
    char upper = toupper((unsigned char)ch);   // convert to uppercase

    cout << "Lowercase: " << lower << "\n";
    cout << "Uppercase: " << upper << "\n";


    // ------------------- EXTRA DEMO -------------------

    // Demonstrating behavior with a sample string
    string text = "AbC123! ";

    cout << "\nProcessing string: " << text << "\n";

    for (char c : text)   // iterate each character
    {
        if (isalpha((unsigned char)c))
            cout << c << " → is alphabet\n";

        if (isdigit((unsigned char)c))
            cout << c << " → is digit\n";

        if (ispunct((unsigned char)c))
            cout << c << " → is punctuation\n";
    }

    return 0;
}