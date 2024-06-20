/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:05:49 by deordone          #+#    #+#             */
/*   Updated: 2024/06/20 14:00:01 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static int	one_philo(t_table *t)
{
	printf("0 The philosopher 🗿 [0] is %s\n", STR_THINK);
	ft_usleep(t->info.time2_die);
	printf("%li The philosopher 🗿 [0] is %s\n", t->info.time2_die, STR_DIE);
	return (0);
}

int	destroy_all(t_table *table, int j)
{
	int	i;

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
	t_table	table;

	if (ac == 6 || ac == 5)
	{
		if (parser(ac, av, &table) < 0)
		{
			printf("philo : invalid digit\n");
			return (1);
		}
		if (table.info.n_philo == 1)
			return (one_philo(&table));
		if (init_mutex(&table) < 0)
			return (-1);
		if (init_philo(&table) < 0)
			return (-1);
		if (init_spider(&table) < 0)
			return (-1);
	}
	else
	{
		printf("philo : incorrect number of arguments\n");
		return (1);
	}
	return (0);
}
