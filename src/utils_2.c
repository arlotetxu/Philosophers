/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:43:19 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/21 17:07:35 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * #FT_MUTEX_UNLOCK
 * 		Function to unblock the threads when launching them
 *
 * #PARAMETERS
 * 		- *gen_data -> Pointer to the general struct.
 *
 * #RETURN
 * 		-
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
