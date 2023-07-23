/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:13:22 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/23 18:35:04 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_error_msg(char *msg)
{
    int	i;

	i = 0;
	while (msg[i])
		i++;
    write(0,"\x1b[31m", 6);
    write(1, msg, i);
	write(0, "\x1b[0m", 5);
}