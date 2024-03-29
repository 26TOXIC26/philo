/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:04:36 by pc                #+#    #+#             */
/*   Updated: 2024/03/28 11:09:13 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

//struct
typedef struct s_info
{
    int philo_num;
    int death_time;
    int eat_time;
    int sleep_time;
    int must_eat;
}   t_info;

//functions
int	ft_isdigit(int c);
int check_arg(int argc, char **args);
int	ft_atoi(const char *str);
void	is_error(void);

#endif