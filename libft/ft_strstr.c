/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:50:25 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/03 13:34:18 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int j;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		j = 0;
		while ((needle[j]) && (needle[j] == haystack[j]))
			j++;
		if (!needle[j])
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
