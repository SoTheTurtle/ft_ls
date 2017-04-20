/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_totsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:09:53 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:18:43 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_totsize(t_dir *dir)
{
	struct stat	file_stat;
	quad_t		size;

	size = 0;
	while (dir)
	{
		stat(dir->str, &file_stat);
		if (dir->str[0] != '.')
			size += file_stat.st_blocks;
		dir = dir->next;
	}
	ft_putstr("total ");
	ft_putendl(ft_itoa_base((intmax_t)size, 10));
}
