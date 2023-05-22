#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    int* tablica = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Podaj wartość dla indeksu " << i << ": ";
        cin >> tablica[i];
    }

    cout << "Zawartość tablicy: ";
    for (int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }

    delete[] tablica;

    return 0;
}

