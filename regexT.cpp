#include <iostream>
#include <regex>
using namespace std;

int main()
{
    string text = "Name: John, Email: john123@gmail.com, Age: 25";

    // ============================================================
    // 🔷 basic_regex / regex
    // pattern object
    // ============================================================
    regex emailPattern(R"(\w+@\w+\.com)");

    // ============================================================
    // 🔷 match_results / smatch
    // stores full match + submatches
    // ============================================================
    smatch match;

    // ============================================================
    // 🔷 regex_search (partial match)
    // ============================================================
    if (regex_search(text, match, emailPattern)) {
        cout << "Found email: " << match[0] << endl;

        // sub_match example
        // match[i] gives sub-expressions
        for (size_t i = 0; i < match.size(); i++)
            cout << "Submatch " << i << ": " << match[i] << endl;
    }


    // ============================================================
    // 🔷 regex_match (full string match)
    // ============================================================
    regex numPattern(R"(\d+)");
    cout << "\nFull match 123? "
         << regex_match("123", numPattern) << endl;


    // ============================================================
    // 🔷 regex_replace
    // ============================================================
    string replaced = regex_replace(text, numPattern, "XX");
    cout << "\nAfter replace: " << replaced << endl;


    // ============================================================
    // 🔷 sregex_iterator (iterate matches)
    // ============================================================
    string nums = "Values: 10 20 30";

    regex num(R"(\d+)");
    sregex_iterator it(nums.begin(), nums.end(), num);
    sregex_iterator end;

    cout << "\nAll numbers: ";
    for (; it != end; ++it)
        cout << it->str() << " ";
    cout << endl;


    // ============================================================
    // 🔷 sregex_token_iterator (token extraction)
    // ============================================================
    string sentence = "apple,banana,orange";

    regex comma(",");
    sregex_token_iterator tok(sentence.begin(), sentence.end(), comma, -1);

    cout << "\nTokens: ";
    for (; tok != sregex_token_iterator(); ++tok)
        cout << tok->str() << " ";
    cout << endl;


    // ============================================================
    // 🔷 regex_error (exception handling)
    // ============================================================
    try {
        regex badPattern("(");   // invalid regex
    }
    catch (regex_error& e) {
        cout << "\nRegex error: " << e.what() << endl;
    }


    // ============================================================
    // 🔷 KEY TYPES USED
    // ============================================================
    // regex        → pattern
    // smatch       → match result
    // sub_match    → part of match
    // iterator     → traverse matches
    // token_iter   → split / extract tokens

    return 0;
}