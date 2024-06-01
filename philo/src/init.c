#include "philosophers.h"
/*
static void eating(void *p)
{
	
}
*/
static void *the_last_supper(void *arg)
{
	t_philo *p;
	int i;

	p = (t_philo *)arg;
	i = (int)p->info.n_philo + 1;
	while (--i)
	{
		if ((p->socrates[i].id % 2) == 0)
		{
			pthread_mutex_lock(&(p->mutex[i]));
			printf("ID -> %d \nThe philosopher -> %ld\n", p->socrates[i].id, p->socrates[i].thread_id);
			pthread_mutex_unlock(&(p->mutex[i]));
		}
		else 
		{
			pthread_mutex_lock(&(p->mutex[i]));
			usleep(100000);
			printf("ID -> %d \nThe philosopher -> %ld\n", p->socrates[i].id, p->socrates[i].thread_id);
			pthread_mutex_unlock(&(p->mutex[i]));
		}
	}
	exit (1);
	return (NULL);
}

static void init_spider(t_philo *p)
{
	int i;

	i = (int)p->info.n_philo + 1;
	while(--i)
    	pthread_create(&(p->socrates[i].thread_id), NULL, the_last_supper, p);
	i = (int)p->info.n_philo + 1;
	while (--i)
    	pthread_join(p->socrates[i].thread_id, NULL); 
}

static void init_philo(t_philo *p)
{
	int i;

	i = (int)p->info.n_philo + 1;
	while(--i)
	{
		p->socrates[i].id = i;
		p->socrates[i].left_spoon_id = (i - 1);
		p->socrates[i].right_spoon_id = i;
		p->socrates[i].last_meal = 0;
	}
	p->socrates[1].left_spoon_id = p->info.n_philo;	
}

static void init_mutex(t_philo *p)
{
	int i;

	i = (int)p->info.n_philo + 1;
	while (--i)
		pthread_mutex_init(&(p->mutex[i]), NULL);
}

void	init(t_philo *p)
{
	init_mutex(p);
	init_philo(p);
//	print_philo(p);	
	init_spider(p);
}
