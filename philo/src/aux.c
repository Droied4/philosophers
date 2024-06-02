#include "philosophers.h"

void print_philo(t_philo *p)
{
	int i;

	i = p->info.n_philo + 1;
	while (--i)
	{
		printf("\nFilosofo 🗿 %d\n", p->socrates[i].id);
	//	printf("left 🥄-> %d 🍝", p->socrates[i].left_spoon_id);
		printf(" %d <- 🥄 right\n", p->socrates[i].right_spoon_id);
	}
}
