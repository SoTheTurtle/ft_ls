/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:06:57 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/06 15:07:00 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len1;
	size_t len2;

	j = 0;
	len1 = ft_strlen(src);
	i = ft_strlen(dst);
	len2 = i;
	if (size < i)
		return (len1 + size);
	if (size == len2)
		return (len1 + len2);
	while (src[j] && j < size - len2 - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (len1 + len2);
}
