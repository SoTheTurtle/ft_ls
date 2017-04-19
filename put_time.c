/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:08:45 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 12:09:09 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_time(struct stat file_stat)
{
	time_t timev;
	int c;
	char *s;
	int i;

	c = 0;
	time(&timev);
	if (timev - file_stat.st_mtimespec.tv_sec > 15778463)
		c = 1;
	s = ctime(&file_stat.st_mtimespec.tv_sec);
	i = 0;
	while (i++ < 4)
		s++;
	i = 0;
	while (i < 7)
	{
		ft_putchar(*s++);
		i++;
	}
	if (c == 1)
		while (*s != ' ')
			s++;
	i = 0;
	while (i < 5)
	{
		ft_putchar(*s++);
		i++;
	}
	ft_putchar(' ');
}
