/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:12:00 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:35:14 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_links(struct stat file_stat, int max_links)
{
	char	*s;
	int		n;
	int		c;

	c = (int)ft_strlen(ft_itoa(max_links));
	s = ft_itoa((int)file_stat.st_nlink);
	n = (int)ft_strlen(s);
	while (++n < c)
		ft_putchar(' ');
	ft_putstr(s);
	ft_putchar(' ');
}
