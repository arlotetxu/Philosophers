
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:29:29 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/24 10:58:14 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* Comprobar que tengo argumentos no nulos y son numericos
*/

int ft_arg_is_nb(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        if (argv[i][0] == '\0')
            return (ft_error_msg("Error.\nEmpty argument.\n"), 1);
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] != '+' && (argv[i][j] < '0' || argv[i][j] > '9'))
                return (ft_error_msg("Error.\nArg is not a number or is < 0.\n"), 1);
            j++;
        }
        i++;
    }
    return (0);
}

/*
* Comprobamos si los argumentos son numericos convirtiendolos 
* con la funcion ft_atoi_philo
*/

// int ft_arg_is_nb(char **argv)
// {
//     int         i;
//     long long   nb;
    
//     i = 0;
//     while (argv[i])
//     {
//         nb = ft_atoi_phi(argv[i]);
//         if (nb < 0 || nb == NULL)
//             return (ft_error_msg("Error.\nInvalid argument.\n"), 1);
//         i++;
//     }
//     return (0);
// }