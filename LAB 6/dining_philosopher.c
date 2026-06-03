#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define EAT_COUNT 3

sem_t forks[N];

void *philosopher(void *arg)
{
    int id = *(int *)arg;

    for(int k = 1; k <= EAT_COUNT; k++)
    {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        /* Deadlock-free */
        if(id == N - 1)
        {
            sem_wait(&forks[(id + 1) % N]);
            printf("Philosopher %d picked up right fork %d.\n",
                   id, (id + 1) % N);

            sem_wait(&forks[id]);
            printf("Philosopher %d picked up left fork %d.\n",
                   id, id);
        }
        else
        {
            sem_wait(&forks[id]);
            printf("Philosopher %d picked up left fork %d.\n",
                   id, id);

            sem_wait(&forks[(id + 1) % N]);
            printf("Philosopher %d picked up right fork %d.\n",
                   id, (id + 1) % N);
        }

        printf("Philosopher %d is eating \n",
               id);
        sleep(2);

        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);

        printf("Philosopher %d put down forks %d and %d.\n",
               id, id, (id + 1) % N);
    }

    printf("Philosopher %d has finished all %d meals.\n",
           id, EAT_COUNT);

    return NULL;
}

int main()
{
    pthread_t ph[N];
    int id[N];

    for(int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    for(int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(ph[i], NULL);

    printf("\nAll philosophers have eaten %d times and left the table.\n",
           EAT_COUNT);

    for(int i = 0; i < N; i++)
        sem_destroy(&forks[i]);

    return 0;
}
