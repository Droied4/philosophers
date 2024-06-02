/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:59:20 by deordone          #+#    #+#             */
/*   Updated: 2024/06/02 01:29:03 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
/*
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
}*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    *spiderman(void *arg)
{
        sleep(1);
        printf("Un gran poder conlleva una gran responsabilidad\n");
        return (NULL);
}

int     main(void)
{
        pthread_t       my_thr;
        pthread_t       my_thr2;

        printf("1. my thread -> %ld\n", my_thr); // -> 4096 -> 4MB
        printf("1. my thread 2 -> %ld\n", my_thr2); // -> 4096 -> 4MB
        pthread_create(&my_thr, NULL, spiderman, NULL);
        printf("2. my thread -> %ld\n", my_thr);
        printf("2. my thread 2 -> %ld\n", my_thr2);
}
