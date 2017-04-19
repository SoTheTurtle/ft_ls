/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:57:09 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/18 15:51:26 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_simple(char *name, int c)
{
	DIR *dirp;
	struct dirent *dpr;
	off_t max;
	//int		minor_max;
	//int		major_max;
	int		user_max;
	int		group_max;
	t_dir *dir;
	t_dir *pimp;

	dir = NULL;
	//max = 0;
	//minor_max = 0;
	//major_max = 0;
	if (!(dirp = opendir(name)))
		return ;
	while ((dpr = readdir(dirp)) != NULL)
	{
		if (ft_strcmp(name, ".") != 0)
			add_elem(&dir, ft_strjoin(ft_strjoin(name, "/"), dpr->d_name));
		else
			add_elem(&dir, dpr->d_name);
	}
	user_max = max_user(dir);
	group_max = max_group(dir);
	max = maxim_size(dir);
	//major_max = maxim_major(dir); MYSTERY OF WHY IS NOT WORKING
	//major_max = 10;
//	minor_max = maxim_minor(dir);
	//minor_max = 100;
	if (c != 5)
	{
		sort_dir(&dir);
		if (c == 4)
			sort_by_date(&dir);
	}
	else if (c == 5)
		reverse_sort(&dir);
	pimp = dir;
	if (c == 3)
		put_totsize(dir);
	while (dir)
	{
		if (c == 3)
			if (dir->str[0] != '.')//this can be removed and => a -la flag
			{
                put_stats(dir->str, max, user_max, group_max, dev_alert(dir));
				/*if (ft_strcmp(name, ".") == 0)
					put_stats(dir->str, max, user_max, group_max, dev_alert(dir));//idk if this if is necessery
				else
					put_stats(ft_strjoin(ft_strjoin(name, "/"), dir->str), max, user_max, group_max, dev_alert(dir));*/
			}
		if (c == 1)
		{
			ft_putendl(dir->str);
		}
		else if (dir->str[0] != '.')
			ft_putendl(dir->str);
		dir = dir->next;
	}
	if (c == 2)
	{
		while (pimp)
		{
			if (is_dir(ft_strjoin(ft_strjoin(name, "/"), pimp->str)) &&
					(pimp->str[0] != '.'))
			{
				ft_putchar('\n');
				ft_putstr(name);
				ft_putchar('/');
				ft_putstr(pimp->str);
				ft_putstr(":\n");
				put_simple(ft_strjoin(ft_strjoin(name, "/"), pimp->str), c);
			}
			pimp = pimp->next;
		}
	}
	(void)closedir(dirp);
}

int main(int ac, char **av)
{
	int i;
	int c;
	int z = 0;

	i = 1;
	errno = 0;
	c = 0;
	if (ac == 1)
		put_simple(".", c);
	if (ac > 1 && ft_strcmp("-a", av[1]) == 0)
	{
		i++;
		c = 1;
	}
	else if (ac > 1 && ft_strcmp("-R", av[1]) == 0)
	{
		i++;
		c = 2;
	}
	else if (ac > 1 && ft_strcmp("-l", av[1]) == 0)
	{
		i++;
		c = 3;
	}
	else if (ac > 1 && ft_strcmp("-t", av[1]) == 0)
	{
		i++;
		c = 4;
	}
	else if (ac > 1 && ft_strcmp("-r", av[1]) == 0)
	{
		i++;
		c = 5;
	}
	if (i + 1 < ac)
		z = 1;
	if (i == ac && c != 0)
		put_simple(".", c);
	else while (i < ac)
	{
		if (z)
		{
			ft_putstr(av[i]);
			ft_putstr(":\n");
		}
		put_simple(av[i], c);
		i++;
		if (z)
			ft_putchar('\n');
	}

	//if there are multiple arguments should write the name of each before
	return (0);
}
