/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:27:21 by deordone          #+#    #+#             */
/*   Updated: 2024/06/03 00:55:17 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

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
		init(&table); 
	}
	else
	{
		printf("philo : incorrect number of arguments\n");
		return (1);
	}
	return (0);
}
