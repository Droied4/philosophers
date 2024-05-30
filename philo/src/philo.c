	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:27:21 by deordone          #+#    #+#             */
/*   Updated: 2024/05/30 01:53:24 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_struct.h"
#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_philo p;

	if (argc == 6 || argc == 5)
	{
        if (parser(argc, argv, &p) < 0)
            printf("philo : invalid digit\n");
	   the_last_supper()	
	}
	else
		printf("philo : incorrect number of arguments\n");
	return (0);
}
