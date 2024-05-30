/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:59:20 by deordone          #+#    #+#             */
/*   Updated: 2024/05/30 12:30:56 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *take_a(void *n)
{
	int  num;

	num = *(int *)n;
	while (num < 10)
	{
		printf("Tomando Muestra de tipo A -> %d\n", num);
		usleep(200000);
		num++;
	}
	*(int *)n = num;
	return (NULL);
}

void *take_b(void *n)
{
	int  num;

	num = *(int *)n;
	while (num < 15)
	{
		printf("Tomando Muestra de tipo B -> %d\n", num);
		usleep(200000);
		num++;
	}
	*(int *)n = num;
	return (NULL);
}

int main (void)
{
	int A = 0;
	int B = 0;
	pthread_t hilo1, hilo2;

	pthread_create(&hilo1, 0, take_a, (void *)&A);
	pthread_create(&hilo2, 0, take_b, (void *)&B);
	pthread_join(hilo1, 0);
	pthread_join(hilo2, 0);
	printf("A -> %d && B -> %d\n", A, B);
	return (0);
}
