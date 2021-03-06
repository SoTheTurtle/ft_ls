/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 10:52:23 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/07 13:11:32 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int x;
	int n;

	n = 0;
	x = 0;
	while (((*nptr == 32) || (*nptr == '\t') || (*nptr == '\f') ||
			(*nptr == '\v') || (*nptr == '\r') || (*nptr == '\n'))
			&& (*nptr))
		nptr++;
	if (*nptr == '-')
	{
		n = 1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		x = (x * 10) + (*nptr - '0');
		nptr++;
	}
	if (n == 1)
		return (-x);
	return (x);
}
