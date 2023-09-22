/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:59:29 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/22 16:24:28 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * #FT_PHILO_DEAD
 * 		Function that prints the dead message and change the is_dead value
 *
 * #PARAMETERS
 * 		- t_time --> time of execition to be printed.
 * 		- philo_id --> identification of the philosophe.
 * 		- *gen_data --> general data struct (where the variable is_dead is).
 *
 * #RETURN
 * 		-
 */

void	ft_dead(int t_time, int philo_id, t_general *gen_data)
{
	printf("%d		%d  died.\n", t_time, philo_id);
	gen_data->is_dead = 1;
}

/*
 * #FT_PHILO_DEAD
 * 		Function that checks if the dead time has been excedeed. If so
 * 		The function calls ft_dead that prints the dead message and chenge
 * 		the status of the variable is_dead to 1.
 * 		This function also checks if each philosophe has eaten the number
 * 		of meals set in the parameters and discount the in the number_meals.
 *
 * #PARAMETERS
 * 		- (void *arg) --> *gen_data -> Pointer to the general struct.
 *
 * #RETURN
 * 		-
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
 * #FT_PHILO_WATCHER
 * 		Function that launches an additional trhread that is pending 
 * 		of the philosophers dead time.
 *
 * #PARAMETERS
 * 		- *gen_data -> Pointer to the general struct.
 *
 * #RETURN
 * 		- 0 when function finishes
 * 		- 1 if there is a problen creatin the thread or the join
 */

int	ft_philo_watcher(t_general *gen_data)
{
	pthread_t	watcher;

	if (gen_data->tot_philos > 1)
	{
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
	}
	return (0);
}
