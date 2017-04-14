/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:25:22 by sbanc             #+#    #+#             */
/*   Updated: 2017/03/12 10:09:14 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_file(int const fd, char **str, char **line)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while ((tmp = ft_strchr(*str, '\n')) == NULL)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			*str = ft_strjoin(*str, buff);
		}
		else if (ret == 0)
		{
			if (ft_strlen(*str) == 0)
				return (0);
			*str = ft_strjoin(*str, "\n");
		}
		else
			return (-1);
	}
	*line = ft_strcdup(*str, '\n');
	*str = ft_strdup(tmp + 1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	int				i;
	static char		*str;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (str == NULL)
		str = (char *)malloc(sizeof(*str));
	if (!str)
		return (-1);
	while (((i = read_file(fd, &str, line)) != -1))
		return (i);
	return (-1);
}
