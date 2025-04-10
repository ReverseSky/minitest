/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:52:02 by grobledo          #+#    #+#             */
/*   Updated: 2024/06/07 16:52:40 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkmealcount(t_data *data, int i)
{
	pthread_mutex_lock(&data->bonrepas);
	if (data->philos[i].meal_count == data->max_meals)
	{
		pthread_mutex_unlock(&data->bonrepas);
		return (1);
	}
	pthread_mutex_unlock(&data->bonrepas);
	return (0);
}

void	free_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->deadmutex);
	pthread_mutex_destroy(&data->bonrepas);
}
