/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:57:59 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/09 20:34:30 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->mutex->print_mutex);
	if (philo->dead > 0)
	{
		pthread_mutex_unlock(&philo->mutex->print_mutex);
		return ;
	}
	printf("[%ld ms] philo %d %s\n", get_time() - philo->start_time, philo->id,
		str);
	pthread_mutex_unlock(&philo->mutex->print_mutex);
}
