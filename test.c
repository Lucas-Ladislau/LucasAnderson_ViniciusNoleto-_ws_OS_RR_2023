#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 

sem_t mutex;  // semáforo para controlar o acesso à mesa
sem_t forks[N];  // semáforos para controlar o acesso aos garfos

void *philosopher(void *arg) {
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % N;

    while (1) {
        printf("Filósofo %d está pensando\n", id);

        sem_wait(&mutex);  // espera para entrar na mesa
        sem_wait(&forks[left]);  // pega o garfo da esquerda
        sem_wait(&forks[right]);  // pega o garfo da direita
        sem_post(&mutex);  // libera o acesso à mesa

        printf("Filósofo %d está comendo\n", id);
        sleep(1);

        sem_post(&forks[left]);  // devolve o garfo da esquerda
        sem_post(&forks[right]);  // devolve o garfo da direita

        printf("Filósofo %d está satisfeito\n", id);
        sleep(1);
    }
}

int main() {
    int i;
    pthread_t tid[N];
    int id[N];

    sem_init(&mutex, 0, 1);  // mutex inicializado com 1
    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);  // garfos inicializados com 1
    }

    for (i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &id[i]);
    }

    for (i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}