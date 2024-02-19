/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:29:22 by deordone          #+#    #+#             */
/*   Updated: 2024/02/17 13:31:04 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCT_H
#define PH_STRUCT_H

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

#endif
