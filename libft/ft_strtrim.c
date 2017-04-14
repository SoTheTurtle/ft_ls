/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:49:08 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/07 13:16:34 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*c;
	int		i;
	int		j;
	int		k;

	i = 0;
	if (s == NULL)
		return (NULL);
	k = 0;
	j = ft_strlen(s) - 1;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (s[i]))
		i++;
	if ((i == (int)ft_strlen(s)) || (j == -1))
		return ("");
	while ((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t'))
		j--;
	if (!(c = (char *)malloc(j - i + 2)))
		return (NULL);
	while (i + k <= j)
	{
		c[k] = s[k + i];
		k++;
	}
	c[k] = '\0';
	return (c);
}
