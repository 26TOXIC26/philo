/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:04:36 by pc                #+#    #+#             */
/*   Updated: 2024/05/16 13:26:50 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// struct

typedef struct s_info
{
	int				philo_num;
	size_t			death_time;
	size_t			eat_time;
	size_t			sleep_time;
	int				must_eat;
}					t_info;

// functions
int					ft_isdigit(int c);
int					check_arg(int argc, char **args);
int					ft_atoi(const char *str);
int					is_error(void);
size_t				get_time(void);

// colors
# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"

#endif