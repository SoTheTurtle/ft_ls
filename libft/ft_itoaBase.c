/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaBase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:53:43 by sbanc             #+#    #+#             */
/*   Updated: 2017/03/19 14:44:22 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoaBase(intmax_t value, int base)
{
	uintmax_t nr;
	int i;
	char *str;
	char *bases = "0123456789ABCDEF";
	int sign = 0;

	if (value == 0)
		return "0";
	if (value < 0)
	{
		if (base == 10)
			sign = 1;
		nr = -value;
	}
	else nr = value;
	str = (char *)malloc(sizeof(char) * 100);
	str[99] = '\0';
	i = 98;
	while (nr)
	{
		str[i] = bases[nr % base];
		nr = nr/base;
		i--;
	}
	if (sign == 1)
	{
		str[i] = '-';
		i--;
	}
	return (str + i + 1);
}
