/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:02:22 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/09 18:01:29 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(philo, BLUE "🍴 has taken a fork 🍴" RESET);
	if (philo->info->philo_num == 1)
	{
		ft_usleep(philo->info->death_time);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	if (pthread_mutex_lock(philo->l_fork) != 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	print(philo, BLUE "🍴 has taken a fork 🍴" RESET);
	print(philo, GREEN "🍝 is eating 🍝" RESET);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	ft_usleep(philo->info->eat_time);
	philo->eat_count++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (1);
}

void	sleeping(t_philo *philo)
{
	philo->is_eating = 0;
	print(philo, YELLOW "💤 is sleeping 💤" RESET);
	ft_usleep(philo->info->sleep_time);
}

void	thinking(t_philo *philo)
{
	print(philo, PURPLE "🤔 is thinking 🤔" RESET);
}

int	dead_philo(t_philo *philo)
{
	if (philo->dead > 0 || philo->eat_count == philo->info->must_eat)
		return (0);
	return (1);
}

void	*philo_life(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(2);
	while (dead_philo(philo))
	{
		if (eating(philo) == 0)
			return ((void *)0);
		sleeping(philo);
		thinking(philo);
	}
	return (ptr);
}
