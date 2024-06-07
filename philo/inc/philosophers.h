/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:28:14 by deordone          #+#    #+#             */
/*   Updated: 2024/06/07 18:57:37 by droied           ###   ########.fr       */
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

/* INIT */
int init(t_table *p);

/* PARSER */
int parser(int ac, char **av, t_table *table);

/* DELFOS */

int memento_mori(t_philo *p);
void *the_last_supper(void *arg);

/* AUX */
int set_state(t_philo *p, char *state);
int	get_mstime(void);
void print_forks(t_table *t);
void print_philo(t_table *t);

#endif
