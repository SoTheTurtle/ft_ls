/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:31:38 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:17:38 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	read_dir(t_dir **dp, char *name)
{
	DIR				*dirp;
	struct dirent	*dpr;
	t_dir			*dir;

	dir = *dp;
	if (!(dirp = opendir(name)))
	{
		ft_putstr("ft_ls: ");
		perror(name);
		return (0);
	}
	while ((dpr = readdir(dirp)) != NULL)
	{
		if (ft_strcmp(name, ".") != 0)
			add_elem(&dir, ft_strjoin(ft_strjoin(name, "/"), dpr->d_name),
					dpr->d_name);
		else
			add_elem(&dir, dpr->d_name, dpr->d_name);
	}
	*dp = dir;
	(void)closedir(dirp);
	return (1);
}
