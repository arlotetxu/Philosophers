/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:43:19 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/17 17:35:01 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
Funcion que desbloquea a los hilos para su lanzamiento en la funcion routine
*/
void	ft_mutex_unlock(t_general *gen_data)
{
	int	i;

	i = 1;
	while (i < gen_data->tot_philos)
	{
		pthread_mutex_unlock(&gen_data->philo[i].start);
		i += 2;
	}
	i = 0;
	while (i < gen_data->tot_philos)
	{
		pthread_mutex_unlock(&gen_data->philo[i].start);
		i += 2;
	}
}

/*
Funcion para imprimir los valores de cada filosofo
*/
void	ft_print_philo_values(t_philo *philo)
{
	int	i;

	i = -1;
	while(++i < philo->general->tot_philos)
	{
		printf("Philo[%d] --> t_t_die: %d\n", philo->philo_id, philo->t_t_die);
		printf("Philo[%d] --> t_t_eat: %d\n", philo->philo_id, philo->t_t_eat);
		printf("Philo[%d] --> t_t_sleep: %d\n", philo->philo_id, philo->t_t_sleep);
		printf("Philo[%d] --> nb_meals: %d\n", philo->philo_id, philo->nb_meals);
	}
}
