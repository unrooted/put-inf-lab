#include <iostream>
#include <vector>
#include <cmath>
#include <regex>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double realPart, double imaginaryPart) {
        real = realPart;
        imaginary = imaginaryPart;
    }

    Complex() : real(0.0), imaginary(0.0) {}

    Complex add(const Complex& other) const {
        double resultReal = real + other.real;
        double resultImaginary = imaginary + other.imaginary;
        return Complex(resultReal, resultImaginary);
    }

    Complex subtract(const Complex& other) const {
        double resultReal = real - other.real;
        double resultImaginary = imaginary - other.imaginary;
        return Complex(resultReal, resultImaginary);
    }

    Complex multiply(const Complex& other) const {
        double resultReal = (real * other.real) - (imaginary * other.imaginary);
        double resultImaginary = (real * other.imaginary) + (imaginary * other.real);
        return Complex(resultReal, resultImaginary);
    }

    Complex divide(const Complex& other) const {
        double divisor = (other.real * other.real) + (other.imaginary * other.imaginary);
        double resultReal = ((real * other.real) + (imaginary * other.imaginary)) / divisor;
        double resultImaginary = ((imaginary * other.real) - (real * other.imaginary)) / divisor;
        return Complex(resultReal, resultImaginary);
    }

    double abs() const {
        return sqrt((real * real) + (imaginary * imaginary));
    }

    void display() const {
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i";
        else
            cout << real << " - " << -imaginary << "i";
    }
};

Complex parseComplexNumber(const string& input) {
    regex complexRegex(R"(z\s*=\s*([-+]?\d+(?:\.\d+)?)\s*([+-])\s*i\s*([-+]?\d+(?:\.\d+)?))");
    smatch matches;

    if (regex_match(input, matches, complexRegex)) {
        double realPart = stod(matches[1].str());
        double imaginaryPart = stod(matches[3].str());

        if (matches[2].str() == "-")
            imaginaryPart *= -1;

        return Complex(realPart, imaginaryPart);
    }

    throw invalid_argument("Invalid complex number format. Please provide a number in the format z = x + iy.");
}

void displayComplexNumbers(const vector<Complex>& complexNumbers) {
    cout << "Complex Numbers:" << endl;
    for (size_t i = 0; i < complexNumbers.size(); i++) {
        cout << "Complex " << (i + 1) << ": ";
        complexNumbers[i].display();
        cout << endl;
    }
}

int main() {
    vector<Complex> complexNumbers;

    while (true) {
        cout << "Select an action:" << endl;
        cout << "1. Show all complex numbers" << endl;
        cout << "2. Add a complex number" << endl;
        cout << "3. Remove a complex number" << endl;
        cout << "4. Perform operations on complex numbers" << endl;
        cout << "5. Show absolute value of a complex number" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 6)
            break;

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please try again." << endl << endl;
            continue;
        }

        switch (choice) {
            case 1:
                displayComplexNumbers(complexNumbers);
                cout << endl;
                break;
            case 2: {
                string complexInput;

                cout << "Enter the complex number to add (in the format z = x + iy): ";
                cin.ignore();
                getline(cin, complexInput);

                try {
                    Complex complex = parseComplexNumber(complexInput);
                    complexNumbers.push_back(complex);
                    cout << "Complex number added successfully." << endl << endl;
                }
                catch (const exception& ex) {
                    cout << "Error: " << ex.what() << endl << endl;
                }
                break;
            }
            case 3: {
                displayComplexNumbers(complexNumbers);
                cout << endl;

                if (complexNumbers.empty()) {
                    cout << "No complex numbers to remove." << endl << endl;
                    break;
                }

                int index;
                cout << "Enter the index of the complex number to remove: ";
                cin >> index;
                cin.ignore();

                if (index < 1 || index > static_cast<int>(complexNumbers.size())) {
                    cout << "Invalid index. Please try again." << endl << endl;
                    break;
                }

                complexNumbers.erase(complexNumbers.begin() + index - 1);
                cout << "Complex number removed successfully." << endl << endl;
                break;
            }
            case 4: {
                displayComplexNumbers(complexNumbers);
                cout << endl;

                if (complexNumbers.empty()) {
                    cout << "No complex numbers to perform operations on." << endl << endl;
                    break;
                }

                int complexIndex1, complexIndex2;
                cout << "Enter the index of the first complex number: ";
                cin >> complexIndex1;
                complexIndex1--;

                if (complexIndex1 < 0 || complexIndex1 >= static_cast<int>(complexNumbers.size())) {
                    cout << "Invalid complex number index. Please try again." << endl << endl;
                    break;
                }

                cout << "Enter the index of the second complex number: ";
                cin >> complexIndex2;
                complexIndex2--;

                if (complexIndex2 < 0 || complexIndex2 >= static_cast<int>(complexNumbers.size())) {
                    cout << "Invalid complex number index. Please try again." << endl << endl;
                    break;
                }

                Complex result;
                int operation;

                cout << "Select an operation:" << endl;
                cout << "1. Add" << endl;
                cout << "2. Subtract" << endl;
                cout << "3. Multiply" << endl;
                cout << "4. Divide" << endl;
                cout << "Enter your choice: ";
                cin >> operation;

                switch (operation) {
                    case 1:
                        result = complexNumbers[complexIndex1].add(complexNumbers[complexIndex2]);
                        cout << "Sum: ";
                        break;
                    case 2:
                        result = complexNumbers[complexIndex1].subtract(complexNumbers[complexIndex2]);
                        cout << "Difference: ";
                        break;
                    case 3:
                        result = complexNumbers[complexIndex1].multiply(complexNumbers[complexIndex2]);
                        cout << "Product: ";
                        break;
                    case 4:
                        result = complexNumbers[complexIndex1].divide(complexNumbers[complexIndex2]);
                        cout << "Quotient: ";
                        break;
                    default:
                        cout << "Invalid operation. Please try again." << endl << endl;
                        continue;
                }

                result.display();
                cout << endl << endl;
                break;
            }
            case 5: {
                displayComplexNumbers(complexNumbers);
                cout << endl;

                if (complexNumbers.empty()) {
                    cout << "No complex numbers to calculate the absolute value." << endl << endl;
                    break;
                }

                int complexIndex;
                cout << "Enter the index of the complex number: ";
                cin >> complexIndex;
                complexIndex--;

                if (complexIndex < 0 || complexIndex >= static_cast<int>(complexNumbers.size())) {
                    cout << "Invalid complex number index. Please try again." << endl << endl;
                    break;
                }

                double absoluteValue = complexNumbers[complexIndex].abs();
                cout << "Absolute Value: " << absoluteValue << endl << endl;
                break;
            }
        }
    }

    return 0;
}