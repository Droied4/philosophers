#include "philosophers.h"


void print_forks(t_table *table)
{

	int philos;
	int i;

	philos = table->info.n_philo;
	i = -1;
	while (++i < philos)
	{
		printf("forks 🥄-> %p \n\n", &table->f[i]);
	}
}

void print_philo(t_table *table)
{
	int philos;
	int i;

	philos = table->info.n_philo;
	i = -1;
	while (++i < philos)
	{
		printf("Filosofo 🗿 %d\n", table->p[i].id);
		printf("left 🥄-> %p 🍝", table->p[i].left_fork);
		printf(" %p <- 🥄 right\n\n", table->p[i].right_fork);
	}
}

