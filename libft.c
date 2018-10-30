/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:17:31 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/27 16:17:33 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(1, s, i);
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else
		ft_putchar(n + 48);
}

int			ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + *str - 48;
		str++;
	}
	return (ret * sign);
}
