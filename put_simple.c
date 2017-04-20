/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:33:10 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 11:33:35 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_simple(char *name, int c)
{
	t_max *max;
	t_dir *dir;

	dir = NULL;
	if (!(read_dir(&dir, name)))
		return ;
	max = (t_max *)malloc(sizeof(t_max));
	max->link_max = max_links(dir);
	max->user_max = max_user(dir);
	max->group_max = max_group(dir);
	max->max_size = maxim_size(dir);
	put_help(dir, max, c);
	if (c == 2)
		put_help2(dir, name, c);
}
