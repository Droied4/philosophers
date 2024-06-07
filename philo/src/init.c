#include "philosophers.h"

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
		p[i].last_noodle = get_mstime();
    	if (pthread_create(&(p[i].thread_id), NULL, the_last_supper, &p[i]) != 0)
			return (destroy_all(table, philos + 2));
		usleep(100);
	}
	i = -1; 
	while (++i < philos)
	{
		if (pthread_join(p[i].thread_id, NULL) != 0)
			return (destroy_all(table, philos + 2));
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
		return (destroy_all(table, philos + 2));
	while(++i < philos)
	{
		table->p[i].id = i;
		if (i != 0)
			table->p[i].left_fork = table->p[i - 1].right_fork;
		table->p[i].right_fork = table->f + i;
		table->p[i].info = table->info;
		table->p[i].foods = 0;
		table->p[i].starvation = table->f + (philos + 1);
		table->p[i].printor = table->f + (philos + 2);
	}
	table->p[0].left_fork = table->f + (philos - 1);
	return (0);
}

static int init_mutex(t_table *table)
{
	int philos;
	int i;

	philos = (int)table->info.n_philo + 2;
	table->f = malloc(sizeof(t_fork ) * philos);
	if (!table->f)
		return (destroy_all(table, -1));
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
	//print_philo(table);
	if (init_spider(table) < 0)
		return (-1);
	return (0);
}
