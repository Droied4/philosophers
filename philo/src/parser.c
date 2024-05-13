#include "philosophers.h"

static void     ft_constructor(int argc, char **argv, t_ph_info *data)
{
        data->n_philo = atol(argv[1]);
        data->time2_die = atol(argv[2]);
        data->time2_eat = atol(argv[3]);
        data->time2_sleep = atol(argv[4]);
        if (argc == 6)
            data->max_eat = atol(argv[5]);
        else
            data->max_eat = -1;
}

static int is_num(char *num)
{
    int i;

    i = 0;
    while(num[i])
    {
        if (num[i] > 47 && num[i] < 58)
            i++;
        else 
            return (-1);
    }
    return (0);
}

static int is_max(t_ph_info *data)
{
    if (!(data->n_philo <= INT_MAX && data->n_philo >= INT_MIN))
            return (-1);
    if (!(data->time2_die <= INT_MAX && data->time2_die >= INT_MIN))
            return (-1);
    if (!(data->time2_eat <= INT_MAX && data->time2_eat >= INT_MIN))
            return (-1);
    if (!(data->time2_sleep <= INT_MAX && data->time2_sleep >= INT_MIN))
            return (-1);
    if (data->max_eat != -1 && !(data->max_eat <= INT_MAX && data->max_eat >= INT_MIN))
            return (-1);
    return (0);
}

int parser(int argc, char **argv, t_ph_info *data)
{
    int i; 
    int aux;

    i = 1;
    aux = 0;
    while (aux >= 0 && argv[i])
        aux = is_num(argv[i++]);
    if (aux < 0)
        return (-1);
    ft_constructor(argc, argv, data);    
    aux = is_max(data);
    if (aux < 0)
        return (-1);
    return (0);
}
