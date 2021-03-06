/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:30:02 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/06 12:24:56 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if ((s == NULL) || (f == NULL))
		return ;
	while ((*s) && (s != NULL))
	{
		f(s);
		s++;
	}
}
