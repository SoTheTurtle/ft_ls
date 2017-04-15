/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:57:09 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/15 13:36:17 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_size(struct stat file_stat, off_t max)
{
	off_t i;
	char *s;
	char *smax;

	i = 0;
	smax = ft_itoaBase((intmax_t)max, 10);
	s = ft_itoaBase((intmax_t)file_stat.st_size, 10);
	while (ft_strlen(s) + i < ft_strlen(smax))
	{
		ft_putchar(' ');
		i+=1;
	}
	ft_putstr(s);
	ft_putstr(" ");
}

void	put_group(struct stat file_stat)
{
	struct group *grp;

	grp = getgrgid(file_stat.st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
}

void	put_user(struct stat file_stat)
{
	struct passwd *user;

	user = getpwuid(file_stat.st_uid);
	ft_putstr(user->pw_name);
	ft_putstr("  ");
}

void	put_links(struct stat file_stat)
{
	ft_putstr(ft_itoa((int)file_stat.st_nlink));
	ft_putchar(' ');
}

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
	ft_putstr( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr( (file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr("  ");//2 spaces 1 should be for ACL
}

void	put_time(struct stat file_stat)
{
	time_t timev;
	int c;
	char *s;
	int i;

	c = 0;
	time(&timev);
	if (timev - file_stat.st_mtimespec.tv_sec > 15778463)
		c = 1;
	s = ctime(&file_stat.st_mtimespec.tv_sec);
	i = 0;
	while (i++ < 4)
		s++;
	i = 0;
	while (i < 7)
	{
		ft_putchar(*s++);
		i++;
	}
	if (c == 1)
		while (*s != ' ')
			s++;
	i = 0;
	while (i < 5)
	{
		ft_putchar(*s++);
		i++;
	}
	ft_putchar(' ');
}

void	put_stats(const char *s, off_t max)
{
	struct stat file_stat;

	if (stat(s, &file_stat) < 0)// lstat does same thing as stat
		return ;
	put_permissions(file_stat);
	put_links(file_stat);
	put_user(file_stat);
	put_group(file_stat);
	put_size(file_stat, max);
	put_time(file_stat);
}

off_t	maxim_size(t_dir *dp_l)
{
	struct stat file_stat;
	off_t max;

	max = 0;
	while (dp_l)
	{
		if (stat(dp_l->str, &file_stat) < 0)
			return (0);
		max = (file_stat.st_size > max ? file_stat.st_size : max);
		dp_l = dp_l->next;
	}
	return (max);
}

void	sort_dir(t_dir **dir)
{
	t_dir *direct;
	t_dir *start;
	char *aux;

	start = *dir;
	direct = *dir;
	while (direct->next != NULL)
	{
		if (ft_strcmp(direct->str, direct->next->str) > 0)
		{
			aux = direct->str;
			direct->str = direct->next->str;
			direct->next->str = aux;
			direct = start;
		}
		else
			direct = direct->next;
	}
	*dir = start;
}

void	add_elem(t_dir **dir, char *dp)
{
	t_dir *tmp;

	tmp = (t_dir *)malloc(sizeof(t_dir));
	if (tmp)
	{
		tmp->str = ft_strdup(dp);
		tmp->next = *dir;
		*dir = tmp;
	}
}

int time_switch_cond(const char *s1, const char *s2)
{
	struct stat file_stat1;
	struct stat file_stat2;

	stat(s1, &file_stat1);
	stat(s2, &file_stat2);
	if (file_stat1.st_mtimespec.tv_sec < file_stat2.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

void	sort_by_date(t_dir **dir)
{
	t_dir *direct;
	t_dir *start;
	char *aux;

	start = *dir;
	direct = *dir;
	while (direct->next != NULL)
	{
		if (time_switch_cond(direct->str, direct->next->str))
		{
			aux = direct->str;
			direct->str = direct->next->str;
			direct->next->str = aux;
			direct = start;
		}
		else
			direct = direct->next;
	}
	*dir = start;
}

void	reverse_sort(t_dir **dir)
{
	t_dir *direct;
	t_dir *start;
	char *aux;

	start = *dir;
	direct = *dir;
	while (direct->next != NULL)
	{
		if (ft_strcmp(direct->str, direct->next->str) < 0)
		{
			aux = direct->str;
			direct->str = direct->next->str;
			direct->next->str = aux;
			direct = start;
		}
		else
			direct = direct->next;
	}
	*dir = start;
}

int is_dir(char *name)
{
	struct stat file_stat;
	stat(name, &file_stat);
	if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

void put_totsize(t_dir *dir)
{
	struct stat file_stat;
	quad_t size;

	size = 0;
	while (dir)
	{
		stat(dir->str, &file_stat);
		if (dir->str[0] != '.')
			size += file_stat.st_blocks;
		dir = dir->next;
	}
	ft_putstr("total ");
	ft_putendl(ft_itoaBase((intmax_t)size, 10));
}

void	put_simple(char *name, int c)
{
	DIR *dirp;
	struct dirent *dpr;
	off_t max;
	//int		minor_max;
	//int		major_max;
	t_dir *dir;
	t_dir *pimp;

	dir = NULL;
	if (!(dirp = opendir(name)))
		return ;
	while ((dpr = readdir(dirp)) != NULL)
	{
		add_elem(&dir, dpr->d_name);
	}
	if (!(ft_strstr(name, "/dev")))
		max = maxim_size(dir);
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
				if (ft_strcmp(name, ".") == 0)
					put_stats(dir->str, max);
				else
					put_stats(ft_strjoin(ft_strjoin(name, "/"), dir->str), max);
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
