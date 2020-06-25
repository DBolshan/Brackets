#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
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

int main(int argc, char *argv[]) {
    char c;
    string str;
    FILE *p;
    p = fopen(argv[1], "r");
    c = getc(p);
    while (c != EOF){
        str += c;
        c = getc(p);
    }
    Proverka test;
    cout << boolalpha << test.isTrue(str) << "\n" << "\n";
    cout << boolalpha << test.isTrue(str) << "\n" << "\n";
}
