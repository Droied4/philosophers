#include "philosophers.h"
	
int	get_mstime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int set_state(t_philo *p, char *state)
{
	int time;
	time = get_mstime();
	
	pthread_mutex_lock(p->printor);
	printf("%i The philosopher 🗿 %d is %s\n", time - p->last_noodle, p->id, state);
	pthread_mutex_unlock(p->printor);
	return (time);
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

