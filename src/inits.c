/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:26:26 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/21 16:50:19 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * #FT_INIT_PHILO
 * 		initializes all the info for all the philosophes (threads).
 *
 * #PARAMETERS
 * 		- *gen_data -> Pointer to the general struct.
 *
 * #RETURN
 * 		- 0 when the function finishes properly.
 * 		- 1 if the malloc fails.
 */
int	ft_init_philo(t_general *gen_data)
{
	int	i;

	i = -1;
	gen_data->philo = malloc(sizeof(t_philo) * gen_data->tot_philos);
	if (!gen_data->philo)
	{
		ft_error_msg("Error allocating memomry for philos!.\n");
		return (1);
	}
	while (++i < gen_data->tot_philos)
	{
		gen_data->philo[i].philo_id = i + 1;
		gen_data->philo[i].t_t_die = gen_data->t_t_die;
		gen_data->philo[i].t_t_eat = gen_data->t_t_eat;
		gen_data->philo[i].t_t_sleep = gen_data->t_t_sleep;
		gen_data->philo[i].l_fork = &gen_data->m_forks[i];
		gen_data->philo[i].r_fork = &gen_data->m_forks[(i + 1)
			% gen_data->tot_philos];
		gen_data->philo[i].nb_meals = gen_data->number_meals;
		gen_data->philo[i].general = gen_data;
	}
	return (0);
}

/*
 * #FT_INIT_MUTEX
 * 		initializes all the mutex needed to run the threads properly
 * 		Launches the function ft_init_philo.
 *
 * #PARAMETERS
 * 		- *gen_data -> Pointer to the general struct.
 *
 * #RETURN
 * 		- 0 when the function finishes properly.
 * 		- 1 if the function ft_init_philo return an error.
 */

int	ft_init_mutex(t_general *gen_data)
{
	int	i;

	gen_data->m_forks = malloc(sizeof(pthread_mutex_t) * gen_data->tot_philos);
	if (!gen_data->m_forks)
	{
		ft_error_msg("Error allocating memory to m_forks!.\n");
		return (1);
	}
	i = -1;
	while (++i < gen_data->tot_philos)
		pthread_mutex_init(&(gen_data->m_forks[i]), NULL);
	pthread_mutex_init(&(gen_data->gen_mutex), NULL);
	if (ft_init_philo(gen_data) == 1)
	{
		free(gen_data->m_forks);
		return (1);
	}
	return (0);
}

/*
 * #FT_INITIAL_DATA_LOAD
 * 		save all the arguments values in the general struct.
 * 		Launch the ft_init_mutex to initialize all the needed mutex.
 *
 * #PARAMETERS
 * 		- *gen_data -> Pointer to the general struct.
 * 		- argc -> number of parameters introduced by the user
 * 		- **argv -> Array with the value of the parameters.
 *
 * #RETURN
 * 		- 0 when the function finishes properly.
 * 		- 1 if the function ft_init_mutex return an error.
 */

int	ft_initial_data_load(t_general *gen_data, int argc, char **argv)
{
	gen_data->tot_philos = ft_atoi_phi(argv[1]);
	gen_data->t_t_die = ft_atoi_phi(argv[2]);
	gen_data->t_t_eat = ft_atoi_phi(argv[3]);
	gen_data->t_t_sleep = ft_atoi_phi(argv[4]);
	if (argc == 6)
		gen_data->number_meals = ft_atoi_phi(argv[5]);
	else
		gen_data->number_meals = -1;
	gen_data->is_dead = 0;
	if (ft_init_mutex(gen_data) == 1)
		return (1);
	return (0);
}
