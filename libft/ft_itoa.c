/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:35:36 by sbanc             #+#    #+#             */
/*   Updated: 2017/03/12 15:53:24 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		how_long_n(int n)
{
	int i;
	int x;

	x = n;
	i = 1;
	if (x < 0)
	{
		i++;
		x = -x;
	}
	while (x != 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

static char		*reverse_int_char(int n)
{
	char	*x;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (n < 0)
	{
		n = -n;
		c = 1;
	}
	if (!(x = (char *)malloc(how_long_n(n) + 1)))
		return (NULL);
	while (n != 0)
	{
		x[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	x[i] = '\0';
	if (c == 1)
		x[i + 1] = '\0';
	return (x);
}

static char		*reverse_that_char(char *c)
{
	size_t	i;
	char	x;

	i = 0;
	while (i < (ft_strlen(c) / 2))
	{
		x = c[i];
		c[i] = c[ft_strlen(c) - i - 1];
		c[ft_strlen(c) - i - 1] = x;
		i++;
	}
	return (c);
}

static char		*get_neg(char *c)
{
	int i;

	i = ft_strlen(c);
	while (i >= 0)
	{
		c[i + 1] = c[i];
		i--;
	}
	c[0] = '-';
	return (c);
}

char			*ft_itoa(int n)
{
	char	*c;
	int		x;

	x = 0;
	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	if (!(c = (char*)malloc(how_long_n(n) + 1)))
		return (NULL);
	if (n == -0)
		return ("0\0");
	if (n < 0)
	{
		x = 1;
		n = -n;
	}
	ft_strcpy(c, reverse_int_char(n));
	c = reverse_that_char(c);
	if (x == 1)
		get_neg(c);
	return (c);
}
