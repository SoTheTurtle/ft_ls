/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:16:03 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:15:57 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_dir(t_dir **dir)
{
	t_dir	*direct;
	t_dir	*start;
	char	*aux;

	start = *dir;
	direct = *dir;
	while (direct->next != NULL)
	{
		if (ft_strcmp(direct->name, direct->next->name) > 0)
		{
			aux = direct->name;
			direct->name = direct->next->name;
			direct->next->name = aux;
			aux = direct->str;
			direct->str = direct->next->str;
			direct->next->str = aux;
			direct = start;
		}
		else
			direct = direct->next;
	}
	*dir = start;
}
