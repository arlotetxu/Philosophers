/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:47:14 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/29 13:24:45 by jflorido         ###   ########.fr       */
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
 * 		ft_initial_data_load --> philo_utils.c
 * - Creada funcion para realizar los mutex a los tenedores
 * 		ft_init_mutex --> philo_utils.c
 *
 * =============== PENDING ====================
 * Crear funcion para inicializar cada filosofo
 * 		ft_init_philo --> philo_utils.c
 * 		Pendiente inicializar los mutex de cada tenedor de cada filosofo
 * Crear funcion para comprobar los datos imprimiendo sus valores
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
            //printf("Todo Correcto. Continua ejecucion!!\n");
    }
    else
	    return (ft_error_msg("Error.\nInvalid number of args\n"), 0);
}
