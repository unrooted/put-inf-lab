#include <iostream>
#include <pthread.h>

using namespace std;

void* encrypt(void* arg) {
    char* text = (char*) arg;
    int k;
    cout << "podaj wartosc k: ";
    cin >> k;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (char) (((text[i] - 'a' + k) % 26) + 'a');
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (char) (((text[i] - 'A' + k) % 26) + 'A');
        }
    }

    cout << "zaszyfrowany tekst: " << text << endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    char text[100];
    cout << "podaj tresc do zaszyfrowania: ";
    cin >> text;
    pthread_create(&thread, NULL, encrypt, (void*) text);
    pthread_join(thread, NULL);
    return 0;
}

