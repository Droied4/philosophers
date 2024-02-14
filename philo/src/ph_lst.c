/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:00:40 by carmeno           #+#    #+#             */
/*   Updated: 2024/02/14 18:00:56 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	**ft_phlst(t_ph_info *data)
{
	int		i;
	t_philo	*node;
	t_philo	**lst;
	t_philo	*lstnode;

	index = 0;
	i = -1;
	while (++i < data->n_philo)
	{
		// me crea un nodo
		node = ft_newph(++index);
		if (!node)
			// limpiar la lista y poner error;
			ft_phlst_add_back(lst, node);
	}
	lstnode = ft_ph_lastnode(lst);
	lstnode->next = *lst;
	*lst->prev = lstnode;
	return (lst);
}

/*funcion addback que tambien agregue el next y el previus
void	ft_phlst_add_back(t_philo **lst, t_philo *node);
*/
t_philo	*ft_ph_lastnode(t_philo **lst)
{
	t_philo	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	ft_phlst_size(t_philo **lst)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_philo	*ft_newph(int index)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->index = index;
	node->state = 0;
	node->eat_times = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
