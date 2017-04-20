/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:17:02 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 11:17:35 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_help(t_dir *dir, t_max *max, int c)
{
	if (c != 5)
	{
		sort_dir(&dir);
		if (c == 4)
			sort_by_date(&dir);
	}
	else if (c == 5)
		reverse_sort(&dir);
	if (c == 3)
		put_totsize(dir);
	while (dir)
	{
		if (c == 3)
			if (dir->name[0] != '.')
				put_stats(dir->str, max, dev_alert(dir));
		if (c == 1)
		{
			ft_putendl(dir->name);
		}
		else if (dir->name[0] != '.')
			ft_putendl(dir->name);
		dir = dir->next;
	}
}
