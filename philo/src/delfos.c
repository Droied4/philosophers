#include "philosophers.h"

static int memento_mori(t_philo *p)
{
	int flag;

	flag = 0;
	if (*p->info.death != 0)
		flag = -1;
	else if ((get_mstime() - p->last_noodle) > p->info.time2_die)
	{
		printf("\033[31m%i The philosopher 🗿 %d\n DIE 💀\n\033[0m", get_mstime() - p->last_noodle, p->id);
		*p->info.death = 1;
		flag = -1;
	}
	pthread_mutex_unlock(p->starvation);
	return (flag);
}

static void eating(t_philo *p)
{
	p->last_noodle = get_mstime();
	p->foods++;
	set_state(p, EATING);
    usleep(p->info.time2_eat);
}

static void zzz(t_philo *p)
{
	set_state(p, SLEEPING);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	usleep(p->info.time2_sleep);
}

static void take_forks(t_philo *p, int i)
{
	if (i == 2)
	{
		pthread_mutex_lock(p->left_fork);
		printf("%i The philosopher 🗿 %d\n take the left fork 🍴\n", get_mstime() - p->last_noodle, p->id);
		pthread_mutex_lock(p->right_fork);
		printf("%i The philosopher 🗿 %d\n take the right fork 🍴\n", get_mstime() - p->last_noodle, p->id);
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		printf("%i The philosopher 🗿 %d\n take the right fork 🍴\n", get_mstime() - p->last_noodle, p->id);
		pthread_mutex_lock(p->left_fork);
		printf("%i The philosopher 🗿 %d\n take the left fork 🍴\n", get_mstime() - p->last_noodle, p->id);
	}
}

void *the_last_supper(void *arg) 
{
        t_philo *p;

        p = (t_philo *)arg;
		if (p->id %2 != 0)
			usleep(1500);
        while (42)
        {
				pthread_mutex_lock(p->starvation);
				if (memento_mori(p) < 0)
					break ;
				set_state(p, THINKING);
                if ((p->id % 2) == 0)
                	take_forks(p, 2);
                else 
                	take_forks(p, 1);
				eating(p);
				zzz(p);
        }
        return (NULL);
}
