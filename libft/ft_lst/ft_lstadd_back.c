/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:34:27 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/24 18:45:24 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*temp;

	temp = *lst;
	if (lst)
	{
		if (*lst)
		{
			while ((*lst)->next)
				(*lst) = (*lst)->next;
			(*lst)->next = new;
		}
	}
	*lst = temp;
}
