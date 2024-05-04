/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   born.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:02:51 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/04 11:12:31 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_data(t_info info, t_philo *threads)
{
    int i;

    i = 0;
    while (i < info.philo_num && info.philo_num <= 300)
    {
        threads[i].id = i + 1;
        threads[i].last_eat = 0;
        i++;
    }
    
}

void *main_check(void *threds)
{
    t_info philo;

    philo = *(t_info *)threds;
    
}
void    ft_born_philo(t_info info, t_philo *threads)
{
    pthread_t main_thread;
    int i;
    
    pthread_create(&main_thread, NULL, main_check, NULL);
    pthread_join(main_thread, NULL);
    i = 0;
    while (i < info.philo_num)
    {
        pthread_create(&threads[i].thread, NULL, philo_life,  &info);
        pthread_join(threads[i].thread, NULL);
    }
    
}
