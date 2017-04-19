/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:13:00 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 11:13:36 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_date(t_dir **dir)
{
	t_dir *direct;
	t_dir *start;
	char *aux;

	start = *dir;
	direct = *dir;
	while (direct->next != NULL)
	{
		if (time_switch_cond(direct->str, direct->next->str))
		{
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
