#include "philosophers.h"

int memento_mori(t_philo *p)
{
	int flag;

	flag = 0;
	pthread_mutex_lock(p->starvation);
	usleep(1000);
	if (*p->info.death != 0)
		flag = -1;
	else if ((get_mstime(p->time)) > p->info.time2_die)
	{
		printf("%li The philosopher 🗿 [%d] is %s\n", get_mstime(p->time), p->id, STR_DIE);
		*p->info.death = 1;
		flag = -1;
	}
	pthread_mutex_unlock(p->starvation);
	return (flag);
}

static int eating(t_philo *p)
{
	p->foods++;
	p->last_noodle = get_mstime(p->time);
	set_state(p, STR_EAT);
    ft_usleep(p->info.time2_eat);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	set_state(p, STR_FORK2);
	return (0);
}

static void zzz(t_philo *p)
{
	set_state(p, STR_SLEEP);
	ft_usleep(p->info.time2_sleep);
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
		p->last_noodle = get_mstime(p->time);
		if (p->id % 2 != 0)
			usleep(1000);
        while (42)
        {
				if (memento_mori(p) < 0)
					break ;
				set_state(p, STR_THINK);
                if ((p->id % 2) == 0)
                	take_forks(p, 2);
                else 
                	take_forks(p, 1);
				if (eating(p) < 0 || (p->info.max_eat != -1 && p->foods >= p->info.max_eat))
					break ;
				zzz(p);
        }
        return (NULL);
}
