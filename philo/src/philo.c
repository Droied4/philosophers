/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:27:21 by deordone          #+#    #+#             */
/*   Updated: 2024/02/17 13:36:34 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_constructor(int argc, char **argv, t_ph_info *data)
{
	// aqui hago un atoi de argv a partir de la posicion 1
	// si argc == 5 la simulacion se detendra con la muerte de un filosofo
	// si argc == 6 la simulacion se detendra con la muerte o cuando haya comido n cantidad
	// de veces cada filosofo.
	data->n_philo = atoi(argv[1]);
	data->time2_die = atoi(argv[2]);
	data->time2_eat = atoi(argv[3]);
	data->time2_sleep = atoi(argv[4]);
	if (argc == 6)
		data->max_eat = atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_ph_info	data;
	t_philo		**philo;

	if (argc == 6 || argc == 5)
	{
		//              primero debo comprobar si todo lo que me han pasado son numeros
		//              una vez comprobado debo hacer un atoi y comprobar el maximo y minimo y tambien
		//              guardar todo en la estructura data
		ft_constructor(argc, argv, &data);
		philo = ft_phlst(&data);
	}
	else
	{
		printf("philo : incorrect number of arguments");
		// ft_dprintf(2, "philo : incorrect number of arguments");
	}
	(void)philo;
	//      printf("[%i][%i][%i]", philo->prev->index, philo->index,
	//	philo->next->index;
	//      printf("o <- o -> o");
	return (0);
}
