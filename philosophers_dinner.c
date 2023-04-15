#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 

sem_t mutex;  // Semáforo para controlar o acesso à mesa
sem_t chopsticks[N];  // Semáforos para controlar o acesso aos hashis

void *philosopher(void *arg) {
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % N;
    id = id + 1;

    while(1){
        printf("Filósofo %d: O que é a vida?\n\n", id);
        sleep(1);

        sem_wait(&mutex);  // espera para entrar na mesa
        
        printf("Filósofo %d: Larica da desgraça meu parceiro\n\n", id);
        sem_wait(&chopsticks[left]);  // pega o hashi da esquerda
        sem_wait(&chopsticks[right]);  // pega o hashi da direita
        printf("Filósofo %d: Vou pegar esses hashis %d e %d para poder comer\n\n", id, left, right);
        
        sem_post(&mutex);  // libera o acesso à mesa

        printf("Filósofo %d: Lamen de cria slk\n\n", id);
        sleep(1);

        sem_post(&chopsticks[left]);  // devolve o hashi da esquerda
        sem_post(&chopsticks[right]);  // devolve o hashi da direita

        printf("Filósofo %d: Pai tá cheião\n\n", id);
        sleep(2);
    }
}

int main() {

    int i;
    pthread_t philo_thread[N];
    int id[N];

    sem_init(&mutex, 0, 1);  // mutex inicializado com 1
    for (i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);  // hashis inicializados com 1
    }

    for (i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&philo_thread[i], NULL, philosopher, &id[i]);
    }

    for (i = 0; i < N; i++) {
        pthread_join(philo_thread[i], NULL);
    }

    return 0;
}