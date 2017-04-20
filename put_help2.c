/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_help2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:21:09 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 11:28:40 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_help2(t_dir *pimp, char *name, int c)
{
	while (pimp)
	{
		if (is_dir(pimp->str) &&
				(pimp->name[0] != '.'))
		{
			ft_putchar('\n');
			ft_putstr(name);
			ft_putchar('/');
			ft_putstr(pimp->str);
			ft_putstr(":\n");
			put_simple(pimp->str, c);
		}
		pimp = pimp->next;
	}
}
