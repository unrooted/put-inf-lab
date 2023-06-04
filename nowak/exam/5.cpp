#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>
#include <cmath>
#include <sstream>

class ABC {
private:
    std::unordered_set<int> D;

public:
    ABC() : D({3, 5, 7, 10}) {}

    void abc(int n) {
        int sign = (n < 0) ? -1 : 1;
        for (int i = 1; i <= std::abs(n); ++i) {
            bool found = false;
            for (int num : D) {
                if (i % std::abs(num) == 0) {
                    found = true;
                    break;
                }
            }
            if (found) {
                std::cout << "X ";
            } else {
                std::cout << (i * sign) << " ";
            }
        }
        std::cout << std::endl;
    }
};

int getUserInput() {
    int n;
    std::string input;
    std::cout << "podaj wartosc int n: ";
    std::getline(std::cin, input);

    while (true) {
        std::istringstream iss(input);
        if (iss >> n && iss.eof() && n >= std::numeric_limits<int>::min() && n <= std::numeric_limits<int>::max()) {
            break;
        } else {
            std::cout << "niepoprawny input, podaj inta: ";
            std::getline(std::cin, input);
        }
    }
    return n;
}

int main() {
    ABC obj;
    int n = getUserInput();

    obj.abc(n);

    return 0;
}
