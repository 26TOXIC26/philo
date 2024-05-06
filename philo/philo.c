/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:46:52 by pc                #+#    #+#             */
/*   Updated: 2024/05/06 20:30:57 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_count(t_philo *threads, t_info info)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < info.philo_num)
    {
        if (threads[i].eat_count == info.must_eat)
            count++;
        i++;
    }
    if (count == info.philo_num)
        return (0);
    return (1);
}

void ft_initialize(int argc, char **argv, t_info *info)
{
    info->philo_num = ft_atoi(argv[1]);
    info->death_time = ft_atoi(argv[2]);
    info->eat_time = ft_atoi(argv[3]);
    info->sleep_time = ft_atoi(argv[4]);
    if (argc == 6)
        info->must_eat = ft_atoi(argv[5]);
}

int main(int argc, char **argv)
{
    t_info info;
    t_philo threads[300];
    pthread_mutex_t forks[300];

    if (argc == 5 || argc == 6)
    {
        if (check_arg(argc, argv) == 0)
            return (is_error());
        ft_initialize(argc ,argv, &info);
        init_forks(info, forks);
        philo_data(info, threads, forks);
        ft_born_philo(info, threads);
        if (check_count(threads, info) == 0)
            return (0);       
    }
    else
        return (is_error());
}
