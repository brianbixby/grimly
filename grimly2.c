/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:12:24 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 15:12:26 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

/*
**  h[] = full, empty, path, enter, exit
*/

char		*ft_setheader(t_maze **pz, char *buf)
{
	int		i;
	int		j;
	char	*descr_row;

	i = -1;
	j = 1;
	if (!buf)
		return (0);
	while (buf[j] != '\n')
		j++;
	while (++i < 5)
		(*pz)->h[4 - i] = buf[j - i - 1];
	if (!(descr_row = (char *)malloc(sizeof(*descr_row) * (j + 1))))
		return (NULL);
	i = -1;
	while (++i <= j)
		descr_row[i] = *buf++;
	descr_row[j] = '\0';
	(*pz)->rows = ft_atoi(descr_row);
	(*pz)->cols = ft_setcols(descr_row, j);
	(*pz)->excount = 0;
	(*pz)->exits = NULL;
	free(descr_row);
	ft_mallocbody(pz);
	return (&*buf);
}

int			ft_setcols(char *topline, int len)
{
	topline[len - 5] = '\0';
	while (*topline && *topline != 'x')
		topline++;
	return (!*topline ? (ft_showerror(NULL)) : (ft_atoi(&topline[1])));
}

int			ft_showerror(char *str)
{
	if (str)
		free(str);
	write(2, "MAP ERROR\n", 10);
	return (0);
}
