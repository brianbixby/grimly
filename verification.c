/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:58:46 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 14:58:48 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#define NOTEQUAL(arg, val1, val2) (arg != val1 && arg != val2)

void		ft_mallocbody(t_maze **pz)
{
	int		i;

	i = -1;
	if (!((*pz)->b = (char **)malloc(sizeof(char *) * ((*pz)->rows + 1))))
		return ;
	while (++i < ((*pz)->rows))
		if (!((*pz)->b[i] = (char *)malloc(sizeof(char)
			* ((*pz)->cols + 2))))
			return ;
	(*pz)->b[i] = NULL;
}

t_maze		*ft_createmaze(void)
{
	t_maze	*pz;

	if (!(pz = (t_maze *)malloc(sizeof(*pz))))
		return (NULL);
	return (pz);
}

int			ft_setentr(t_maze **pz, int x, int y)
{
	(*pz)->entr[0] = x;
	(*pz)->entr[1] = y;
	return (1);
}

/*
** only chars in first line, '\n' &end of each line, row * col <= bil
** exits >= 1, entrances = 1, rows and cols adhere to first line.
** *t is total, row and col, entrance count
*/

int			ft_verify(char *str, int *t, t_maze **m, char *s)
{
	s = ft_setheader(m, str);
	if (!str || (*m)->rows * (*m)->cols > 1000000000)
		return (ft_showerror(NULL));
	while (s[++t[1]])
	{
		(*m)->b[t[2]][t[0]] = (s[t[1]] == (*m)->h[2] ? (*m)->h[1] : s[t[1]]);
		if ((*m)->b[t[2]][t[0]] == (*m)->h[3])
			t[3] += ft_setentr(&(*m), (int)t[2], (int)t[0]);
		else if ((*m)->b[t[2]][t[0]] == (*m)->h[4])
			(*m)->excount++;
		else if (s[t[1]] == '\n')
		{
			if (t[0] != ((*m))->cols || t[3] > 1)
				return (ft_free(NULL, m, str));
			(*m)->b[t[2]][t[0] + 1] = '\0';
			t[0] = -1;
			t[2]++;
		}
		else if (NOTEQUAL((*m)->b[t[2]][*t], (*m)->h[0], (*m)->h[1]))
			return (ft_free(NULL, m, str));
		t[0]++;
	}
	free(str);
	return ((t[2] != (*m)->rows || !(*m)->excount || t[3] != 1)
		? (ft_free(NULL, m, NULL)) : (ft_shortestpath(m)));
}
