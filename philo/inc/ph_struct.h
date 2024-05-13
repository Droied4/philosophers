/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:29:22 by deordone          #+#    #+#             */
/*   Updated: 2024/05/13 16:23:25 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCT_H
#define PH_STRUCT_H

typedef struct s_ph_info
{
        long    n_philo;
        long   time2_die;
        long    time2_eat;
        long    time2_sleep;
        long    max_eat;
}       t_ph_info;

typedef struct s_philo
{
        int index;
        int state;
        int eat_times;
        struct s_philo *next;
        struct s_philo *prev;
}       t_philo;

#endif
