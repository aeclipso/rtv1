/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:04:10 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/13 18:49:03 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*arr2;

	i = 0;
	if (!(dst) && !(src) && n != 0)
		return (NULL);
	arr = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	while (i < n)
	{
		arr[i] = arr2[i];
		if (arr2[i] == (unsigned char)c)
		{
			return (arr + i + 1);
		}
		i++;
	}
	return (NULL);
}
