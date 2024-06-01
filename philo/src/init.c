#include "philosophers.h"

static void init_spider(t_philo *p)
{

}

static void init_philo(t_philo *p)
{
	int i;

	i = (int)p->info.n_philo;
	while(i)
	{
		p->socrates[i].id = i;
		p->socrates[i].left_spoon_id = (i - 1);
		p->socrates[i].right_spoon_id = i;
		p->socrates[i].last_meal = 0;
		i--;
	}
	p->socrates[1].left_spoon_id = p->info.n_philo;	
}

void	the_last_supper(t_philo *p)
{
	init_philo(p);
	print_philo(p);	
	init_spider(p);
}
