#include "philosophers.h"
/*
static void eating(void *p)
{
	
}
*/
static void *the_last_supper(void *arg)
{
	t_table *t;
	int philos;
	int i;

	t = (t_table *)arg;
	philos = (int)t->info.n_philo;
	i = -1;
	while (++i < philos)
	{
		pthread_mutex_lock(t->p[i].left_fork);
		printf("The philosopher -> %d \n with ID -> %ld take the %p fork\n", t->p[i].id, t->p[i].thread_id, t->p[i].left_fork);
		pthread_mutex_lock(t->p[i].right_fork);
		printf("The philosopher -> %d \n with ID -> %ld take the %p fork\n", t->p[i].id, t->p[i].thread_id, t->p[i].right_fork);
		//usleep(t->info.time2_eat);
		pthread_mutex_unlock(t->p[i].right_fork);
		pthread_mutex_unlock(t->p[i].left_fork);
	}
	return (NULL);
}

static int init_spider(t_table *table)
{
	t_philo *p;
	int philos;
	int i;

	philos = (int)table->info.n_philo;
	p = table->p;
	i = -1;
	while(++i < philos)
	{
    	if (pthread_create(&(p[i].thread_id), NULL, the_last_supper, table) != 0)
			return (destroy_all(table, philos));
		usleep(100);
	}
	i = -1;
	while (++i < philos)
	{
		if (pthread_join(p[i].thread_id, NULL) != 0)
			return (destroy_all(table, philos));
	}
	return (0);
}

static int init_philo(t_table *table)
{
	int philos;
	int i;

	philos = (int)table->info.n_philo;
	i = -1;
	table->p = malloc(sizeof(t_philo) * philos);
	if (!table->p)
		return (destroy_all(table, philos));
	while(++i < philos)
	{
		table->p[i].id = i;
		if (i != 0)
			table->p[i].left_fork = table->p[i - 1].right_fork;
		table->p[i].right_fork = table->f + i;
		table->p[i].state = THINKING;
	}
	table->p[0].left_fork = table->f + (philos - 1);
	return (0);
}

static int init_mutex(t_table *table)
{
	int philos;
	int i;

	table->f = malloc(sizeof(t_fork ) * table->info.n_philo);
	if (!table->f)
		return (destroy_all(table, -1));
	philos = (int)table->info.n_philo;
	i = -1;
	while (++i < philos)
	{
		if (pthread_mutex_init(&(table->f[i]), NULL) != 0)
			return (destroy_all(table, i));
	}
	return (0);
}

int	init(t_table *table)
{
	if (init_mutex(table) < 0)
		return (-1);
	if (init_philo(table) < 0)
		return (-1);
	print_forks(table);
	print_philo(table);
	if (init_spider(table) < 0)
		return (-1);
	return (0);
}
