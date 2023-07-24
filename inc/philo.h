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
typedef struct s_data{
	int 		tot_philos;
	long long	t_t_die;
	long long	t_t_eat;
	long long	t_t_sleep;
	int 		must_eat; //numero de veces que tiene que comer
	
}	t_data;

typedef struct s_philo{
	int		philo_id;
	t_data	*philo_data;
} 	t_philo;

//Including functions

//UTILS
void		ft_error_msg(char *msg);
void		ft_free(char *str, char **str_2);
long long	ft_atoi_phi(char *nb);

//CHECKS
int         ft_arg_is_nb(char **argv);

#endif //PHILOSOPHERS_PHILO_H
