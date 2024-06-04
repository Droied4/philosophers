#include "philosophers.h"

static void zzz(t_philo *p)
{
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
	usleep(p->info.time2_sleep);
}

static void pair_philos(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	printf("The philosopher -> %d \n with ID -> %ld take the %p fork\n", p->id, p->thread_id, p->left_fork);
	pthread_mutex_lock(p->right_fork);
	printf("The philosopher -> %d \n with ID -> %ld take the %p fork\n", p->id, p->thread_id, p->right_fork);
}

static void odd_philos(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);   
	printf("The philosopher -> %d \n with ID -> %ld take the %p fork\n", p->id, p->thread_id, p->right_fork);
	pthread_mutex_lock(p->left_fork);
	printf("The philosopher -> %d \n with ID -> %ld take the %p fork\n", p->id, p->thread_id, p->left_fork);
}

void *the_last_supper(void *arg)
{
        t_philo *p;

        p = (t_philo *)arg;
        while (42)
        {
                if ((p->id % 2) == 0)
                	pair_philos(p);
                else 
                	odd_philos(p);
                usleep(p->info.time2_eat);
				zzz(p);
        }
        return (NULL);
}
