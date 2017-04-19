/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:18:02 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 12:07:14 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_stats(const char *s, off_t max, int user_max, int group_max, int z)
{
	struct stat file_stat;//need sth to know if minor and major were used
	static int c = 0;//wont work if a directory is first
	int len;
	// l files dont work theyll be shown as c files
	// if c then need and extra space after group name
	// also minor is not aligned properly
	if (lstat(s, &file_stat) < 0)// lstat does same thing as stat
		return ;
	put_permissions(file_stat);
	put_links(file_stat);
	put_user(file_stat, user_max);
	put_group(file_stat, group_max);
	if (z)
		ft_putchar(' ');
	if ((file_stat.st_mode & S_IFMT) == S_IFCHR || (file_stat.st_mode & S_IFMT) == S_IFBLK)
	{
		put_major(file_stat);
		put_minor(file_stat);
		c++;
	}
	else
	{
		if (c)
		{
			len = 0;
			while (++len < 2)
				ft_putchar(' ');
			len = 0;
			while (++len < 3)
				ft_putchar(' ');
			//ft_putstr("  ");
		}
		put_size(file_stat, max);
	}
	put_time(file_stat);
}
