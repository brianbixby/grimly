/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 02:46:00 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/23 02:46:01 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_queue		*g_tail;

/*
**  int g_reps = 0;
** 	g_reps++;
**	printf("%d\n", g_reps);
**  h[] = full, empty, path, enter, exit
*/

void		ft_mazesolver(t_maze **pz, int **dupmaze, t_queue *q)
{
	t_queue	*temp;

	temp = NULL;
	if (q)
	{
		while (q)
		{
			if ((q->x - 1 >= 0 && (*pz)->b[q->x - 1][q->y] != (*pz)->h[0]))
				ft_solvemaze1(pz, dupmaze, q->x, q->y);
			if ((q->y - 1 >= 0 && (*pz)->b[q->x][q->y - 1] != (*pz)->h[0]))
				ft_solvemaze2(pz, dupmaze, q->x, q->y);
			if ((q->y + 1 < (*pz)->cols && (*pz)->b[q->x][q->y + 1]
				!= (*pz)->h[0]))
				ft_solvemaze3(pz, dupmaze, q->x, q->y);
			if ((q->x + 1 < (*pz)->rows && (*pz)->b[q->x + 1][q->y]
				!= (*pz)->h[0]))
				ft_solvemaze4(pz, dupmaze, q->x, q->y);
			temp = q;
			q = q->next;
			free(temp);
		}
	}
}

void		ft_solvemaze1(t_maze **pz, int **dupmaze, int x, int y)
{
	int		flag;
	int		temp;

	flag = 0;
	temp = 0;
	if ((x - 1 >= 0 && (*pz)->b[x - 1][y] != (*pz)->h[0]))
	{
		temp = ft_minall(dupmaze[x][y], (x - 1 >= 0 && y + 1 < (*pz)->cols ?
		(dupmaze[x - 1][y + 1]) : (-1)), (x - 2 >= 0 ? (dupmaze[x - 2][y]) :
		(-1)), (x - 1 >= 0 && y - 1 >= 0 ? (dupmaze[x - 1][y - 1]) : (-1))) + 1;
		if (temp > 0 && ((temp < dupmaze[x - 1][y]) || dupmaze[x - 1][y] < 0))
		{
			dupmaze[x - 1][y] = temp;
			flag = 1;
		}
	}
	if (flag && dupmaze[x - 1][y] >= 0)
	{
		g_tail->next = ft_create_elem(x - 1, y);
		g_tail = g_tail->next;
	}
}

void		ft_solvemaze2(t_maze **pz, int **dupmaze, int x, int y)
{
	int		flag;
	int		temp;

	flag = 0;
	temp = 0;
	if ((y - 1 >= 0 && (*pz)->b[x][y - 1] != (*pz)->h[0]))
	{
		temp = ft_minall(dupmaze[x][y], (x + 1 < (*pz)->rows && y - 1 >= 0 ?
		(dupmaze[x + 1][y - 1]) : (-1)), (y - 2 >= 0 ? (dupmaze[x][y - 2]) :
		(-1)), (x - 1 >= 0 && y - 1 >= 0 ? (dupmaze[x - 1][y - 1]) : (-1))) + 1;
		if (temp > 0 && ((temp < dupmaze[x][y - 1]) || dupmaze[x][y - 1] < 0))
		{
			flag = 1;
			dupmaze[x][y - 1] = temp;
		}
	}
	if (flag && dupmaze[x][y - 1] >= 0)
	{
		g_tail->next = ft_create_elem(x, y - 1);
		g_tail = g_tail->next;
	}
}

void		ft_solvemaze3(t_maze **pz, int **dupmaze, int x, int y)
{
	int		flag;
	int		temp;

	flag = 0;
	temp = 0;
	if (x < 0 || y < 0 || y >= (*pz)->cols || x >= (*pz)->rows)
		return ;
	if ((y + 1 < (*pz)->cols && (*pz)->b[x][y + 1] != (*pz)->h[0]))
	{
		temp = ft_minall(dupmaze[x][y], (x - 1 >= 0 && y + 1 < (*pz)->cols ?
		(dupmaze[x - 1][y + 1]) : (-1)), (x + 1 < (*pz)->rows && y + 1 <
		(*pz)->cols ? (dupmaze[x + 1][y + 1]) : (-1)), (y + 2 < (*pz)->cols
		? (dupmaze[x][y + 2]) : (-1))) + 1;
		if (temp > 0 && ((temp < dupmaze[x][y + 1]) || dupmaze[x][y + 1] < 0))
		{
			dupmaze[x][y + 1] = temp;
			flag = 1;
		}
	}
	if (flag && dupmaze[x][y + 1] >= 0)
	{
		g_tail->next = ft_create_elem(x, y + 1);
		g_tail = g_tail->next;
	}
}

void		ft_solvemaze4(t_maze **pz, int **dupmaze, int x, int y)
{
	int		flag;
	int		temp;

	flag = 0;
	temp = 0;
	if (x < 0 || y < 0 || y >= (*pz)->cols || x >= (*pz)->rows)
		return ;
	if ((x + 1 < (*pz)->rows && (*pz)->b[x + 1][y] != (*pz)->h[0]))
	{
		temp = ft_minall(dupmaze[x][y], (x + 1 < (*pz)->rows && y - 1 >= 0 ?
		(dupmaze[x + 1][y - 1]) : (-1)), (x + 2 < (*pz)->rows ?
		(dupmaze[x + 2][y]) : (-1)), (x + 1 < (*pz)->rows && y + 1 <
		(*pz)->cols ? (dupmaze[x + 1][y + 1]) : (-1))) + 1;
		if (temp > 0 && ((temp < dupmaze[x + 1][y]) || dupmaze[x + 1][y] < 0))
		{
			dupmaze[x + 1][y] = temp;
			flag = 1;
		}
	}
	if (flag && dupmaze[x + 1][y] >= 0)
	{
		g_tail->next = ft_create_elem(x + 1, y);
		g_tail = g_tail->next;
	}
}
