/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxim_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:16:58 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/20 12:35:43 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

off_t	maxim_size(t_dir *dp_l)
{
	struct stat	file_stat;
	off_t		max;

	max = 0;
	while (dp_l)
	{
		stat(dp_l->str, &file_stat);
		max = (file_stat.st_size > max ? file_stat.st_size : max);
		dp_l = dp_l->next;
	}
	return (max);
}
