/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:11:13 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:37:20 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	max_group(t_dir *dp)
{
	struct stat		file_stat;
	struct group	*grp;
	int				max;
	int				j;

	max = 0;
	while (dp)
	{
		stat(dp->str, &file_stat);
		grp = getgrgid(file_stat.st_gid);
		j = ft_strlen(grp->gr_name);
		max = (max < j ? j : max);
		dp = dp->next;
	}
	return (max);
}
