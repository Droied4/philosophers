/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:27:21 by deordone          #+#    #+#             */
/*   Updated: 2024/06/18 00:52:57 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static int one_philo(t_table *t)
{
	printf("0 The philosopher 🗿 [0] is %s\n", STR_THINK);
	ft_usleep(t->info.time2_die);
	printf("%li The philosopher 🗿 [0] is %s\n", t->info.time2_die, STR_DIE);
	return (0);
}

int destroy_all(t_table *table, int j)
{
	int i;

	i = -1;
	if (table->f)
	{
		while (++i < j)
			pthread_mutex_destroy(&table->f[i]);
		free(table->f);
		table->f = NULL;
	}
	if (table->p)
		free(table->p);
	return (-1);
}

int	main(int ac, char **av)
{
	t_table table;

	if (ac == 6 || ac == 5)
	{
        if (parser(ac, av, &table) < 0)
		{
            printf("philo : invalid digit\n");
			return (1);
		}
		if (table.info.n_philo == 1)
			return (one_philo(&table));
		init(&table); 
	}
	else
	{
		printf("philo : incorrect number of arguments\n");
		return (1);
	}
	return (0);
}
