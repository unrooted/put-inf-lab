#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <cmath>

using namespace std;

double number, power, result;
sem_t sem_data, sem_result;

void *get_data(void *arg) {
    cout << "podaj liczbe: ";
    cin >> number;
    cout << "podaj potege: ";
    cin >> power;
    sem_post(&sem_data); 
    return NULL;
}


void *calculate_power(void *arg) {
    sem_wait(&sem_data);
    result = pow(number, power);
    sem_post(&sem_result);
    return NULL;
}

int main() {
   
    sem_init(&sem_data, 0, 0);
    sem_init(&sem_result, 0, 0);

    
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, get_data, NULL);
    pthread_create(&thread2, NULL, calculate_power, NULL);

   
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    
    cout << number << " do potegi " << power << " wynosi " << result << endl;

    
    sem_destroy(&sem_data);
    sem_destroy(&sem_result);

    return 0;
}

