#include "philosophers.h"

int memento_mori(t_philo *p)
{
	int flag;

	flag = 0;
	pthread_mutex_lock(p->starvation);
	if (*p->info.death != 0)
		flag = -1;
	else if ((get_mstime() - p->last_noodle) > p->info.time2_die)
	{
		printf("%i The philosopher 🗿 %d is %s\n", get_mstime() - p->last_noodle, p->id, STR_DIE);
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
	set_state(p, STR_EAT);
    usleep(p->info.time2_eat);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	set_state(p, STR_FORK2);
}

static void zzz(t_philo *p 	)
{
	set_state(p, STR_SLEEP);
	usleep(p->info.time2_sleep);
}

static void take_forks(t_philo *p, int i)
{
	if (i == 2)
	{
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->right_fork);
		set_state(p, STR_FORK);
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->left_fork);
		set_state(p, STR_FORK);
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
				if (memento_mori(p) < 0)
					break ;
				set_state(p, STR_THINK);
                if ((p->id % 2) == 0)
                	take_forks(p, 2);
                else 
                	take_forks(p, 1);
				eating(p);
				zzz(p);
        }
        return (NULL);
}
