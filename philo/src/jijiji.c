#include <sys/time.h>
#include <stdio.h>

int	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main(void)
{
	int time;
	while (42)
	{
		time = get_current_time_ms();
		printf("the time is -> %i\n", time);
	}
	return (0);
}
