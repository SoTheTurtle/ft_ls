/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:00:26 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/19 12:58:39 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>

typedef struct	s_dir
{
	char		 *str;
    char        *name;
	struct s_dir *next;
}				t_dir;
extern int		errno;

void			put_totsize(t_dir *dir);
int				is_dir(char *name);
void			reverse_sort(t_dir **dir);
void			sort_by_date(t_dir **dir);
int				time_switch_cond(const char *s1, const char *s2);
void			add_elem(t_dir **dir, char *dp, char *name);
void			sort_dir(t_dir **dir);
off_t			maxim_size(t_dir *dp_l);
void			put_stats(const char *s, off_t max, int user_max, int group_max,
		int z, int max_links);
void			put_minor(struct stat file_stat);
void			put_major(struct stat file_stat);
void			put_time(struct stat file_stat);
void			put_permissions(struct stat file_stat);
int				max_user(t_dir *dp);
int				max_group(t_dir *dp);
void			put_links(struct stat file_stat, int max_links);
void			put_user(struct stat file_stat, int max);
void			put_group(struct stat file_stat, int max);
void			put_size(struct stat file_stat, off_t max);
int 			dev_alert(t_dir *dir);
int				max_links(t_dir *dir);

#endif
