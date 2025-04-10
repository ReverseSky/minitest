/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:12:44 by grobledo          #+#    #+#             */
/*   Updated: 2024/06/07 16:53:11 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

unsigned long long int	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	deathcheck(t_philo *data, unsigned long long int time)
{
	if (get_time() > time + data->data->death_time)
	{
		mutex_print(data, "died");
		pthread_mutex_lock(&data->data->deadmutex);
		data->data->dead = true;
		pthread_mutex_unlock(&data->data->deadmutex);
		return (1);
	}
	return (0);
}

int	mutex_print(t_philo *data, char *str)
{
	unsigned long long int	time;

	time = (get_time() - data->data->start_time);
	pthread_mutex_lock(&data->data->deadmutex);
	if (data->data->dead == true)
	{
		pthread_mutex_unlock(&data->data->deadmutex);
		return (1);
	}
	printf("%lld %d %s\n", time, data->id, str);
	pthread_mutex_unlock(&data->data->deadmutex);
	return (0);
}

int	waittime(t_philo *data, unsigned long long int time)
{
	while (get_time() < data->start_action + time)
		usleep(100);
	return (0);
}
