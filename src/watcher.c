/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:59:29 by jflorido          #+#    #+#             */
/*   Updated: 2023/08/07 17:50:09 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* Funcion que crea hilo adicional para comprobar si un filosofo ha muerto.
* Si un filosofo muere, debe cambiar la variable de la estructura t_general->is_dead
* a valor "1".

*/

// int	ft_philo_watcher(t_general *gen_data)
// {
// 	pthread_t	watcher;

// 	while (1)
// 	{
// 		if (pthread_create(&watcher, NULL, &ft_philo_dead, gen_data) != 0)
// 		{
// 			ft_error_msg("Error creating the watcher thread!,\n");
// 			return (1);
// 		}
// 		if (pthread_join(watcher, (void *) &gen_data) != 0)
// 		{
// 			ft_error_msg("Error creating the watcher thread!,\n");
// 			return (1);
// 		}
// 		if (gen_data->is_dead == 0)
// 		{
// 			printf("Philo VIVO!!\n");
// 			return (0);
// 		}
// 		if (gen_data->is_dead == 1)
// 		{
// 			printf("Philo MUERTO!!\n");
// 			//TODO Funcion declarada como INT es correcto? Void?
// 			//TODO LLamar a funcion para eliminar los hilos
// 			//TODO llamar a funcion para free
// 			//free(gen_data);
// 			return (1);
// 		}
// 	}
// }

int	ft_philo_watcher(t_general *gen_data)
{
	pthread_t	watcher;

	if (pthread_create(&watcher, NULL, &ft_philo_dead, gen_data) != 0)
	{
		ft_error_msg("Error creating the watcher thread!,\n");
		return (1);
	}
	if (pthread_join(watcher, (void *) &gen_data) != 0)
	{
		ft_error_msg("Error creating the watcher thread!,\n");
		return (1);
	}
	while (1)
	{
		// if (gen_data->is_dead == 0)
		// {
		// 	printf("Philo VIVO!!\n");
		// }
		if (gen_data->is_dead == 1)
		{
			printf("Philo MUERTO!!\n");
			//TODO Funcion declarada como INT es correcto? Void?
			//TODO LLamar a funcion para eliminar los hilos
			//TODO llamar a funcion para free
			//free(gen_data);
			return (1);
		}
	}
}
