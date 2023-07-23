/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:45:20 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/23 17:45:21 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

long long counter = 0;
#define BIG 1000000000
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

/*
 * WITHOUT CONTROLED RACE CONDITION
 */
void	ft_counter()
{
	long long i = -1;
	while (++i < BIG)
		counter++;
}

int main(void)
{
	ft_counter();
	ft_counter();
	printf("Result: %lld\n", counter);
	return (0);
}

/*
 * WITH CONTROLED RACE CONDITION (MUTEX)
 */
//void	*ft_counter()
//{
//	long long i = -1;
//	while (++i < BIG)
//	{
//		pthread_mutex_lock(&lock);
//		counter++;
//		pthread_mutex_unlock(&lock);
//	}
//	return NULL;
//}
//
//int main(void)
//{
//	pthread_t	t1;
//
//	pthread_create(&t1, NULL, ft_counter, NULL);
//	//ft_counter();
//	ft_counter();
//	pthread_join(t1, NULL);
//	printf("Result: %lld\n", counter);
//	return (0);
//}