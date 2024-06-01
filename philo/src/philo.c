/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:27:21 by deordone          #+#    #+#             */
/*   Updated: 2024/06/01 15:15:31 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_philo p;

	if (argc == 6 || argc == 5)
	{
        if (parser(argc, argv, &p) < 0)
		{
            printf("philo : invalid digit\n");
			return (-1);
		}
		the_last_supper(&p); 
	}
	else
		printf("philo : incorrect number of arguments\n");
	return (0);
}
