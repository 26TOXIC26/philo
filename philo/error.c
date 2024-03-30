/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:39 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/30 03:25:21 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_error(void)
{
	printf("Error in arg\n");
	printf("--->your input most be positive and ofcourse most be number (number!!!!!!)\n");
	printf("--->and you can put 4 or 5 arg not more or less then\n");
	exit(0);
}
