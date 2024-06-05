#include "philosophers.h"
	
int	get_mstime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int set_state(t_philo *p, int state)
{
	int time;
	time = get_mstime();
	if (state == EATING)
	{
		p->state = EATING;
		printf("%i The philosopher 🗿 %d\n is \033[34mEating\033[0m 🍝\n", time - p->last_noodle, p->id);
	}
	else if (state == THINKING)
	{
		p->state = THINKING;
		printf("%i The philosopher 🗿 %d\n is \033[33mThinking\033[0m 🤔\n", time - p->last_noodle, p->id);
	}
	else if (state == SLEEPING)
	{
		p->state = SLEEPING;
		printf("%i The philosopher 🗿 %d\n is \033[31mSleeping\033[0m 😴\n", time - p->last_noodle, p->id);
	}
	return (time);
}

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

