#include "philosophers.h"

void print_philo(t_philo *p)
{
	int i;

	i = p->info.n_philo;
	while (i)
	{
		printf("\nId -> %d\n", p->socrates[i].id);
		printf("left 🥄-> %d\n", p->socrates[i].left_spoon_id);
		printf("right 🥄-> %d\n", p->socrates[i].right_spoon_id);
		i--;
	}
}
