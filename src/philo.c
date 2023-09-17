/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:47:14 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/17 17:41:02 by jflorido         ###   ########.fr       */
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
 *
 *
 * =============== PENDING ====================
 *
 *	- Funcion para salir una vez que un filosofo muere (ver watcher)
 *	- Funcion para gestionar 1 unico filosofo
 *	- Chequeo de si los filosofos han comido el numero de veces indicado en los argumentos 
 		(OJO, que puede no haber argumento y tienes esta condicion en la ejecucion de la rutina. Por eso se inicializa a -1 cuando no hay argumento)
		 crear una variable con el numero de veces que come cada filosofo e igualarla a 0
		 cada vez que unn filosofo come, aumentar la variable.
		 Cada vez que una variable de filosofo llega a al numero de comidas, descontar 1 del parametro de la 
		 	estructura general mediante el watcher y sacar al philosofo de la rutina
 *	- Comprobación de problemas de memoria (leaks).
 *	- Comprobación de las funciones usadas en el proyecto (ver comando shell notion)
 */

#include "../inc/philo.h"

/*
* Funcion para lanzar la rutina
*/
void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	//crear mutex lock de la variable mutex de cada filosofo. Esto hace que se queden en espera
	//todos los hilos hasta que se hace el unlock antes del join en la funcion main
	//Aqui que es donde hay que inicializar el valor de st_time


	pthread_mutex_lock(&philo->start);
	philo->general->st_time = ft_get_time();
	//printf("Starting time: %d\n", philo->general->st_time);
	//while (1)//TODO la condicion debe ser que no ha muerto ningun y que no hemos alcanzado el numero de comidas
	while (philo->general->is_dead == 0)
	{
		ft_take_fork(philo);
		ft_eating(philo);
		if (philo->nb_meals == 0)
			break;
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (0);
}

/*
* Funcion para crear los hilos de los filosofos
*/
void	ft_create_threads(t_general *gen_data)
{
	int	i;

	i = 0;
	//gen_data->st_time = ft_get_time();
	//printf("Llego a crear el tiempo de inicio: %d\n", gen_data->st_time);
	while (i < gen_data->tot_philos)
	{
		//Bloquear el mutex start de cada filosofo
		pthread_mutex_init(&(gen_data->philo[i].start), NULL);
		pthread_mutex_lock(&gen_data->philo[i].start);
		pthread_create(&gen_data->philo[i].thread, NULL, &ft_routine, (void *)&gen_data->philo[i]);
		i++;
	}
	//Crear while para desbloquear los mutex start de cada filosofo. primero impares y luego pares
	//Meter esto en una funcion ya que de lo contrario me pasaré de lineas
	
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

    gen_data = malloc(sizeof(t_general)); //TODO Liberar
    if (!gen_data)
		return (1);
	if (argc == 5 || argc == 6)
    {
        if (ft_arg_is_nb(argv) == 0 && ft_arg_in_int(argv) == 0 && ft_initial_data_load(gen_data, argc, argv) == 0)
		{
			ft_create_threads(gen_data);
			//ft_philo_watcher(gen_data);
			//Meter los free() de los mallocs hechos en esta funcion en las funciones del archivo inits.c
			//free(gen_data);
			return (0);
		}
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
}
