/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:23:18 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/29 13:32:22 by jflorido         ###   ########.fr       */
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
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
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
long		ft_atoi_phi(char *nb);
long		ft_get_time();

//CHECKS
int			ft_arg_is_nb(char **argv);
int			ft_arg_in_int(char **argv);

//PHILO_UTILS
int			ft_initial_data_load(int argc, char **argv);
int			ft_init_mutex(t_general *general);
int			ft_init_philo(t_general *gen_data);

#endif //PHILO_H
