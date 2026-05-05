/*
#include <regex> → Enables regex library (C++11+)
-------------------------------------------------------------------------------
CORE TYPES
-------------------------------------------------------------------------------
regex re(const string& pattern, syntax_option_type flags = ECMAScript);
→ const string& pattern : read-only reference (no copy, accepts lvalue/rvalue)
→ flags                : enum value (passed by value)

smatch m; → match result container (stores full match + capturing groups)

-------------------------------------------------------------------------------
MATCH FUNCTIONS
-------------------------------------------------------------------------------

bool regex_match(const string& str, const regex& re); → FULL string must match
→ const string& str : read-only input (no modification)
→ const regex& re   : compiled pattern (no copy) 

bool regex_match(const string& str, smatch& m, const regex& re);
→ smatch& m : non-const reference (output parameter, must be variable)
→ stores full match + groups

bool regex_search(const string& str, const regex& re);
→ returns true if ANY substring matches

bool regex_search(const string& str, smatch& m, const regex& re);
→ smatch& m : stores FIRST match + capturing groups
→ used for extraction

string regex_replace(const string& str, const regex& re, const string& fmt);
→ const string& fmt : replacement string (supports $1, $2...)
→ returns NEW string (original unchanged)

-------------------------------------------------------------------------------
MATCH RESULT (smatch)
-------------------------------------------------------------------------------

m.size()        → size_t (total matches: full + groups)
m.empty()       → bool (no match)
m[0]            → full match
m[i]            → i-th group
m.str(i)        → returns string value
m.position(i)   → index of match
m.length(i)     → length of match
m.prefix()      → part before match
m.suffix()      → part after match

-------------------------------------------------------------------------------
ITERATORS (HIGH-LEVEL USAGE)
-------------------------------------------------------------------------------

sregex_iterator it(str.begin(), str.end(), re);
→ used to LOOP over all matches in a string
→ each iteration gives one match (as smatch)
→ access:
     (*it)[0] → full match
     (*it)[i] → capturing groups

sregex_iterator end;
→ marks end of iteration
→ used as loop condition (it != end)

-------------------------------------------------------------------------------

sregex_token_iterator it(str.begin(), str.end(), re, submatch);
→ used to EXTRACT specific parts from string

→ submatch meaning:
     0  → full matches
     n  → nth capturing group
    -1  → non-matching parts (used for splitting)

→ each iteration gives string (not smatch)

sregex_token_iterator end;
→ marks end of iteration

USAGE SUMMARY
--------------
sregex_iterator
→ use when you need:
   - all matches
   - access to groups, positions, full match object

sregex_token_iterator
→ use when you need:
   - split string
   - extract specific group only
   - simple string output


-------------------------------------------------------------------------------
FLAGS (syntax_option_type - passed by value)
-------------------------------------------------------------------------------

icase      → ignore case

nosubs     → disable capturing groups

optimize   → faster matching (slower compile)

collate    → locale-based comparison

ECMAScript → default syntax

basic / extended / awk / grep / egrep → alternate grammars

multiline  → ^ and $ per line

dotall     → '.' matches newline

-------------------------------------------------------------------------------
MATCH FLAGS (match_flag_type - passed by value)
-------------------------------------------------------------------------------

match_default     → default behavior

match_not_bol     → not beginning of line

match_not_eol     → not end of line

match_not_null    → no empty matches

match_continuous  → must match from start

match_prev_avail  → previous character exists

-------------------------------------------------------------------------------
KEY UNDERSTANDING
-------------------------------------------------------------------------------

const T&  → read-only reference (no copy, accepts lvalue + rvalue)

T&        → modifiable reference (must pass variable, used for output)

T (value) → copied (used for small types like int, enum)

iterator  → object behaving like pointer (used to traverse string)

===============================================================================
*/

#include <iostream>
#include <regex>
using namespace std;

