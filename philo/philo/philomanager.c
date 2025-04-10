/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philomanager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:00:43 by grobledo          #+#    #+#             */
/*   Updated: 2024/06/07 16:51:06 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_eating2(t_philo *data)
{
	data->start_action = get_time();
	waittime(data, data->data->eat_time);
	pthread_mutex_unlock(data->r_fork);
	data->taken[1] = false;
	pthread_mutex_unlock(data->l_fork);
	data->taken[0] = false;
	return (0);
}

static int	is_eating(t_philo *data)
{
	int	count;

	pthread_mutex_lock(data->l_fork);
	data->taken[0] = true;
	if (mutex_print(data, "has taken a fork") == 1)
		return (1);
	if (data->data->philo_num == 1)
		return (usleep(data->data->death_time), 1);
	pthread_mutex_lock(data->r_fork);
	data->taken[1] = true;
	if (mutex_print(data, "has taken a fork") == 1)
		return (1);
	pthread_mutex_lock(&data->data->timeleft);
	data->digest_time = get_time();
	pthread_mutex_unlock(&data->data->timeleft);
	if (mutex_print(data, "is eating") == 1)
		return (1);
	pthread_mutex_lock(&data->data->bonrepas);
	data->meal_count += 1;
	count = data->meal_count;
	pthread_mutex_unlock(&data->data->bonrepas);
	if (count == data->data->max_meals)
		return (1);
	is_eating2(data);
	return (0);
}

static int	is_sleeping(t_philo *data)
{
	if (mutex_print(data, "is sleeping") == 1)
		return (1);
	data->start_action = get_time();
	waittime(data, data->data->sleep_time);
	return (0);
}

static int	is_thinking(t_philo *data)
{
	data->start_action = get_time();
	return (mutex_print(data, "is thinking"));
}

void	*philo_run(void *data)
{
	t_philo	*ptdr;
	bool	temp;

	ptdr = (t_philo *)data;
	ptdr->start_action = get_time();
	pthread_mutex_lock(&ptdr->data->timeleft);
	ptdr->digest_time = ptdr->start_action;
	pthread_mutex_unlock(&ptdr->data->timeleft);
	while (1)
	{
		pthread_mutex_lock(&ptdr->data->deadmutex);
		temp = ptdr->data->dead;
		pthread_mutex_unlock(&ptdr->data->deadmutex);
		if (temp == true || is_eating(data)
			|| is_sleeping(data) || is_thinking(data))
			break ;
	}
	if (ptdr->taken[1] == true)
		pthread_mutex_unlock(ptdr->r_fork);
	if (ptdr->taken[0] == true)
		pthread_mutex_unlock(ptdr->l_fork);
	return (NULL);
}
