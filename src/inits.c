/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:26:26 by jflorido          #+#    #+#             */
/*   Updated: 2023/08/04 13:33:24 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
* Inicializar cada filosofo con sus datos
*/
int	ft_init_philo(t_general *gen_data)
{
	int	i;

	i = -1;
	gen_data->philo = malloc(sizeof(t_philo) * gen_data->tot_philos);
	if (!gen_data->philo)
		return (1);
	while (++i < gen_data->tot_philos)
	{
		gen_data->philo[i].philo_id = i + 1;
		gen_data->philo[i].t_t_die = gen_data->t_t_die;
		gen_data->philo[i].t_t_eat = gen_data->t_t_eat;
		gen_data->philo[i].t_t_sleep = gen_data->t_t_sleep;
		gen_data->philo[i].l_fork = &gen_data->m_forks[i];
		gen_data->philo[i].r_fork = &gen_data->m_forks[(i + 1) % gen_data->tot_philos];
		gen_data->philo[i].nb_meals = 0;
		//continuar con datos
		printf("Filosofo [%d] iniciados.\n", gen_data->philo[i].philo_id);
	}
	// printf("Datos philo 0 --> id: %d\n", gen_data->philo[0].philo_id);
	// printf("Datos philo 0 --> t_t_die: %d\n", gen_data->philo[0].t_t_die);
	// printf("Datos philo 0 --> t_t_sleep: %d\n", gen_data->philo[0].t_t_sleep);
	// printf("Datos philo 0 --> nb_meals: %d\n", gen_data->philo[0].nb_meals);
	return (0);
}

/*
* Inicializar los mutex de los tenedores y el mutex para el chequeo de muerte
*/

int	ft_init_mutex(t_general *gen_data)
{
    int	i;

	gen_data->m_forks = malloc(sizeof(pthread_mutex_t) * gen_data->tot_philos); //TODO Liberar
	if (!gen_data->m_forks)
		return (1);
	i = -1;
	while (++i < gen_data->tot_philos)
		pthread_mutex_init(&gen_data->m_forks[i], NULL);
	pthread_mutex_init(&gen_data->m_check_dead, NULL);
	 printf("Mutex creados!!\n");
	//Llamar a Inicializar filosofos
	ft_init_philo(gen_data);
	return (0);
}

/*
* Carga de datos inicial
*/
int ft_initial_data_load(int argc, char **argv)
{
    t_general	*gen_data;

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
     printf("Total philos: %d\n", gen_data->tot_philos);
     printf("Tiempo de muerte: %d\n", gen_data->t_t_die);
    //Crear los mutex
	if (ft_init_mutex(gen_data) == 1)
		return (1);
    return (0);
}