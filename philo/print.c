/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:57:59 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/07 14:59:15 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->print);
    printf("[%ldms] philo %d %s\n", get_time()-philo->start_time ,philo->id, str);
    pthread_mutex_unlock(&philo->print);
}