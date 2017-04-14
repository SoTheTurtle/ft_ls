/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:30:26 by sbanc             #+#    #+#             */
/*   Updated: 2017/02/26 17:32:09 by sbanc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*fc;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->content = (void *)malloc(content_size);
		if (new->content == NULL)
			return (NULL);
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			fc = (void *)malloc(content_size);
			ft_memcpy(fc, content, content_size);
			new->content = fc;
			new->content_size = content_size;
		}
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
