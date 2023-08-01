/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:13:22 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/29 12:37:51 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* 1
* Function to show the error messages
*/
void	ft_error_msg(char *msg)
{
    // int	i;

	// i = 0;
	// while (msg[i])
	// 	i++;
    // write(0,"\x1b[31m", 6);
    // write(1, msg, i);
	// write(0, "\x1b[0m", 5);
    printf("\x1b[31m" "%s" "\x1b[0m", msg);
}

/*
* 2
* Function to frees all string and **strings
*/
void	ft_free(char *str, char **str_2)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		while (str_2[i])
			free(str_2[i++]);
		free(str_2[i]);
		free(str_2);
	}
	else
		free(str);
}

/*
* 3
* ATOI
*/
long	ft_atoi_phi(char *nb)
{
	int			i;
	int			sign;
	long 		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nb[i] != '\0' && nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	if (nb[i] == '-')
	// 	return (ft_error_msg("Error.\nValue < 0\n"), 1);
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

long	ft_get_time()
{
	long			get_time;
	struct	timeval	tv;

	get_time = 0;
	if (gettimeofday(&tv, NULL) == 0)
	{
		// printf("Segundos: %ld\n", tv.tv_sec);
		// printf("Microsegundos: %ld\n", tv.tv_usec);
		get_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		printf("Tiempo en milisec: %ld\n", get_time);
	}
	return (get_time);
}


