/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:28:14 by deordone          #+#    #+#             */
/*   Updated: 2024/05/13 16:14:26 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include "ph_macros.h"
# include "ph_struct.h"

/*
 * ph_lst
 * */
//void ft_phlst_add_back(t_philo **lst, t_philo *node);
int *ft_phlst_size(t_philo **lst);
t_philo *ft_newph(int index);
t_philo *ft_ph_lastnode(int index);
t_philo **ft_phlst(t_ph_info *data);
int parser(int argc, char **argv, t_ph_info *data);

#endif
