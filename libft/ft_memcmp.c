/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:26:05 by sbanc             #+#    #+#             */
/*   Updated: 2016/12/23 12:05:44 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ss1;
	const unsigned char *ss2;
	size_t				i;
	int					c;

	ss1 = s1;
	ss2 = s2;
	i = 0;
	c = 0;
	while ((i < n) && (c == 0))
	{
		c = ss1[i] - ss2[i];
		i++;
	}
	return (c);
}
