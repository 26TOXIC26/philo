/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:46:52 by pc                #+#    #+#             */
/*   Updated: 2024/05/10 18:08:47 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initialize(int argc, char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->death_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
}

void	init_mutex(t_mutex *mutex)
{
	pthread_mutex_init(&mutex->dead_mutex, NULL);
	pthread_mutex_init(&mutex->print_mutex, NULL);
	pthread_mutex_init(&mutex->eat_mutex, NULL);
}

int	main(int argc, char **argv)
{
	t_info			info;
	t_mutex			mutex;
	t_philo			threads[300];
	pthread_mutex_t	forks[300];

	if (argc == 5 || argc == 6)
	{
		if (check_arg(argc, argv) == 0)
			return (is_error());
		ft_initialize(argc, argv, &info);
		init_forks(info, forks);
		init_mutex(&mutex);
		philo_data(&info, threads, forks, &mutex);
		ft_born_philo(info, threads);
		destroy_kolchi(forks, threads);
	}
	else
		return (is_error());
}
