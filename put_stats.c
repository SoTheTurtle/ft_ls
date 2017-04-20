/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:18:02 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:29:55 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		put_stats_help(struct stat file_stat, t_max *max, int z)
{
	put_permissions(file_stat);
	put_links(file_stat, max->link_max);
	put_user(file_stat, max->user_max);
	put_group(file_stat, max->group_max);
	if (z)
		ft_putchar(' ');
}

void			put_stats(const char *s, t_max *max, int z)
{
	struct stat	file_stat;
	int			len;

	if (lstat(s, &file_stat) < 0)
		return ;
	put_stats_help(file_stat, max, z);
	if ((file_stat.st_mode & S_IFMT) == S_IFCHR ||
			(file_stat.st_mode & S_IFMT) == S_IFBLK)
	{
		put_major(file_stat);
		put_minor(file_stat);
	}
	else
	{
		if (z)
		{
			len = 0;
			while (++len < 4)
				ft_putchar(' ');
		}
		put_size(file_stat, max->max_size);
	}
	put_time(file_stat);
}
