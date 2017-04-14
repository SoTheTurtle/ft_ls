/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:18:53 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/03 13:22:05 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *a;

	a = (const unsigned char *)s;
	while (n > 0)
	{
		if (*a == (unsigned char)c)
			return ((void *)a);
		a++;
		n--;
	}
	return (NULL);
}
