/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:29:29 by jflorido          #+#    #+#             */
/*   Updated: 2023/09/21 16:55:19 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* Comprobar que los argumentos no exceden los limites de INT
*/
/*
 * #FT_ARG_IN_INT
 * 		Checks if the numbers introduced as arguments are not exceeding
 * 		the int data type range.
 *
 * #PARAMETERS
 * 		- **argv -> The array with all the arguments
 *
 * #RETURN
 * 		- 0 when any argument doesn't exceed the int range.
 * 		- 1 if any argument exceed the int range.
 */
int	ft_arg_in_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoi_phi(argv[i]) > MAX_INT || ft_atoi_phi(argv[i]) < MIN_INT)
		{
			printf ("\x1b[31m" "Error.\nArg[%d] out of the INT limits!\n", i);
			return (1);
		}
	}
	return (0);
}

/*
 * #FT_ARG_IS_NB
 * 		Checks if the arguments are not null and they are numerics
 *
 * #PARAMETERS
 * 		- *gen_data -> Pointer to the general struct.
 *
 * #RETURN
 * 		- 0 when the function finishes properly.
 * 		- 1 if the function ft_init_philo return an error.
 */

int	ft_arg_is_nb(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi_phi(argv[i]) <= 0)
			return (ft_error_msg("Error.\nThere is an Arg <= 0\n"), 1);
		if (argv[i][0] == '\0')
			return (ft_error_msg("Error.\nEmpty argument.\n"), 1);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '+' && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (ft_error_msg("Error.\nArg is not a number.\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}
