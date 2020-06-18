#include <iostream>
#include <vector>
using namespace std;

class Proverka {
public:
    bool isTrue(std::string s) {
        std::vector<char> pam;
        for (char c : s) {
            switch (c) {
            case '(':
            case '{':
            case '[':
                pam.push_back(c);
                break;
            case ')':
                if (pam.empty() || pam.back() != '(')
                    return false;
                pam.pop_back();
                break;
            case '}':
                if (pam.empty() || pam.back() != '{')
                    return false;
                pam.pop_back();
                break;
            case ']':
                if (pam.empty() || pam.back() != '[')
                    return false;
                pam.pop_back();
                break;
            }
        }
        return pam.empty();
    }
};

int main() {
    Proverka test;
    cout << boolalpha << test.isTrue("asdf(as[x]df)") << "\n" << "\n";
    cout << boolalpha << test.isTrue("asdf(as[x}df)") << "\n" << "\n";
}