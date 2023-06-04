#include <iostream>

using namespace std;

bool detectTriangle(float a, float b, float c) {
    return (a + b > c && a + c > b && b + c > a);
}

int main() {
    float a, b, c;
    cout << "Podaj długość pierwszego boku: ";
    cin >> a;
    cout << "Podaj długość drugiego boku: ";
    cin >> b;
    cout << "Podaj długość trzeciego boku: ";
    cin >> c;

    if (detectTriangle(a, b, c)) {
        cout << "Można zbudować trójkąt." << endl;

        if (a == b && b == c) {
            cout << "To jest trójkąt równoboczny." << endl;
        } else if (a == b || a == c || b == c) {
            cout << "To jest trójkąt równoramienny." << endl;
        } else {
            cout << "To jest trójkąt różnoboczny." << endl;
        }
    } else {
        cout << "Nie można zbudować trójkąta." << endl;
    }

    return 0;
}

