/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:26:01 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 14:26:04 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_maze
{
	int				rows;
	int				cols;
	char			h[5];
	char			**b;
	int				entr[2];
	int				**exits;
	int				excount;
}					t_maze;

typedef struct		s_queue
{
	struct s_queue	*next;
	int				x;
	int				y;
}					t_queue;

char				*ft_readsdin(void);
char				*ft_readfile(char *file);
int					*ft_settrce(int *trce);
int					ft_shortestpath(t_maze **pz);

char				*ft_setheader(t_maze **pz, char *buf);
int					ft_showerror(char *str);
int					ft_setcols(char *topline, int len);

int					ft_verify(char *str, int *t, t_maze **m, char *s);
t_maze				*ft_createmaze(void);
void				ft_mallocbody(t_maze **pz);
int					ft_setentr(t_maze **pz, int x, int y);

void				ft_mazesolver(t_maze **pz, int **dupmaze, t_queue *q);
void				ft_solvemaze1(t_maze **pz, int **dupmaze, int x, int y);
void				ft_solvemaze2(t_maze **pz, int **dupmaze, int x, int y);
void				ft_solvemaze3(t_maze **pz, int **dupmaze, int x, int y);
void				ft_solvemaze4(t_maze **pz, int **dupmaze, int x, int y);

int					ft_minall(int a, int b, int c, int d);
int					ft_printmaze(t_maze **pz, int count);
int					ft_combinemaps(t_maze **pz, int **mz, int count, int min);
int					ft_mincoords(int a, int b, int c, int d);
int					*ft_getexit(t_maze **pz, int **mz, int *ex);

int					*ft_setdefaultvalue(int	*arr, int num, int size);
int					**ft_emptymaze(t_maze **pz, int **dupmaze);
int					ft_free(int **emptymaze, t_maze **pz, char *str);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
int					ft_atoi(const char *str);

t_queue				*ft_create_elem(int x, int y);
void				ft_queue_push_back(t_queue **begin_queue, int x, int y);
#endif
