/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:28:14 by deordone          #+#    #+#             */
/*   Updated: 2024/02/14 17:26:18 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# define EATING = 3
# define SLEEPING = 2
# define THINKING = 1 

typedef struct s_ph_info
{
        unsigned int    n_philo;
        unsigned int    time2_die;
        unsigned int    time2_eat;
        unsigned int    time2_sleep;
        unsigned int    max_eat;
}       t_ph_info;

typedef struct s_philo
{
        int index;
        int state;
        int eat_times;
        struct s_philo *next;
        struct s_philo *prev;
}       t_philo;

/*
 * ph_lst
 * */
//void ft_phlst_add_back(t_philo **lst, t_philo *node);
int *ft_phlst_size(t_philo **lst);
t_philo *ft_newph(int index);
t_philo *ft_ph_lastnode(int index);
t_philo **ft_phlst(t_ph_info *data);

#endif
