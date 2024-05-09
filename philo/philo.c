/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:46:52 by pc                #+#    #+#             */
/*   Updated: 2024/05/09 14:48:16 by amousaid         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_info			info;
	t_philo			threads[300];
	pthread_mutex_t	forks[300];
	pthread_mutex_t	print;

	if (argc == 5 || argc == 6)
	{
		if (check_arg(argc, argv) == 0)
			return (is_error());
		ft_initialize(argc, argv, &info);
		init_forks(info, forks);
		pthread_mutex_init(&print, NULL);
		philo_data(&info, threads, forks, print);
		ft_born_philo(info, threads);
	}
	else
		return (is_error());
}
