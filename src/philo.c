/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:47:14 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/21 16:47:19 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Nombre de programa --> OK
philo

Archivos a entregar
Makefile, *.h, *.c, en el directorio philo/

Makefile --> OK
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

Se permite usar libft --> OK
No
*/

/*
 * ================ DONE ======================
 *
 * - Chequeos de entrada. Numero de argumentos. Valores numericos, no vacios,
 * 		con posibilidad de signo '+' --> checks.c
 * - Funcion para liberar strings y strings dobles (char **) --> utils.c
 * - Funcion Atoi --> utils.c
 * - Creada funcion para comprobar que los valores introducidos no exceden los
 * 		limites de INT. ft_arg_in_int --> checks.c
 * - Creada funcion para obtener el tiempo actual
 * 		ft_get_time --> utils.c
 * - Creada funcion para la carga de datos en la estructura general
 * 		ft_initial_data_load --> inits.c
 * - Creada funcion para realizar los mutex a los tenedores
 * 		ft_init_mutex --> inits.c
 * - Creada funcion para inicializar a cada filosofo
 * 		ft_init_philo --> inits.c
 * - Creada funcion para esperar el tiempo necesario para realizar las operaciones
 * 		ft_sleep --> utils.c
 * - Creada funcion que genera filosofo vigilante
 * 		ft_philo_watcher --> watcher.c
 * - Creada funcion para las impresiones por pantalla del estado
 * 		ft_print_msg --> utils.c
 *  - Creada rutina (usando mutex_lock para que los hilos salgan todos a la vez)
 * 		ft_routine --> philo.c
 * * 		- 1/ Funcion comer. Reserva de tenedores. Logica para reservar (pares / impares).
 * 				- Imprimir mensaje
 * 				- Actualizar t_t_die
 * 				- Actualizar nb_meals
 * 				- Unlock de los tenedores
 * 		- 2/ Funcion para dormir. En combinacion con ft_sleep.
 * 		- 3/ Funcion para pensar. Solo mensaje??? No hay tiempo definido.
 *  - Creada funcion para lanzar los hilos (usando mutex_lock para crear los hilos y que no se ejecute nada hasta
 * 		que esten todos creados)
 * 		ft_create_threads --> philo.c
 *  - Chequeo de si los filosofos han comido el numero de veces indicado en los argumentos (ver watcher)
 * 	- Liberados los malloc al final de la ejecución. Sin problemas con Valgrind
 * 	- Norminette OK
 *
 * =============== PENDING ====================
 *
 *	- Funcion para gestionar 1 unico filosofo
 *	- Comprobación de las funciones usadas en el proyecto (ver comando shell notion)
	- Comentarios a las funciones
	- Quitar el mensaje cuando se liberan los tenedores
 */

#include "../inc/philo.h"

/*
 * #FT_ROUTINE
 * 		wait for all the threads (mutex_lock). Save the starting time (st_time)
 * 		and start to launch all the action to performed by each thread (philosophe)
 *
 * #PARAMETERS
 * 		- void *arg --> this parameter will be converted in the philo array
 * 						later on. Needed to do by this way according to the
 * 						functions to create the threads.
 *
 * #RETURN
 * 		- 0 when the function finishes, the means, when the threads stop.
 */
void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->start);
	philo->general->st_time = ft_get_time();
	while (philo->general->is_dead == 0 && (philo->general->number_meals == -1
			|| philo->general->number_meals >= 0))
	{
		ft_take_fork(philo);
		ft_eating(philo);
		if (philo->nb_meals == 0)
			break ;
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (0);
}

/*
 * #FT_CREATE_THREADS
 *		This function creates all the threads based on the arguments
 *
 * #PARAMETERS
 * 		- t_general *gen_data--> a pointer to the general structure where
 * 					some data arguments will be stored.
 *
 * #RETURN
 * 		-
 */
void	ft_create_threads(t_general *gen_data)
{
	int	i;

	i = 0;
	while (i < gen_data->tot_philos)
	{
		pthread_mutex_init(&(gen_data->philo[i].start), NULL);
		pthread_mutex_lock(&gen_data->philo[i].start);
		pthread_create(&gen_data->philo[i].thread, NULL,
			&ft_routine, (void *)&gen_data->philo[i]);
		i++;
	}
	ft_mutex_unlock(gen_data);
	ft_philo_watcher(gen_data);
	i = 0;
	while (i < gen_data->tot_philos)
	{
		pthread_join(gen_data->philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_general	*gen_data;

	gen_data = malloc(sizeof(t_general));
	if (!gen_data)
		return (1);
	if (argc == 5 || argc == 6)
	{
		if (ft_arg_is_nb(argv) == 0 && ft_arg_in_int(argv) == 0 && ft_initial_data_load(gen_data, argc, argv) == 0)
			ft_create_threads(gen_data);
		else
		{
			free(gen_data);
			return (1);
		}
	}
	else
	{
		free(gen_data);
		return (ft_error_msg("Error.\nInvalid number of args\n"), 0);
	}
	free(gen_data->m_forks);
	free(gen_data->philo);
	free(gen_data);
	return (0);
}
