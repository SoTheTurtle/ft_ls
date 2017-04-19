/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:14:46 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 11:15:50 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_elem(t_dir **dir, char *dp, char *name)
{
	t_dir *tmp;

	tmp = (t_dir *)malloc(sizeof(t_dir));
	if (tmp)
	{
		tmp->str = ft_strdup(dp);
		tmp->name = ft_strdup(name);
		tmp->next = *dir;
		*dir = tmp;
	}
}
