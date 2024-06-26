/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   born.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:02:51 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/13 12:38:05 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_data(t_info *info, t_philo *threads, pthread_mutex_t *forks,
		t_mutex *mutex)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		threads[i].id = i + 1;
		threads[i].last_eat = get_time();
		threads[i].start_time = get_time();
		threads[i].info = info;
		threads[i].eat_count = 0;
		threads[i].l_fork = &forks[i];
		threads[i].dead = 0;
		threads[i].is_eating = 0;
		threads[i].mutex = mutex;
		if (i == 0)
			threads[i].r_fork = &forks[info->philo_num - 1];
		else
			threads[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(t_info info, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info.philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	ft_born_philo(t_info info, t_philo *threads)
{
	pthread_t	main_thread;
	int			i;

	i = 0;
	pthread_create(&main_thread, NULL, main_check, threads);
	while (i < info.philo_num)
	{
		pthread_create(&threads[i].thread, NULL, philo_life, &threads[i]);
		i++;
	}
	i = 0;
	while (i < info.philo_num)
	{
		pthread_join(threads[i].thread, NULL);
		i++;
	}
	pthread_join(main_thread, NULL);
}
