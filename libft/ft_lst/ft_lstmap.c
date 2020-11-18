/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:35:09 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/24 18:50:11 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start_new;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	if (!(start_new = ft_lstnew(f(temp->content))))
		return (NULL);
	start_new->next = NULL;
	temp = temp->next;
	while (temp)
	{
		if (!(new = ft_lstnew(f(temp->content))))
		{
			ft_lstclear(&start_new, del);
			return (NULL);
		}
		ft_lstadd_back(&start_new, new);
		temp = temp->next;
	}
	return (start_new);
}
