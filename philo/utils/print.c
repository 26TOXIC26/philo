/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:57:59 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/10 18:17:26 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->mutex->print_mutex);
	pthread_mutex_lock(&philo->mutex->dead_mutex);
	if (philo->dead > 0)
	{
		pthread_mutex_unlock(&philo->mutex->print_mutex);
		pthread_mutex_unlock(&philo->mutex->dead_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->mutex->dead_mutex);
	printf("[%ld ms] philo %d %s\n", get_time() - philo->start_time, philo->id,
		str);
	pthread_mutex_unlock(&philo->mutex->print_mutex);
}
