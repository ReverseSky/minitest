/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:45 by grobledo          #+#    #+#             */
/*   Updated: 2024/06/07 16:51:30 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define MAX_PHILO 200

typedef enum e_status
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
}	t_status;

typedef struct s_philo
{
	struct s_data			*data;
	int						id;
	t_status				status;
	int						meal_count;
	unsigned long long int	start_action;
	unsigned long long int	digest_time;
	bool					taken[2];
	pthread_t				thread;
	long int				last_eat;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*l_fork;
}		t_philo;

typedef struct s_data
{
	pthread_t				thread[MAX_PHILO];
	int						philo_num;
	int						max_meals;
	bool					dead;
	int						finished;
	t_philo					philos[MAX_PHILO];
	long long int			death_time;
	long long int			eat_time;
	long long int			sleep_time;
	unsigned long long int	start_time;
	pthread_mutex_t			forks[MAX_PHILO];
	pthread_mutex_t			lock;
	pthread_mutex_t			write;
	pthread_mutex_t			deadmutex;
	pthread_mutex_t			timeleft;
	pthread_mutex_t			bonrepas;
}	t_data;

int						checkchar(char *str);
int						main(int argc, char **argv);
int						init(t_data *data, char **argv, int argc);
unsigned long long int	get_time(void);
int						mutex_print(t_philo *data, char *str);
int						deathcheck(t_philo *data, unsigned long long int time);
void					*philo_run(void *data);
int						waittime(t_philo *data, unsigned long long int time);
int						checkmealcount(t_data *data, int i);
void					free_mutex(t_data *data);

#endif