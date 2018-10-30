/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 07:08:05 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/27 07:08:06 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			*ft_setdefaultvalue(int *arr, int num, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		arr[i] = num;
	return (arr);
}

int			**ft_emptymaze(t_maze **pz, int **dupmaze)
{
	int		ikj[3];

	*ikj = *ft_setdefaultvalue(ikj, -1, 3);
	if (!(dupmaze = (int **)malloc(sizeof(int *) * ((*pz)->rows + 1))))
		return (NULL);
	while (++ikj[0] < ((*pz)->rows))
		if (!(dupmaze[ikj[0]] = (int *)malloc(sizeof(int) * ((*pz)->cols + 2))))
			return (NULL);
	dupmaze[ikj[0]] = NULL;
	ikj[0] = -1;
	while (++ikj[0] < (*pz)->rows)
	{
		ikj[2] = -1;
		while (++ikj[2] < (*pz)->cols + 2)
		{
			dupmaze[ikj[0]][ikj[2]] = -1;
			if ((*pz)->b[ikj[0]][ikj[2]] == (*pz)->h[4])
			{
				(*pz)->exits[++ikj[1]][0] = ikj[0];
				(*pz)->exits[ikj[1]][1] = ikj[2];
			}
		}
	}
	dupmaze[(*pz)->entr[0]][(*pz)->entr[1]] = 0;
	return (dupmaze);
}

int			ft_free(int **emptymaze, t_maze **pz, char *str)
{
	int		i;

	i = -1;
	if (emptymaze)
		while (++i < (*pz)->rows)
			free(emptymaze[i]);
	i = -1;
	if ((*pz)->exits)
		while (++i < (*pz)->excount)
			free((*pz)->exits[i]);
	i = -1;
	while (++i < (*pz)->rows)
		free((*pz)->b[i]);
	if (emptymaze)
		free(emptymaze);
	if ((*pz)->excount)
		free((*pz)->exits);
	free((*pz)->b);
	if (str)
		ft_showerror(str);
	if (!emptymaze && !str)
		ft_showerror(NULL);
	return (0);
}
