/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:16 by grobledo          #+#    #+#             */
/*   Updated: 2024/06/07 16:54:37 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_create(t_data *data)
{
	int	i;
	int	launched;

	i = 0;
	launched = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->thread[i], NULL,
				philo_run, &data->philos[i]) == -1)
			break ;
		i++;
		launched++;
	}
	if (i < data->philo_num)
	{
		pthread_mutex_lock(&data->deadmutex);
		data->dead = true;
		pthread_mutex_unlock(&data->deadmutex);
	}
	return (launched);
}

static int	boucleverif(t_data *data, int i)
{
	long long int	tmp;

	pthread_mutex_lock(&data->timeleft);
	tmp = data->philos[i].digest_time;
	pthread_mutex_unlock(&data->timeleft);
	if (tmp != 0 && deathcheck(&data->philos[i], tmp) == 1)
	{
		pthread_mutex_lock(&data->deadmutex);
		data->dead = true;
		pthread_mutex_unlock(&data->deadmutex);
		return (1);
	}
	return (0);
}

static void	verifdeath(t_data *data)
{
	int	i;
	int	full;

	full = 0;
	while (full != data->philo_num)
	{
		i = 0;
		full = 0;
		while (i < data->philo_num)
		{
			if (checkmealcount(data, i) == 1)
			{
				full++;
				i++;
				continue ;
			}
			if (boucleverif(data, i) == 1)
				return ;
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		launched;

	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("Error : invalid number of arguments\n"));
	while (argv[i])
	{
		if (checkchar(argv[i++]) == 1)
			return (printf("Error : argument must be a number\n"));
	}
	if (init(&data, argv, argc) != 0)
		return (1);
	data.start_time = get_time();
	launched = philo_create(&data);
	if (launched == data.philo_num)
		verifdeath(&data);
	i = 0;
	while (i < launched)
		pthread_join(data.thread[i++], NULL);
	free_mutex(&data);
	return (0);
}
