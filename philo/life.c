/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:02:22 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/07 15:09:59 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eating(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    print(philo, "has taken a fork");
    if (philo->info->philo_num == 1)
    {
        usleep(philo->info->death_time * 1000);
        pthread_mutex_unlock(philo->r_fork);
        return (0);
    }
    pthread_mutex_lock(philo->l_fork);
    print(philo, "has taken a fork");
    print(philo, "is eating");
    philo->last_eat = get_time();
    usleep(philo->info->eat_time * 1000);
    philo->eat_count++;
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
    return (1);
}

void sleeping(t_philo *philo)
{
    print(philo, "is sleeping");
    usleep(philo->info->sleep_time * 1000);
}

void thinking(t_philo *philo)
{
    print(philo, "is thinking");
}

int dead_philo(t_philo *philo)
{
    if (philo->dead != 0 || philo->eat_count >= philo->info->must_eat)
        return (0);
    return (1);
}

void *philo_life(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *)ptr;
    if (philo->id % 2 == 0)
        usleep(1000);
    while (dead_philo(philo))
    {
        if (eating(philo) == 0)
            return ((void *)0);
		sleeping(philo);
	    thinking(philo);
    }
    return(ptr);
}