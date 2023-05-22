#include <iostream>
#include <pthread.h>

using namespace std;

int n; // User input for n
unsigned long long fib[100]; // Array to store fibonacci sequence
unsigned long long sum; // Variable to store sum of the fibonacci sequence
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex variable to protect shared resources

void* fibonacci(void* arg) {
    int i;
    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    pthread_exit(NULL);
}

void* calculateSum(void* arg) {
    int i;

    for (i = 0; i <= n; i++) {
        pthread_mutex_lock(&mutex);
        sum += fib[i];
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    cout << "podaj n: ";
    cin >> n;

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, fibonacci, NULL);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, calculateSum, NULL);
    pthread_join(thread2, NULL);

    cout << "suma " << n << " pierwszych wartosci w ciagu Fibonacciego wynosi: " << sum << endl;

    pthread_mutex_destroy(&mutex);

    return 0;
}

