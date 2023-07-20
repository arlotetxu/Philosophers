//
// Created by Jose Manuel Florido Pereña on 17/7/23.
//
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t *semaphore;

void* printThread(void* threadId) {
	int id = *(int*)threadId;
	for (int i = 0; i < 5; i++) {
		sem_wait(semaphore);
		printf("Hilo %d: Mensaje %d\n", id, i);
		sem_post(semaphore);
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[2];
	int threadIds[2] = {1, 2};

	semaphore = sem_open("my_semaphore", O_CREAT, 0644, 1);
	if (semaphore == SEM_FAILED) {
		perror("Error al crear el semáforo");
		return 1;
	}

	for (int i = 0; i < 2; i++) {
		pthread_create(&threads[i], NULL, printThread, (void*)&threadIds[i]);
	}

	for (int i = 0; i < 2; i++) {
		pthread_join(threads[i], NULL);
	}

	sem_close(semaphore);
	sem_unlink("my_semaphore");

	return 0;
}