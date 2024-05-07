/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:04:36 by pc                #+#    #+#             */
/*   Updated: 2024/05/07 15:08:21 by amousaid         ###   ########.fr       */
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

typedef struct s_info
{
    int philo_num;
    int death_time;
    int eat_time;
    int sleep_time;
    int must_eat;
}   t_info;

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int eat_count;
    int last_eat;
    size_t start_time;
    t_info *info;
    int dead;
    //mutex
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t print;
    
}   t_philo;

//functions
int	ft_isdigit(int c);
int check_arg(int argc, char **args);
int	ft_atoi(const char *str);
int	is_error(void);
long get_time();
void    philo_data(t_info info, t_philo *threads, pthread_mutex_t *forks, pthread_mutex_t print);
void    ft_born_philo(t_info info, t_philo *threads);
void *philo_life(void *ptr);
void init_forks(t_info info, pthread_mutex_t *forks);
void    print(t_philo *philo, char *str);

#endif