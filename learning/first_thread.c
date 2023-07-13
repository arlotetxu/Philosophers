//
// Created by Jose Manuel Florido Pereña on 11/7/23.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*my_turn()
{
	int i = 0;

	while (i < 8)
	{
		sleep(1);
		printf("My turn - %d\n", i++);
	}
	return (NULL);
}

void	*your_turn()
{
	int i = 0;
	while (i < 3)
	{
		sleep(2);
		printf("Your turn - %d\n", i++);
	}
	return (NULL);
}

int main(void)
{
	pthread_t	newthread;

	pthread_create(&newthread, NULL, my_turn, NULL); //Crea un hilo de ejecucion
	//my_turn();
	your_turn();
	pthread_join(newthread, NULL); //Espera a que el hilo de ejecucion termine para continuar con el codigo de main
	//sleep(5);
	//your_turn();
	sleep(12);
	//printf("Fin\n");
	return (0);
}