/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:28:14 by deordone          #+#    #+#             */
/*   Updated: 2024/06/01 15:30:06 by droied           ###   ########.fr       */
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

/* PARSER */
int parser(int argc, char **argv, t_philo *p);

/* INIT */
void the_last_supper(t_philo *p);

/* AUX */
void print_philo(t_philo *p);

#endif
