/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:52:31 by grobledo          #+#    #+#             */
/*   Updated: 2024/05/31 16:49:00 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	number;

	i = 0;
	is_neg = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg *= -1;
		i++;
	}
	while (str [i] >= '0' && str[i] <= '9')
		number = (number * 10) + str[i++] - 48;
	return (number * is_neg);
}

static int	init_data(t_data *data, char **argv, int argc)
{
	data->philo_num = (int) ft_atoi(argv[1]);
	data->death_time = (long long int) ft_atoi(argv[2]);
	data->eat_time = (long long int) ft_atoi(argv[3]);
	data->sleep_time = (long long int) ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals = (int) ft_atoi(argv[5]);
	else
		data->max_meals = -1;
	if (data->philo_num <= 0 || data->philo_num > MAX_PHILO
		|| data->death_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
		return (printf("Error : wrong argument\n"));
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->deadmutex, NULL);
	pthread_mutex_init(&data->timeleft, NULL);
	pthread_mutex_init(&data->bonrepas, NULL);
	return (0);
}

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].meal_count = 0;
		data->philos[i].status = THINKING;
		data->philos[i].taken[0] = false;
		data->philos[i].taken[1] = false;
		data->philos[i].digest_time = 0;
		i++;
	}
	return (0);
}

static int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks[i++], NULL);
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	data->philos[0].l_fork = &data->forks[0];
	i = 1;
	while (i < data->philo_num)
	{
		if (i % 2 != 0)
		{
			data->philos[i].r_fork = &data->forks[i];
			data->philos[i].l_fork = &data->forks[i - 1];
		}
		else
		{
			data->philos[i].r_fork = &data->forks[i - 1];
			data->philos[i].l_fork = &data->forks[i];
		}
		i++;
	}
	return (0);
}

int	init(t_data *data, char **argv, int argc)
{
	if (init_data(data, argv, argc))
		return (1);
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (0);
}
