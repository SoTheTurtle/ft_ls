/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaBase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:53:43 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 11:54:34 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(intmax_t value, int base)
{
	uintmax_t	nr;
	int			i;
	char		*str;
	char		*bases;
	int			sign;

	bases = ft_strdup("0123456789ABCDEF");
	if (value == 0)
		return ("0");
	sign = ((base == 10) && (value < 0) ? 1 : 0);
	if (value < 0)
		nr = -value;
	else
		nr = value;
	str = (char *)malloc(sizeof(char) * 100);
	str[99] = '\0';
	i = 98;
	while (nr)
	{
		str[i--] = bases[nr % base];
		nr = nr / base;
	}
	if (sign == 1)
		str[i--] = '-';
	return (str + i + 1);
}
