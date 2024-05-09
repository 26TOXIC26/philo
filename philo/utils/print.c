/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:57:59 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/09 16:02:50 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    print(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->print);
    if (philo->dead > 0)
    {
        pthread_mutex_unlock(&philo->print);
        return ;
    }
    printf("[%ld ms] philo %d %s\n", get_time()-philo->start_time ,philo->id, str);
    pthread_mutex_unlock(&philo->print);
}