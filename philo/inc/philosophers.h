/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:28:14 by deordone          #+#    #+#             */
/*   Updated: 2024/06/03 13:42:59 by droied           ###   ########.fr       */
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

/* MAIN */

int destroy_all(t_table *table, int i);

/* PARSER */
int parser(int ac, char **av, t_table *table);

/* INIT */
int init(t_table *p);

/* AUX */
void print_forks(t_table *p);
void print_philo(t_table *p);

#endif
