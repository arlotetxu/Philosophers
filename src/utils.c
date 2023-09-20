/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:13:22 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/20 19:33:28 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* 1
* Function to show the error messages
*/
void	ft_error_msg(char *msg)
{
	printf("\x1b[31m" "%s" "\x1b[0m", msg);
}

/*
* 2
* Function to print the philo actions
*/
void	ft_print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->general->gen_mutex));
	if (philo->general->is_dead == 0)
		printf ("%d		%d %s", ft_get_time() - philo->general->st_time,
			philo->philo_id, msg);
	pthread_mutex_unlock(&philo->general->gen_mutex);
}

/*
* 3
* ATOI
*/
long	ft_atoi_phi(char *nb)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nb[i] != '\0' && nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	if (nb[i] == '-')
		sign = -1;
	while (nb[i] != '\0' && nb[i] == '+')
		i++;
	while (nb[i] != '\0' && nb[i] >= '0' && nb[i] <= '9')
	{
		result = result * 10 + (nb[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
* 4
* Obtener la fecha
*/

int	ft_get_time(void)
{
	int				get_time;
	struct timeval	tv;

	get_time = 0;
	if (gettimeofday(&tv, NULL) == 0)
	{
		get_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	}
	return (get_time);
}

/*
5
* Funcion sleep para mantenerse haciendo una accion
*/

void	ft_sleep(int m_sec)
{
	int	time;

	time = ft_get_time();
	while ((ft_get_time() - time) < m_sec)
		usleep(100);
}
