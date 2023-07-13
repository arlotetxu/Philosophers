//
// Created by Jose Manuel Florido Pereña on 11/7/23.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*my_turn()
{
	while (1)
	{
		sleep(1);
		printf("My turn.\n");
	}
	return (NULL);
}

void	*your_turn()
{
	while (1)
	{
		sleep(2);
		printf("Your turn.\n");
	}
	return (NULL);
}

int main(void)
{
	pthread_t	newthread;

	pthread_create(&newthread, NULL, my_turn, NULL);
	//my_turn();
	//your_turn();
	sleep(12);
	//printf("Fin\n");
	return (0);
}