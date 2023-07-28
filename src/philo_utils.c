/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:26:26 by jflorido          #+#    #+#             */
/*   Updated: 2023/07/28 17:39:24 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* Carga de datos inicial
*/
int ft_initial_data_load(int argc, char **argv)
{
    t_general   *gen_data;
    
    gen_data = malloc(sizeof(t_general)); //TODO Liberar
    if (!gen_data)
        return (1);
    gen_data->tot_philos = ft_atoi_phi(argv[1]);
    gen_data->t_t_die = ft_atoi_phi(argv[2]);
    gen_data->t_t_eat = ft_atoi_phi(argv[3]);
    gen_data->t_t_sleep = ft_atoi_phi(argv[4]);
    if (argc == 6)
        gen_data->number_meals = ft_atoi_phi(argv[5]);
    else
        gen_data->number_meals = 0; //TODO comprobar si 0 es correcto y no interfiere con la logica del programa
    gen_data->is_dead = 0;
    // printf("Total philos: %d\n", gen_data->tot_philos);
    // printf("Tiempo de muerte: %d\n", gen_data->t_t_die);
    //Crear los mutex
    return (0);
}