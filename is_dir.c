/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:11:01 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 12:59:16 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_dir(char *name)
{
	struct stat file_stat;

	stat(name, &file_stat);
	if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}
