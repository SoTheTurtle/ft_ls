/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:22:00 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 12:22:20 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_size(struct stat file_stat, off_t max)
{
	off_t i;
	char *s;
	char *smax;
	int len_s;
	int len_smax;

	i = 0;
	smax = ft_itoa_base((intmax_t)max, 10);
	s = ft_itoa_base((intmax_t)file_stat.st_size, 10);
	len_s = ft_strlen(s);
	len_smax = ft_strlen(smax);
	while (len_s + i < len_smax)
	{
		ft_putchar(' ');
		i+=1;
	}
	ft_putstr(s);
	ft_putstr(" ");
}
