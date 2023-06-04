#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

std::string reverseString(const std::string& str, char punctuation)
{
    std::string reversed = str;
    bool hasPeriod = false;
    if (!reversed.empty() && reversed.back() == '.') {
        hasPeriod = true;
        reversed.pop_back();
    }

    bool hasQuestion = false;
    if (!reversed.empty() && reversed.back() == '?') {
        hasQuestion = true;
        reversed.pop_back();
    }

    bool hasExclamation = false;
    if (!reversed.empty() && reversed.back() == '!') {
        hasExclamation = true;
        reversed.pop_back();
    }

    std::reverse(reversed.begin(), reversed.end());

    reversed.push_back(' ');

    int n = reversed.length();
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (reversed[i] == ' ') {
            std::reverse(reversed.begin() + j, reversed.begin() + i);
            j = i + 1;
        }
    }

    reversed.pop_back();

    if (hasPeriod || hasQuestion || hasExclamation || !reversed.empty())
        reversed.push_back(punctuation);

    return reversed;
}


int main()
{
    std::string str;
    std::cout << "Podaj zdanie: ";
    std::getline(std::cin, str);

    bool capitalizeFirst = false;
    if (!str.empty() && std::isupper(str[0])) {
        capitalizeFirst = true;
        str[0] = std::tolower(str[0]);
    }

    std::string rev = reverseString(str, str.back());

    if (capitalizeFirst)
        rev[0] = std::toupper(rev[0]);

    std::cout << "Odwrócone zdanie: " << rev << std::endl;

    return 0;
}
