/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:52:26 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/07 11:12:49 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dest;
	while (n > 0)
	{
		if (*s == c)
		{
			*d = *s;
			d++;
			s++;
			return (d);
		}
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (NULL);
}
