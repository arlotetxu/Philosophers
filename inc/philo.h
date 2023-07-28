/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:23:18 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/28 17:36:21 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//HEADERS
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

//DEFINES
# define max_int 2147483647
# define min_int -2147483648

//STRUCTS

typedef struct s_philo
{
	int		            philo_id;
    int			        t_t_die;
	int			        t_t_eat;
	int			        t_t_sleep;
	struct	s_general	*general;
} 	                    t_philo;

typedef struct s_general
{
	int 			tot_philos;
	int			    t_t_die;
	int			    t_t_eat;
	int			    t_t_sleep;
	int             st_time;
	int 			number_meals; //numero de veces que tiene que comer
	int 			is_dead;
	pthread_t		*thread;
    pthread_mutex_t m_check_dead;
	pthread_mutex_t *m_forks;
	t_philo			*philo;
}	                t_general;



//Including functions

//UTILS
void		ft_error_msg(char *msg);
void		ft_free(char *str, char **str_2);
long	    ft_atoi_phi(char *nb);

//CHECKS
int         ft_arg_is_nb(char **argv);
int         ft_arg_in_int(char **argv);

//PHILO_UTILS
int         ft_initial_data_load(int argc, char **argv);

#endif //PHILO_H
