#include "philosophers.h"

void print_philo(t_table *table)
{
	int i;

	i = table->info.n_philo + 1;
	while (--i)
	{
		printf("\nFilosofo 🗿 %d\n", table->p[i].id);
		printf("left 🥄-> %p 🍝", table->p[i].left_fork);
		printf(" %p <- 🥄 right\n", table->p[i].right_fork);
	}
}

