/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:47:14 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/23 18:43:13 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Tu(s) programa(s) debe(n) aceptar los siguientes argumentos:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]

Nombre de programa
philo

Archivos a entregar
Makefile, *.h, *.c, en el directorio philo/

Makefile 
NAME, all, clean, fclean, re

Argumentos 
number_of_philosophers 
time_to_die 
time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]

Funciones autorizadas
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock

Se permite usar libft
No
*/


#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		printf("Probando %s\n", argv[0]);
	}
    else
	    return (ft_error_msg("Error.\nInvalid number of args\n"), 0);
}