/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:34:42 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/24 18:45:51 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
}
