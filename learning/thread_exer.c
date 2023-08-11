#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	*ft_save_primes(void)
{
	int	count;
	int	nb;
	int	*nb_arr;

	count = 0;
	nb = 2;
	nb_arr = malloc(sizeof(int) * 12);
	while (count < 12)
	{
		if (ft_is_prime(nb) == 1)
		{
			nb_arr[count] = nb;
			count++;
		}
		nb++;
	}
	return (nb_arr);
}

//void	*ft_get_nb(void *index)
int	*ft_get_nb(void *index)
{
	int	*nb_arr;
	int	i;
	int	res;
	int ind = *(int*)index + 6;

	printf("Valor de Index: %d\n", *(int*)index);
	printf("Valor de Ind: %d\n", ind);
	i = *(int *)index;
	res = 0;
	nb_arr = ft_save_primes();
	while (i < ind)
		res += nb_arr[i++];
	i = *(int *)index;
	while (i < ind)
	{
		printf("Index[%d]: %d\n", i, nb_arr[i]);
		i++;
	}
	*(int*)index = res;
	return (index);
}

int	main(void)
{
	pthread_t	th[2];
	int			i;
	int			sum;

	sum = 0;
	i = -1;
	while (++i < 2)
	{
		int *a = malloc(sizeof(int));
		*a = i * 6;
		//printf("El valor de a: %d\n", *a);
		if (pthread_create(&th[i], NULL, (void *)&ft_get_nb, (void *)a) != 0)
			return (1);
	}
	i = -1;
	while (++i < 2)
	{
		int	*res;
		res = 0;
		if (pthread_join(th[i], (void *)&res) != 0)
			return (1);
		sum += *res;
		free(res);
	}
	printf("Resultado final suma: %d\n", sum);
	return (0);
}
