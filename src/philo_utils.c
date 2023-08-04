/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:18:03 by jflorido          #+#    #+#             */
/*   Updated: 2023/08/04 15:05:04 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* Comprueba si el el philo no ha comido y muere Hay que ir actualizando el t_t_die
* Cada vez que come. Esto sera:
* t_t_die = ft_get_time() - st_time + t_t_die
* Esta sera la funcion que tiene que estar comprobando el philo_checker
*/
int	ft_philo_dead(t_general *gen_data)
{
	int	i;

	i = -1;
	while (++i < gen_data->tot_philos)
		if((ft_get_time() - gen_data->st_time) > gen_data->philo[i].t_t_die)
		{
			gen_data->is_dead = 1;
			return (1);
		}
	return (0);
}
