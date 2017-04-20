/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_permissions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:09:46 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:34:09 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_permissions(struct stat file_stat)
{
	if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((file_stat.st_mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((file_stat.st_mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((file_stat.st_mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((file_stat.st_mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((file_stat.st_mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else
		ft_putchar('-');
	ft_putstr((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr("  ");
}
