/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_major.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:08:04 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:34:57 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_major(struct stat file_stat)
{
	int		maj;
	char	*s;
	int		len;
	int		i;

	i = 0;
	maj = major(file_stat.st_rdev);
	s = ft_itoa_base((intmax_t)maj, 10);
	len = ft_strlen(s);
	while (len + i < 2)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(s);
	ft_putstr(", ");
}
