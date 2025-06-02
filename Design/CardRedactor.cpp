
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <string>
#include <vector>
#include <cassert>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;
// Assume redact_card_numbers is already defined above


/*
Visa:

Must be 13 or 16 digits

Must start with 4

Mastercard:

Must be 16 digits

Starts with 51–55 or 2221–2720

American Express:

Must be 15 digits

Starts with 34 or 37
*/
class CardRedactor {
    private:
    
        bool isVisa(const std::string& token) {
            int n = token.size();
            return (n == 13 || n == 16) && boost::starts_with(token, "4");
        }

        bool isAmex(const std::string& token) {
            return token.size() == 15 && (boost::starts_with(token, "34") || boost::starts_with(token, "37"));
        }

        bool isMastercard(const std::string& token) {
            int n = token.size();
            if (n != 16) return false;
            int two = stoi(token.substr(0, 2));
            int four = stoi(token.substr(0, 4));
            return (two >= 51 && two <= 55) || (four >= 2221 && four <= 2720);
        }

    public:
        string redact_card_numbers(string input) {
            vector<string> tokens;
            split(tokens, input, is_any_of(" "));
            
            for (string &token: tokens) {
                bool isDigit = std::all_of(token.begin(), token.end(), [](char ch) {return isdigit(ch);});
                int n = token.size();
                if (isDigit && n >=13 && n <=16) {
                    bool isValid = isVisa(token) || isMastercard(token) || isAmex(token);

                    if (isValid) token = string(n - 4, 'x') + token.substr(n-4);
                }
            }
            
            return boost::join(tokens, " ");
        }  
};

void run_tests() {
    CardRedactor redactor;
    std::vector<std::pair<std::string, std::string>> tests = {
        {
            "basic_string 12345 no redaction",
            "basic_string 12345 no redaction"
        },
        {
            "1234567890123456 is not a card",
            "1234567890123456 is not a card"
        },
        {
            "4234567890123456 is a valid visa",
            "xxxxxxxxxxxx3456 is a valid visa"
        },
        {
            "an embedded number 378282246310005 in the string",
            "an embedded number xxxxxxxxxxx0005 in the string"
        },
        {
            "card 2221000000000009 is master",
            "card xxxxxxxxxxxx0009 is master"
        },
        {
            "55 is not enough 5555555555554444 works",
            "55 is not enough xxxxxxxxxxxx4444 works"
        },
        {
            "random text 5105105105105100 more text",
            "random text xxxxxxxxxxxx5100 more text"
        }
    };

    for (const auto& [input, expected] : tests) {
        std::string result = redactor.redact_card_numbers(input);
        std::cout << "Input:    " << input << "\n";
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Output:   " << result << "\n";
        std::cout << (result == expected ? "[PASS]" : "[FAIL]") << "\n\n";
        assert(result == expected);
    }

    std::cout << "✅ All tests passed!\n";
}


int main(){
    run_tests();
    return 0;
}
