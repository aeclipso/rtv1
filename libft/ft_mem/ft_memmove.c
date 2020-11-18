/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:28:58 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/16 22:00:41 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*arr2;

	if (!(dst) && !(src) && n != 0)
		return (NULL);
	arr = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	i = 0;
	if (arr < arr2)
	{
		while (i < n)
		{
			arr[i] = arr2[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			arr[n] = arr2[n];
		}
	}
	return (dst);
}
