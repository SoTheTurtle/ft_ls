/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_switch_cond.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:14:01 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:15:26 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	time_switch_cond(const char *s1, const char *s2)
{
	struct stat file_stat1;
	struct stat file_stat2;

	stat(s1, &file_stat1);
	stat(s2, &file_stat2);
	if (file_stat1.st_mtimespec.tv_sec < file_stat2.st_mtimespec.tv_sec)
		return (1);
	return (0);
}
