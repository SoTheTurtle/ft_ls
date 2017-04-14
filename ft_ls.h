/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:00:26 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/09 14:20:01 by sbanc            ###   ########.fr       */
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
//nothing changes if remove the folowing includes
# include <sys/socket.h>
# include <netdb.h>
# include <ifaddrs.h>
# include <arpa/inet.h>
//# include <uid/uid.h>

typedef struct s_dir
{
	struct dirent *dp;
	struct s_dir *next;
}				t_dir;
extern int errno;

#endif