int main()
{
    cout << "===== C++ REGEX DEMO =====\n\n";

    // 1. FULL STRING MATCH ---------------------------------------------

    string text1 = "12345"; // input string
    regex pattern1("\\d+"); // \d+ → one or more digits

    if (regex_match(text1, pattern1)) // checks entire string
        cout << "1. Full match (digits): PASS\n";
    else
        cout << "1. Full match: FAIL\n";

    // 2. PARTIAL MATCH (SEARCH) ----------------------------------------

    string text2 = "Order ID: 5678"; // contains digits inside text
    smatch match2;                   // object to store match result
    regex pattern2("\\d+");          // digit pattern

    if (regex_search(text2, match2, pattern2))            // finds first occurrence
        cout << "2. Found number: " << match2[0] << "\n"; // full match

    // 3. EMAIL VALIDATION ----------------------------------------------

    string email = "test@mail.com";

    regex emailPattern("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    // ^ start
    // [\w.-]+ username
    // @ symbol
    // domain + . + extension
    // $ end

    if (regex_match(email, emailPattern))
        cout << "3. Valid Email\n";
    else
        cout << "3. Invalid Email\n";

    // 4. CAPTURING GROUPS ----------------------------------------------

    string data = "Name: John Age: 25";
    smatch match4;

    regex pattern4("Name: (\\w+) Age: (\\d+)");
    // (\\w+) → group 1 → Name
    // (\\d+) → group 2 → Age

    if (regex_search(data, match4, pattern4))
    {
        cout << "4. Full Match: " << match4[0] << "\n"; // whole match
        cout << "   Name: " << match4[1] << "\n";       // group 1
        cout << "   Age : " << match4[2] << "\n";       // group 2
    }

    // 5. REPLACE TEXT --------------------------------------------------

    string text5 = "Hello 123 World 456";
    regex pattern5("\\d+"); // digits

    string replaced = regex_replace(text5, pattern5, "#");
    // replaces every number with '#'

    cout << "5. Replace digits: " << replaced << "\n";

    // 6. ITERATE MULTIPLE MATCHES --------------------------------------

    string text6 = "A1 B22 C333";
    regex pattern6("\\d+"); // find all numbers

    sregex_iterator it6(text6.begin(), text6.end(), pattern6); // start iterator
    sregex_iterator end6;                                      // end iterator

    cout << "6. All numbers: ";

    for (; it6 != end6; ++it6)     // loop through all matches
        cout << it6->str() << " "; // print each match

    cout << "\n";

    // 7. SPLIT STRING USING REGEX --------------------------------------

    string text7 = "C++ STL regex powerful";
    regex pattern7("\\s+"); // one or more spaces

    // -1 → return NON-matching parts (used for splitting)
    sregex_token_iterator it7(text7.begin(), text7.end(), pattern7, -1);
    sregex_token_iterator end7;

    cout << "7. Split words:\n";

    for (; it7 != end7; ++it7)
        cout << "   " << *it7 << "\n"; // each token (word)

    // 8. DATE FORMAT CHANGE --------------------------------------------

    string date = "25/12/2024";
    regex pattern8("(\\d{2})/(\\d{2})/(\\d{4})");

    // $1 = day, $2 = month, $3 = year
    string newDate = regex_replace(date, pattern8, "$3-$2-$1");

    cout << "8. Formatted Date: " << newDate << "\n";

    // 9. PHONE NUMBER VALIDATION ---------------------------------------

    string phone = "9876543210";

    regex pattern9("^[6-9]\\d{9}$");
    // starts with 6-9
    // followed by 9 digits

    if (regex_match(phone, pattern9))
        cout << "9. Valid Phone Number\n";
    else
        cout << "9. Invalid Phone Number\n";

    // 10. WORDS STARTING WITH 'C' --------------------------------------

    string text10 = "C++ Code Compile Run";
    regex pattern10("\\bC\\w*");
    // \b → word boundary
    // C → starts with C
    // \w* → rest of word

    sregex_iterator it10(text10.begin(), text10.end(), pattern10);
    sregex_iterator end10;

    cout << "10. Words starting with C: ";

    for (; it10 != end10; ++it10)
        cout << it10->str() << " ";

    cout << "\n";

    cout << "\n===== END OF DEMO =====\n";

    return 0;
}