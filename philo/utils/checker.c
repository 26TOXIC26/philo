/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:07:31 by pc                #+#    #+#             */
/*   Updated: 2024/05/09 10:17:32 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_check_num(char **argv)
{
    int i;

    i = 1;
    while (i < 5)
    {
        if (ft_atoi(argv[i]) == -1 || ft_atoi(argv[i]) == 0)
            return (-1);
        i++;
    }
    if (argv[5] && ft_atoi(argv[5]) == -1)
        return (-1);
    return (0);
}

int check_arg(int argc, char **args)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (j < argc)
    {
        while (args[j][i])
        {
            if (ft_isdigit(args[j][i]) == 0)
                return (0);
            i++;
        }
        i = 0;
        j++;
    }
    if (ft_check_num(args) == -1)
        return (0);
    return (1);
}