/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:47:14 by jflorido          #+#    #+#             */
/*   Updated: 2023/08/04 13:47:03 by jflorido         ###   ########.fr       */
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
 * 		ft_sleep --> philo_utils.c (PASAR A UTILS???)
 *
 * =============== PENDING ====================
 * - Crear rutina
 * 		- 1/ Funcion comer. Reserva de tenedores. Logica para reservar (pares / impares).
 * 		- 2/ Funcion para dormir. En combinacion con ft_sleep.
 * 		- 3/ Funcion para pensar. Solo mensaje??? No hay tiempo definido.
 * 		- Comprobacion de si filosofo esta muerto?? Hilo independiente
 * - Crear funcion para lanzar los hilos de los philos
 * 		- Pasar como argumento la funcion que tiene que realizar. Rutina.
 *
 * - Crear philosofo adicional para comprobar si alguno ha muerto???
 */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
    {
        if (ft_arg_is_nb(argv) == 0 && ft_arg_in_int(argv) == 0)
            //ft_initial_data_load(argc, argv);
			ft_get_time();
		ft_initial_data_load(argc, argv);
		printf("Inicio sleep\n");
		//ft_sleep(5000);
		printf("Fin sleep\n");
            //printf("Todo Correcto. Continua ejecucion!!\n");
    }
    else
	    return (ft_error_msg("Error.\nInvalid number of args\n"), 0);
}
