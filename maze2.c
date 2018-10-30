/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 06:41:15 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/27 06:41:17 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			ft_minall(int a, int b, int c, int d)
{
	int		min;

	min = -500;
	if (a >= 0)
		min = a;
	if (b >= 0 && (b < min || min < 0))
		min = b;
	if (c >= 0 && (c < min || min < 0))
		min = c;
	if (d >= 0 && (d < min || min < 0))
		min = d;
	return (min);
}

int			ft_printmaze(t_maze **pz, int count)
{
	int		i;

	i = -1;
	ft_putnbr((*pz)->rows);
	ft_putchar('x');
	ft_putnbr((*pz)->cols);
	while (++i < 5)
		ft_putchar((*pz)->h[i]);
	ft_putchar('\n');
	i = -1;
	while (++i < (*pz)->rows)
		ft_putstr((*pz)->b[i]);
	ft_putstr("RESULT IN ");
	ft_putnbr(count - 1);
	count - 1 == 1 ? (ft_putstr(" STEP!\n")) : (ft_putstr(" STEPS!\n"));
	return (0);
}

int			ft_combinemaps(t_maze **pz, int **mz, int count, int min)
{
	int		ex[2];

	*ex = *ft_getexit(pz, mz, ex);
	count = mz[ex[0]][ex[1]];
	if (count <= 0)
		return (ft_showerror(NULL));
	while (mz[ex[0]][ex[1]] > 0)
	{
		(*pz)->b[ex[0]][ex[1]] = (*pz)->h[2];
		min = ft_mincoords(
			(ex[0] - 1 >= 0 ? mz[ex[0] - 1][ex[1]] : -1),
			(ex[1] - 1 >= 0 ? mz[ex[0]][ex[1] - 1] : -1),
			(ex[1] + 1 < (*pz)->cols ? mz[ex[0]][ex[1] + 1] : -1),
			(ex[0] + 1 < (*pz)->rows ? mz[ex[0] + 1][ex[1]] : -1));
		if (min == 1)
			ex[0] -= 1;
		else if (min == 2)
			ex[1] -= 1;
		else
			(min == 3 ? (ex[1] += 1) : (ex[0] += 1));
	}
	*ex = *ft_getexit(pz, mz, ex);
	(*pz)->b[ex[0]][ex[1]] = (*pz)->h[4];
	(*pz)->b[(*pz)->entr[0]][(*pz)->entr[1]] = (*pz)->h[3];
	return (ft_printmaze(pz, count));
}

int			ft_mincoords(int a, int b, int c, int d)
{
	int		lowest;

	lowest = -1;
	if (a >= 0)
		lowest = a;
	if (b >= 0 && (b < lowest || lowest < 0))
		lowest = b;
	if (c >= 0 && (c < lowest || lowest < 0))
		lowest = c;
	if (d >= 0 && (d < lowest || lowest < 0))
		lowest = d;
	if (lowest == a)
		return (1);
	else if (lowest == b)
		return (2);
	else if (lowest == c)
		return (3);
	else
		return (4);
}

int			*ft_getexit(t_maze **pz, int **mz, int *ex)
{
	int		i;

	ex[0] = (*pz)->exits[0][0];
	ex[1] = (*pz)->exits[0][1];
	i = 0;
	while (++i < (*pz)->excount)
	{
		if (mz[(*pz)->exits[i][0]][(*pz)->exits[i][1]] < mz[ex[0]][ex[1]])
		{
			ex[0] = (*pz)->exits[i][0];
			ex[1] = (*pz)->exits[i][1];
		}
		else if (mz[(*pz)->exits[i][0]][(*pz)->exits[i][1]] == mz[ex[0]][ex[1]])
		{
			if ((*pz)->exits[i][0] < ex[0] || ((*pz)->exits[i][0] == ex[0]
				&& (*pz)->exits[i][1] < ex[1]))
			{
				ex[0] = (*pz)->exits[i][0];
				ex[1] = (*pz)->exits[i][1];
			}
		}
	}
	return (ex);
}
