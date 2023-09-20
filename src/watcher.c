/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:59:29 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/20 19:49:59 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_dead(int t_time, int philo_id, t_general *gen_data)
{
	printf("%d		%d  died.\n", t_time, philo_id);
	gen_data->is_dead = 1;
}

/*
* Comprueba si el el philo no ha comido y muere. Hay que ir actualizando
* el t_t_die Cada vez que come. Esto sera:
* t_t_die = ft_get_time() - st_time + t_t_die
* Esta sera la funcion que tiene que estar comprobando el philo_checker
*/
void	*ft_philo_dead(void *arg)
{
	int			i;
	t_general	*gen_data;

	gen_data = (t_general *)arg;
	while (1)
	{
		i = -1;
		while (++i < gen_data->tot_philos)
		{
			if (gen_data->philo[i].nb_meals == 0)
			{
				gen_data->number_meals--;
				pthread_detach(gen_data->philo[i].thread);
			}
			if (gen_data->number_meals == 0)
				return (NULL);
			if ((ft_get_time() - gen_data->st_time)
				> gen_data->philo[i].t_t_die)
			{
				ft_dead(ft_get_time() - gen_data->st_time,
					gen_data->philo[i].philo_id, gen_data);
				return (NULL);
			}
		}
	}
}

/*
* Funcion que crea hilo adicional para comprobar si un filosofo ha muerto.
* Si un filosofo muere, debe cambiar la variable de la estructura
* t_general->is_dead a valor "1".
*/
int	ft_philo_watcher(t_general *gen_data)
{
	pthread_t	watcher;

	if (pthread_create(&watcher, NULL, &ft_philo_dead, gen_data) != 0)
	{
		ft_error_msg("Error creating the watcher thread!,\n");
		return (1);
	}
	if (pthread_join(watcher, NULL) != 0)
	{
		ft_error_msg("Error creating the watcher thread!,\n");
		return (1);
	}
	return (0);
}
