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

/*
* Comprueba si el el philo no ha comido y muere. Hay que ir actualizando el t_t_die
* Cada vez que come. Esto sera:
* t_t_die = ft_get_time() - st_time + t_t_die
* Esta sera la funcion que tiene que estar comprobando el philo_checker
*/
void*	ft_philo_dead(void *arg)
{
	int			i;
	t_general	*gen_data;

	gen_data = (t_general*)arg;
	i = -1;
	while (++i < gen_data->tot_philos)
		if((ft_get_time() - gen_data->st_time) > gen_data->philo[i].t_t_die)
		{
			gen_data->is_dead = 1;
			return ((void *)gen_data);
		}
	return ((void *)gen_data);
}

