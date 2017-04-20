/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:07:28 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:34:33 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_minor(struct stat file_stat)
{
	int		min;
	char	*s;
	int		len_s;
	int		i;

	min = minor(file_stat.st_rdev);
	s = ft_itoa_base((intmax_t)min, 10);
	len_s = ft_strlen(s);
	i = 0;
	while (len_s + i < 3)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(s);
	ft_putstr(" ");
}
