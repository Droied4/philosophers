/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:29:22 by deordone          #+#    #+#             */
/*   Updated: 2024/06/01 16:36:52 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCT_H
# define PH_STRUCT_H
# include "philosophers.h"

typedef struct s_ph_info
{
        long	n_philo;
        long	time2_die;
        long	time2_eat;
        long	time2_sleep;
        long	max_eat;
}       t_ph_info;

typedef struct s_socrates
{
	int 		id;
	int			state;
	int 		left_spoon_id;
	int 		right_spoon_id;
	int 		last_meal;
	pthread_t	thread_id;
} 	t_socrates;

typedef struct s_philo
{
	struct s_socrates socrates[250];
	pthread_mutex_t mutex[250];
	struct s_ph_info info;
}       t_philo;

#endif
