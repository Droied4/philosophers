/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:29:22 by deordone          #+#    #+#             */
/*   Updated: 2024/06/04 04:12:22 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCT_H
# define PH_STRUCT_H
# include "philosophers.h"

typedef struct s_info
{
        long	n_philo;
        long	time2_die;
        long	time2_eat;
        long	time2_sleep;
        long	max_eat;
}       t_info;

typedef pthread_mutex_t t_fork;

typedef struct s_philo
{
	int 			id;	
	int				state;
	int				foods;
	int				last_noodle;
	pthread_t		thread_id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_info			info;
} 	t_philo;

typedef struct s_table
{
	t_fork 			*f;
	t_philo	*p;
	t_info	info;
}       t_table;

#endif
