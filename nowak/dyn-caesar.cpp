#include <iostream>
#include <pthread.h>
#include <cstring>

using namespace std;

void* encrypt(void* arg) {
    char* text = (char*) arg;
    int k;
    cout << "podaj k: ";
    cin >> k;

    int len = strlen(text);
    char* encrypted_text = new char[len + 1];

    for (int i = 0; i < len; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            encrypted_text[i] = (char) (((text[i] - 'a' + k) % 26) + 'a');
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            encrypted_text[i] = (char) (((text[i] - 'A' + k) % 26) + 'A');
        }
        else {
            encrypted_text[i] = text[i];
        }
    }

    encrypted_text[len] = '\0';
    cout << "zaszyfrowana tresc: " << encrypted_text << endl;
    delete[] encrypted_text;
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    string input_text;
    cout << "podaj tekst do zaszyfrowania: ";
    getline(cin, input_text);

    char* text = new char[input_text.length() + 1];
    strcpy(text, input_text.c_str());

    pthread_create(&thread, NULL, encrypt, (void*) text);
    pthread_join(thread, NULL);
    delete[] text;
    return 0;
}
