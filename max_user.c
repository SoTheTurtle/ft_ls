/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:10:27 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:38:11 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	max_user(t_dir *dp)
{
	struct stat		file_stat;
	struct passwd	*user;
	int				max;
	int				j;

	max = 0;
	while (dp)
	{
		stat(dp->str, &file_stat);
		user = getpwuid(file_stat.st_uid);
		j = ft_strlen(user->pw_name);
		max = (max < j ? j : max);
		dp = dp->next;
	}
	return (max);
}
