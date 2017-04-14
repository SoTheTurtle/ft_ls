/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:21:00 by sbanc             #+#    #+#             */
/*   Updated: 2017/03/05 13:27:58 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		i;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if ((!s1) || (!s2))
		return (0);
	if (!(c = (char *)malloc(len + 1)))
		return (NULL);
	ft_strcpy(c, s1);
	ft_strcat(c, s2);
	return (c);
}
