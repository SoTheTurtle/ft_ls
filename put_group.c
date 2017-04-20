/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:13:37 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:35:27 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_group(struct stat file_stat, int max)
{
	struct group	*grp;
	int				j;
	int				len;

	j = 0;
	grp = getgrgid(file_stat.st_gid);
	ft_putstr(grp->gr_name);
	len = ft_strlen(grp->gr_name);
	while (j + len < max)
	{
		ft_putchar(' ');
		j++;
	}
	ft_putstr("  ");
}
