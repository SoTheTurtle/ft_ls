/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:12:55 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:18:01 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_user(struct stat file_stat, int max)
{
	struct passwd	*user;
	int				j;
	int				len;

	j = 0;
	user = getpwuid(file_stat.st_uid);
	ft_putstr(user->pw_name);
	len = ft_strlen(user->pw_name);
	while (j + len < max)
	{
		ft_putchar(' ');
		j++;
	}
	ft_putstr("  ");
}
