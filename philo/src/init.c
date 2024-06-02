#include "philosophers.h"
/*
static void eating(void *p)
{
	
}
*/
static void *the_last_supper(void *arg)
{
	t_table *table;
	int philos;
	int i;

	table = (t_table *)arg;
	philos = (int)table->info.n_philo + 1;
	i = -1;
	while (++i < philos)
	{
	//	pthread_mutex_lock(&(p->mutex[i]));
		printf("ID -> %d \nThe philosopher -> %ld\n", table->p[i].id, table->p[i].thread_id);
	//	pthread_mutex_unlock(&(p->mutex[i]));
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
	}
	i = -1;
	while (++i < philos)
	{
		if (pthread_join(p[i].thread_id, NULL) != 0)
			return (destroy_all(table, philos));
		usleep(1);
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
//		table->p[i].left_fork = (i - 1 + philos) % philos;
//		table->p[i].right_fork = (i + 1) % philos;
		table->p[i].state = THINKING;
	}
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
	print_philo(table);
	if (init_spider(table) < 0)
		return (-1);
	return (0);
}
