/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:02:22 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/06 20:36:04 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eating(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    printf("philo %d has taken a fork\n", philo->id);
    if (philo->info->philo_num == 1)
    {
        usleep(philo->info->death_time * 1000);
        pthread_mutex_unlock(philo->r_fork);
        return (0);
    }
    pthread_mutex_lock(philo->l_fork);
    printf("philo %d has taken a fork\n", philo->id);
    printf("philo %d is eating\n", philo->id);
    philo->last_eat = get_time();
    usleep(philo->info->eat_time * 1000);
    philo->eat_count++;
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
    return (1);
}

void sleeping(t_philo *philo)
{
    printf("philo %d is sleeping\n", philo->id);
    usleep(philo->info->sleep_time * 1000);
}

void thinking(t_philo *philo)
{
    printf("philo %d is thinking\n", philo->id);
}

void *philo_life(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *)ptr;
    if (philo->id % 2 == 0)
        usleep(1);
    while (1)
    {
        if (eating(philo) == 0)
            return ((void *)0);
        eating(philo);
		sleeping(philo);
	    thinking(philo);
    }
    return(ptr);
}