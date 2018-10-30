/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:27:26 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 14:27:28 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

extern t_queue	*g_tail;

int			ft_shortestpath(t_maze **pz)
{
	int		i;
	int		**emptymaze;
	t_queue	*queue;

	i = -1;
	emptymaze = NULL;
	queue = NULL;
	if (!((*pz)->exits = (int **)malloc(sizeof(int **) * (*pz)->excount)))
		return (0);
	while (++i < (*pz)->excount)
		if (!((*pz)->exits[i] = (int *)malloc(sizeof(int *) * 2)))
			return (0);
	emptymaze = ft_emptymaze(pz, emptymaze);
	g_tail = queue;
	ft_queue_push_back(&queue, (*pz)->entr[0], (*pz)->entr[1]);
	ft_mazesolver(pz, emptymaze, queue);
	ft_combinemaps(pz, emptymaze, 0, 0);
	ft_free(emptymaze, pz, NULL);
	return (0);
}

char		*ft_readsdin(void)
{
	int		ret;
	char	*str;
	int		i;
	char	temp[4096];

	if (!(str = (char *)malloc(sizeof(char) * 2000000001)))
		return (NULL);
	i = 0;
	while ((ret = read(0, temp, 1)))
		str[i++] = *temp;
	if (str[i - 1] != '\n')
	{
		free(str);
		return (0);
	}
	str[i] = '\0';
	return (str);
}

/*
** max labrynth size is a billion,allocating 2 bill, map could be 1b rows
** need to account for new line charachters
*/

char		*ft_readfile(char *file)
{
	int		ret;
	char	*str;
	int		fd;

	if (!(str = (char *)malloc(sizeof(char) * 2000000001)))
		return (NULL);
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, str, 2000000000)))
		str[ret] = '\0';
	return (str);
}

/*
** ./gen 5 10 "* o12"
** trce is total, row, col, entrance count to save lines in ft_verify function
*/

int			*ft_settrce(int *trce)
{
	trce[0] = 0;
	trce[1] = -1;
	trce[2] = 0;
	trce[3] = 0;
	return (trce);
}

int			main(int argc, char **argv)
{
	int		ifd[2];
	int		trce[4];
	t_maze	*pz;
	char	*str;

	ifd[0] = 0;
	*trce = *ft_settrce(trce);
	pz = ft_createmaze();
	str = NULL;
	if (argc > 1)
	{
		while (++ifd[0] < argc)
		{
			if (ifd[0] > 1)
				ft_putchar('\n');
			ifd[1] = open(argv[ifd[0]], O_RDONLY);
			*trce = *ft_settrce(trce);
			ifd[1] < 0 ? (write(2, "MAP ERROR\n", 10)) :
				(ft_verify(ft_readfile(argv[ifd[0]]), trce, &pz, str));
			close(ifd[1]);
		}
	}
	else
		ft_verify(ft_readsdin(), trce, &pz, str);
	return (0);
}
