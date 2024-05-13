/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:27:21 by deordone          #+#    #+#             */
/*   Updated: 2024/05/13 18:46:44 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_struct.h"
#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ph_info	data;

	if (argc == 6 || argc == 5)
	{
        if (parser(argc, argv, &data) < 0)
            printf("philo : invalid digit\n");
        
	}
	else
		printf("philo : incorrect number of arguments\n");
	return (0);
}
