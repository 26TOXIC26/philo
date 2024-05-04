/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:04:36 by pc                #+#    #+#             */
/*   Updated: 2024/05/03 17:26:26 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
#include <unistd.h>

//struct
typedef struct s_philo
{
    pthread_t thread;
    int id;
    int last_eat;
    long start_time;


    //mutex
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    
}   t_philo;

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
int	is_error(void);
long get_time();
void    philo_data(t_info info, t_philo *threads);
void    ft_born_philo(t_info info, t_philo *threads);

#endif