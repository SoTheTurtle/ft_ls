/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:36:12 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:36:56 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	max_links(t_dir *dir)
{
	struct stat	file_stat;
	int			n;

	n = 0;
	while (dir)
	{
		stat(dir->str, &file_stat);
		n = (n < file_stat.st_nlink ? file_stat.st_nlink : n);
		dir = dir->next;
	}
	return (n);
}
