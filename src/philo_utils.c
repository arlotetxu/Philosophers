/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:18:03 by jflorido          #+#    #+#             */
/*   Updated: 2023/08/07 17:40:23 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_take_fork(t_philo *philo)
{
		if (philo->philo_id % 2 == 0)
			if (pthread_mutex_lock(philo->r_fork) != 0)
				return (pthread_mutex_unlock(philo->r_fork), 1);
		else
			if (pthread_mutex_lock(philo->l_fork) != 0)
				return (pthread_mutex_unlock(philo->l_fork), 1);
		printf("%d has taken a fork.\n", philo->philo_id);
		if (philo->philo_id % 2 == 0)
			if (pthread_mutex_lock(philo->l_fork) != 0)
				return (pthread_mutex_unlock(philo->l_fork), 1);
		else
			if (pthread_mutex_lock(philo->r_fork) != 0)
				return (pthread_mutex_unlock(philo->r_fork), 1);
		printf("%d has taken a fork.\n", philo->philo_id);
	return (0);
}

