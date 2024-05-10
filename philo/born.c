/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   born.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:02:51 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/10 18:13:51 by amousaid         ###   ########.fr       */
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

int	done_eating(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo[0].mutex->eat_mutex);
	while (i < philo->info->philo_num)
	{
		if (philo[i].eat_count != philo[i].info->must_eat)
			return (pthread_mutex_unlock(&philo[0].mutex->eat_mutex), 0);
		i++;
	}
	pthread_mutex_unlock(&philo[0].mutex->eat_mutex);
	return (1);
}

void	*main_check(void *threds)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)threds;
	while (done_eating(philo) == 0)
	{
		i = -1;
		while (++i < philo->info->philo_num)
		{
			pthread_mutex_lock(&philo[i].mutex->eat_mutex);
			if (get_time() - philo[i].last_eat > philo[i].info->death_time
				&& philo[i].is_eating == 0
				&& philo[i].eat_count != philo[i].info->must_eat)
			{
				pthread_mutex_unlock(&philo[i].mutex->eat_mutex);
				print(&philo[i], RED "🪦 died🪦" RESET);
				i = 0;
				while (i < philo->info->philo_num)
				{
					pthread_mutex_lock(&philo[i].mutex->dead_mutex);
					philo[i].dead = 1;
					pthread_mutex_unlock(&philo[i++].mutex->dead_mutex);
				}
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].mutex->eat_mutex);
		}
	}
	return (threds);
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
