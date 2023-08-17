/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:18:03 by jflorido          #+#    #+#             */
/*   Updated: 2023/08/17 09:14:37 by jflorido         ###   ########.fr       */
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
	ft_print_msg(philo, " is eating.\n");
	ft_sleep(philo->t_t_eat);
	pthread_mutex_lock(&philo->general->gen_mutex);
	philo->t_t_die = ft_get_time() - philo->general->st_time
		+ philo->general->t_t_die;
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->general->gen_mutex);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

/*
* Funcion para dormir
*/
void	ft_sleeping(t_philo *philo)
{
	ft_print_msg(philo, " is sleeping.\n");
	ft_sleep(philo->t_t_sleep);
}

/*
* Funcion para pensar. Añadir un tiempo manual?????
*/
void	ft_thinking(t_philo *philo)
{
	ft_print_msg(philo, " is thinking.\n");
	//ft_sleep(10);
}
