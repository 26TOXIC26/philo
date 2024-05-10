/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:39 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/10 18:09:03 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_error(void)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃          Please enter 4 or 5 arguments       ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃  [1]Number of philosophers                   ┃\n");
	printf("┃  [2]Time to die                              ┃\n");
	printf("┃  [3]Time to eat                              ┃\n");
	printf("┃  [4]Time to sleep                            ┃\n");
	printf("┃  [5]Number of meals                          ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	return (0);
}

void destroy_kolchi(pthread_mutex_t *forks, t_philo *philos)
{
	int i;

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