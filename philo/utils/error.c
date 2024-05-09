/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:39 by amousaid          #+#    #+#             */
/*   Updated: 2024/05/09 10:17:38 by amousaid         ###   ########.fr       */
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
