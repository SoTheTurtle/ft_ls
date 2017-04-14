/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:39:25 by sbanc             #+#    #+#             */
/*   Updated: 2017/01/06 12:20:59 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *somelst;
	t_list *resp;

	if ((lst == NULL) || (f == NULL))
		return (NULL);
	somelst = f(lst);
	resp = somelst;
	if (resp == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		somelst->next = f(lst);
		if (somelst->next == NULL)
			return (NULL);
		somelst = somelst->next;
	}
	return (resp);
}
