#include <iostream>
#include <pthread.h>

using namespace std;

struct thread_data {
  int n;
  int result;
};

void *fibonacci(void *arg) {
  thread_data *data = (thread_data*) arg;
  int n = data->n;
  if (n <= 1) {
    data->result = n;
  } else {
    thread_data data_1 = { n - 1, 0 };
    thread_data data_2 = { n - 2, 0 };
    pthread_t thread_1, thread_2;

    pthread_create(&thread_1, NULL, fibonacci, (void*) &data_1);
    pthread_create(&thread_2, NULL, fibonacci, (void*) &data_2);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    data->result = data_1.result + data_2.result;
  }
  pthread_exit(NULL);
}

int fib_multi_threaded(int n) {
  thread_data data = { n, 0 };
  pthread_t thread;
  pthread_create(&thread, NULL, fibonacci, (void*) &data);
  pthread_join(thread, NULL);
  return data.result;
}

int main() {
  int n;
  cout << "Podaj n: ";
  cin >> n;

  cout << "Fibonacci(" << n << ") = " << fib_multi_threaded(n) << endl;

  return 0;
}

