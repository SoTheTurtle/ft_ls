/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:11:57 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 11:12:40 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	reverse_sort(t_dir **dir)
{
	t_dir *direct;
	t_dir *start;
	char *aux;

	start = *dir;
	direct = *dir;
	while (direct->next != NULL)
	{
		if (ft_strcmp(direct->str, direct->next->str) < 0)
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
