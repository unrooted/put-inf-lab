#include <iostream>
#include <cmath>
#include <cstring>
#include <pthread.h>

using namespace std;

bool* prime;
pthread_mutex_t lock;
int n;

void markMultiples(int p) {
    int i, j;
    for (i = 2 * p; i <= n; i += p) {
        pthread_mutex_lock(&lock);
        prime[i] = false;
        pthread_mutex_unlock(&lock);
    }
}

void* sieve(void* arg) {
    int* p = (int*)arg;
    int primeNum = *p;
    markMultiples(primeNum);
    pthread_exit(NULL);
}

int main() {
    cout << "podaj n: ";
    cin >> n;

    prime = new bool[n + 1];

    memset(prime, true, (n + 1) * sizeof(bool));

    pthread_t threads[n - 1];

    pthread_mutex_init(&lock, NULL);

    int i, j;
    for (i = 2; i <= sqrt(n); i++) {
        if (prime[i]) {
            pthread_create(&threads[i - 2], NULL, sieve, (void*)&i);
        }
    }

    for (i = 2; i <= sqrt(n); i++) {
        if (prime[i]) {
            pthread_join(threads[i - 2], NULL);
        }
    }

    cout << "liczby pierwsze: ";
    for (i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    delete[] prime;
    pthread_mutex_destroy(&lock);

    return 0;
}

