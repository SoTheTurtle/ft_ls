/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:57:09 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:14:27 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	help_line(int ac, char **av)
{
	int c;

	c = 0;
	if ((ac > 1) && (ft_strcmp("-a", av[1]) == 0))
		c = 1;
	else if ((ac > 1) && (ft_strcmp("-R", av[1]) == 0))
		c = 2;
	else if ((ac > 1) && (ft_strcmp("-l", av[1]) == 0))
		c = 3;
	else if ((ac > 1) && (ft_strcmp("-t", av[1]) == 0))
		c = 4;
	else if ((ac > 1) && (ft_strcmp("-r", av[1]) == 0))
		c = 5;
	return (c);
}

int			main(int ac, char **av)
{
	int i;
	int c;
	int z;

	c = help_line(ac, av);
	if (ac == 1)
		put_simple(".", c);
	i = (c != 0 ? 2 : 1);
	z = (ac - i > 1 ? 1 : 0);
	if ((i == ac) && (c != 0))
		put_simple(".", c);
	else
		while (i < ac)
		{
			if (z)
			{
				ft_putstr(av[i]);
				ft_putstr(":\n");
			}
			put_simple(av[i], c);
			if (i + 1 < ac)
				ft_putchar('\n');
			i++;
		}
	return (0);
}
