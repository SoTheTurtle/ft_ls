/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:57:09 by sbanc             #+#    #+#             */
/*   Updated: 2017/04/18 15:24:15 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_size(struct stat file_stat, off_t max)
{
	off_t i;
	char *s;
	char *smax;
	int len_s;
	int len_smax;

	i = 0;
	smax = ft_itoaBase((intmax_t)max, 10);
	s = ft_itoaBase((intmax_t)file_stat.st_size, 10);
	len_s = ft_strlen(s);
	len_smax = ft_strlen(smax);
	while (len_s + i < len_smax)
	{
		ft_putchar(' ');
		i+=1;
	}
	ft_putstr(s);
	ft_putstr(" ");
}

void	put_group(struct stat file_stat, int max)
{
	struct group *grp;
	int j;
	int len;

	j = 0;
	grp = getgrgid(file_stat.st_gid);
	ft_putstr(grp->gr_name);
	len = ft_strlen(grp->gr_name);
	while (j + len < max)
	{
		ft_putchar(' ');
		j++;
	}
	ft_putstr("  ");
}

void	put_user(struct stat file_stat, int max)
{
	struct passwd *user;
	int j;
	int len;

	j = 0;
	user = getpwuid(file_stat.st_uid);
	ft_putstr(user->pw_name);
	len = ft_strlen(user->pw_name);
	while (j + len < max)
	{
		ft_putchar(' ');
		j++;
	}
	ft_putstr("  ");
}

void	put_links(struct stat file_stat)
{
	ft_putstr(ft_itoa((int)file_stat.st_nlink));
	ft_putchar(' ');
}

int max_group(t_dir *dp)
{
	struct stat file_stat;
	struct group *grp;
	int max;
	int j;

	max = 0;
	while (dp)
	{
		stat(dp->str, &file_stat);
		grp = getgrgid(file_stat.st_gid);
		j = ft_strlen(grp->gr_name);
		max = (max < j ? j : max);
		dp = dp->next;
	}
	return (max);
}

int max_user(t_dir *dp)
{
	struct stat file_stat;
	struct passwd *user;
	int max;
	int j;

	max = 0;
	while (dp)
	{
		stat(dp->str, &file_stat);
		user = getpwuid(file_stat.st_uid);
		j = ft_strlen(user->pw_name);
		max = (max < j ? j : max);
		dp = dp->next;
	}
	return (max);
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

void	put_major(struct stat file_stat, int max)
{
	int maj;
	char *s;
	char *smax;
	int len[2];
	int i;

	i = 0;
	maj = major(file_stat.st_rdev);
	s = ft_itoaBase((intmax_t)maj, 10);
	smax = ft_itoaBase((intmax_t)max, 10);
	len[0] = ft_strlen(s);
	len[1] = ft_strlen(smax);
	while (len[0] + i < len[1])
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(s);
	ft_putstr(", ");
}

void	put_minor(struct stat file_stat, int max)
{
	int min;
	char *s;
	char *smax;
	int len_s[2];
	int i;

	min = minor(file_stat.st_rdev);
	s = ft_itoaBase((intmax_t)min, 10);
	smax = ft_itoaBase((intmax_t)max, 10);
	len_s[0] = ft_strlen(s);
	len_s[1] = ft_strlen(smax);
	i = 0;
	while (len_s[0] + i < len_s[1])
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(s);
	ft_putstr(" ");
}

void	put_stats(const char *s, off_t max, int minor, int major, int user_max, int group_max)
{
	struct stat file_stat;//need sth to know if minor and major were used

	if (stat(s, &file_stat) < 0)// lstat does same thing as stat
		return ;
	put_permissions(file_stat);
	put_links(file_stat);
	put_user(file_stat, user_max);
	put_group(file_stat, group_max);
	if ((file_stat.st_mode & S_IFMT) == S_IFCHR)
	{
		put_major(file_stat, major);
		put_minor(file_stat, minor);
	}
	else
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
		stat(dp_l->str, &file_stat);
		max = (file_stat.st_size > max ? file_stat.st_size : max);
		dp_l = dp_l->next;
	}
	return (max);
}

int		maxim_minor(t_dir *dp_l)
{
	int max;
	struct stat file_stat;
	int min;

	max = 0;
	while (dp_l)
	{
		stat(dp_l->str, &file_stat);
		min = minor(file_stat.st_rdev);
		max = (max < min ? min : max);
		dp_l = dp_l->next;
	}
	return (max);
}

int		maxim_major(t_dir *dp_l)
{
	int max;
	struct stat file_stat;
	int maj;

	max = 0;
	while (dp_l)
	{
		stat(dp_l->str, &file_stat);
		maj = major(file_stat.st_rdev);
		max = (max < maj ? maj : max);
		dp_l = dp_l->next;
	}
	/*ft_putstr("THIS IS MAXIMUM MAJOR |");
	ft_putnbr(max);
	ft_putstr("| \n");THIS IS WHERE IT FAILES*/
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
	int		minor_max;
	int		major_max;
	int		user_max;
	int		group_max;
	t_dir *dir;
	t_dir *pimp;

	dir = NULL;
	max = 0;
	minor_max = 0;
	major_max = 0;
	if (!(dirp = opendir(name)))
		return ;
	while ((dpr = readdir(dirp)) != NULL)
	{
		add_elem(&dir, dpr->d_name);
	}
	user_max = max_user(dir);
	group_max = max_group(dir);
	max = maxim_size(dir);
	minor_max = maxim_minor(dir);
	major_max = maxim_major(dir);
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
					put_stats(dir->str, max, minor_max, major_max, user_max, group_max);//idk if this if is necessery
				else
					put_stats(ft_strjoin(ft_strjoin(name, "/"), dir->str), max,
							minor_max, major_max, user_max, group_max);
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
