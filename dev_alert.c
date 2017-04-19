/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_alert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:52:15 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 12:53:06 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		dev_alert(t_dir *dir)
{
	struct stat file_stat;

	while (dir)
	{
		lstat(dir->str, &file_stat);
		if ((file_stat.st_mode & S_IFMT) == S_IFCHR)
			return (1);
		else if ((file_stat.st_mode & S_IFMT) == S_IFBLK)
			return (1);
		dir = dir->next;
	}
	return (0);
}
