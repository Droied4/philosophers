/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:27:21 by deordone          #+#    #+#             */
/*   Updated: 2024/05/13 16:27:01 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_struct.h"
#include "philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ph_info	data;
	t_philo		**philo;

	if (argc == 6 || argc == 5)
	{
        if (parser(argc, argv, &data) < 0)
            printf("philo : invalid digit");
	}
	else
		printf("philo : incorrect number of arguments");
	(void)philo;
	//      printf("[%i][%i][%i]", philo->prev->index, philo->index,
	//	philo->next->index;
	//      printf("o <- o -> o");
	return (0);
}
