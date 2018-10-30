/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:44:30 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/28 18:44:33 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

extern t_queue	*g_tail;

t_queue			*ft_create_elem(int x, int y)
{
	t_queue		*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_queue));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->next = NULL;
	}
	return (tmp);
}

void			ft_queue_push_back(t_queue **begin_queue, int x, int y)
{
	t_queue		*queue;

	queue = *begin_queue;
	if (queue)
	{
		g_tail->next = ft_create_elem(x, y);
		g_tail = g_tail->next;
	}
	else
	{
		*begin_queue = ft_create_elem(x, y);
		g_tail = *begin_queue;
	}
}
