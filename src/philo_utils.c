/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:18:03 by jflorido          #+#    #+#             */
/*   Updated: 2023/08/16 20:11:42 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* Funcion para la reserva de los tenedores
*/

int	ft_take_fork(t_philo *philo)
{
		if (philo->philo_id % 2 == 0)
		{
			if (pthread_mutex_lock(philo->r_fork) != 0)
				return (pthread_mutex_unlock(philo->r_fork), 1);
		}
		else
		{
			if (pthread_mutex_lock(philo->l_fork) != 0)
				return (pthread_mutex_unlock(philo->l_fork), 1);
		}
		ft_print_msg(philo, "has taken a fork.\n");
		if (philo->philo_id % 2 == 0)
		{
			if (pthread_mutex_lock(philo->l_fork) != 0)
				return (pthread_mutex_unlock(philo->l_fork), 1);
		}
		else
		{
			if (pthread_mutex_lock(philo->r_fork) != 0)
				return (pthread_mutex_unlock(philo->r_fork), 1);
		}
		ft_print_msg(philo, "has taken a fork.\n");
	return (0);
}

/*

* Funcion para comer
*/
void	ft_eating(t_philo *philo)
{
	ft_print_msg(philo, "is eating.\n");
	//Al finalizar la funcion hay que actualizar el campo t_t_die del filosofo
}
