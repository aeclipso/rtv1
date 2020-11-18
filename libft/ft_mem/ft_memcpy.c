/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:50:35 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/08 17:05:42 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*arr2;

	if (!dst && !src)
		return (NULL);
	i = 0;
	arr = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	while (i < n)
	{
		arr[i] = arr2[i];
		i++;
	}
	return (dst);
}
