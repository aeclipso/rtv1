/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:08:40 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/08 16:49:27 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*arr;
	size_t			i;

	if (size == 0)
		return (NULL);
	i = 0;
	if (!(arr = (unsigned char*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void*)arr);
}
