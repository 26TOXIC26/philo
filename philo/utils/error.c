/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:39 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/18 18:13:45 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_error(void)
{
	write(2, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", 146);
	write(2, "┃   Please enter 4 or 5 arguments (positive)   ┃\n", 54);
	write(2, "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n", 146);
	write(2, "┃  [1]Number of philosophers   (less than 300) ┃\n", 54);
	write(2, "┃  [2]Time to die                              ┃\n", 54);
	write(2, "┃  [3]Time to eat                              ┃\n", 54);
	write(2, "┃  [4]Time to sleep                            ┃\n", 54);
	write(2, "┃  [5]Number of meals                          ┃\n", 54);
	write(2, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n", 146);
	return (-1);
}

void	destroy_kolchi(pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philos[i].mutex->print_mutex);
	pthread_mutex_destroy(&philos[i].mutex->dead_mutex);
	pthread_mutex_destroy(&philos[i].mutex->eat_mutex);
	while (i < philos->info->philo_num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	i = 0;
}
