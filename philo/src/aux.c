#include "philosophers.h"
time_t    get_mstime(t_fork *time)
{
    static time_t    start_time = 0;
    struct timeval    t;
	
	pthread_mutex_lock(time);
    if (start_time == 0)
    {
        gettimeofday(&t, NULL);
        start_time = get_time_value();
    }
    gettimeofday(&t, NULL);
    pthread_mutex_unlock(time);
    return (get_time_value() - start_time);
}

void set_state(t_philo *p, char *state)
{
	pthread_mutex_lock(p->printor);
	if (memento_mori(p) >= 0)
		printf("%li The philosopher 🗿 %d is %s\n", get_mstime(p->time), p->id, state);
	pthread_mutex_unlock(p->printor);
}

long    get_time_value(void)
{
    struct timeval  timestamp;

    gettimeofday(&timestamp, NULL);
    return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}

void    ft_usleep(int ms)
{
    long int    time;

    time = get_time_value();
    while (get_time_value() - time < ms)
        usleep(100);
}
