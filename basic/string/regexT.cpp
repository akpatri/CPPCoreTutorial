#include <iostream>
#include <regex>
using namespace std;

int main() {

    string text = "Email: john123@gmail.com, Age: 25";

    // ============================================================
    // 🔷 1. regex → pattern holder
    // Responsibility:
    //   Stores the pattern you want to search
    //
    // Syntax:
    //   regex pattern("your_pattern");
    //
    // Parameters:
    //   "your_pattern" → string defining search rule
    // ============================================================
    regex emailPattern(R"(\w+@\w+\.com)");



    // ============================================================
    // 🔷 2. smatch → result container
    // Responsibility:
    //   Stores match result (full + parts)
    //
    // Syntax:
    //   smatch match;
    //
    // Parameters:
    //   No parameters (just a container)
    // ============================================================
    smatch match;



    // ============================================================
    // 🔷 3. regex_search → find partial match
    // Responsibility:
    //   Searches pattern anywhere inside string
    //
    // Syntax:
    //   regex_search(text, match, pattern)
    //
    // Parameters:
    //   text    → string to search in
    //   match   → object to store result
    //   pattern → regex object
    // ============================================================
    if (regex_search(text, match, emailPattern)) {
        cout << "Found: " << match[0] << endl;
        // match[0] → full match
    }



    // ============================================================
    // 🔷 4. regex_match → full string match
    // Responsibility:
    //   Checks if entire string matches pattern
    //
    // Syntax:
    //   regex_match(text, pattern)
    //
    // Parameters:
    //   text    → full string
    //   pattern → regex rule
    // ============================================================
    cout << "Is number? "
         << regex_match("123", regex(R"(\d+)")) << endl;



    // ============================================================
    // 🔷 5. regex_replace → replace matches
    // Responsibility:
    //   Replaces matched parts with new text
    //
    // Syntax:
    //   regex_replace(text, pattern, new_value)
    //
    // Parameters:
    //   text      → original string
    //   pattern   → what to replace
    //   new_value → replacement
    // ============================================================
    string result = regex_replace(text, regex(R"(\d+)"), "XX");
    cout << "After replace: " << result << endl;



    // ============================================================
    // 🔷 6. sregex_iterator → iterate matches
    // Responsibility:
    //   Loops through ALL matches in string
    //
    // Syntax:
    //   sregex_iterator(begin, end, pattern)
    //
    // Parameters:
    //   begin   → start of string
    //   end     → end of string
    //   pattern → regex rule
    // ============================================================
    string nums = "10 20 30";
    regex numPattern(R"(\d+)");

    sregex_iterator it(nums.begin(), nums.end(), numPattern);
    sregex_iterator end;

    cout << "Numbers: ";
    for (; it != end; ++it)
        cout << it->str() << " ";
    cout << endl;



    // ============================================================
    // 🔷 7. sregex_token_iterator → split / tokens
    // Responsibility:
    //   Splits string based on delimiter
    //
    // Syntax:
    //   sregex_token_iterator(begin, end, pattern, -1)
    //
    // Parameters:
    //   begin   → start
    //   end     → end
    //   pattern → delimiter
    //   -1      → return non-matching parts (tokens)
    // ============================================================
    string data = "apple,banana,orange";
    regex comma(",");

    sregex_token_iterator tok(data.begin(), data.end(), comma, -1);

    cout << "Tokens: ";
    for (; tok != sregex_token_iterator(); ++tok)
        cout << tok->str() << " ";
    cout << endl;



    // ============================================================
    // 🔷 8. regex_error → exception handling
    // Responsibility:
    //   Handles invalid regex pattern
    //
    // Syntax:
    //   try { regex bad("("); }
    //   catch(regex_error& e)
    //
    // Parameters:
    //   e → error object
    // ============================================================
    try {
        regex badPattern("(");  // invalid
    }
    catch (regex_error& e) {
        cout << "Error: " << e.what() << endl;
    }


    return 0;
}