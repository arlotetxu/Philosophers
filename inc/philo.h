/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:23:18 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/24 10:18:02 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_PHILO_H
#define PHILOSOPHERS_PHILO_H

//HEADERS
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//STRUCTS

typedef struct s_philo{
	int		philo_id;
	struct	s_general	*general;
} 	t_philo;

typedef struct s_general{
	int 			tot_philos;
	long			t_t_die;
	long			t_t_eat;
	long			t_t_sleep;
	long 			st_time;
	int 			number_meals; //numero de veces que tiene que comer
	int 			is_dead;
	pthread_t		*thread;
	pthread_mutex_t *m_forks;
	t_philo			*philo;
}	t_general;



//Including functions

//UTILS
void		ft_error_msg(char *msg);
void		ft_free(char *str, char **str_2);
long	ft_atoi_phi(char *nb);

//CHECKS
int         ft_arg_is_nb(char **argv);

#endif //PHILOSOPHERS_PHILO_H
