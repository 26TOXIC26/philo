/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_thread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:56:12 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/11 22:58:18 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_lock(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->philo_num)
	{
		pthread_mutex_lock(&philo[i].mutex->dead_mutex);
		philo[i].dead = 1;
		pthread_mutex_unlock(&philo[i++].mutex->dead_mutex);
	}
}

void	*main_check(void *threds)
{
	t_philo	*philo;
	int		i;

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
				ft_lock(philo);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].mutex->eat_mutex);
		}
	}
	return (threds);
}
