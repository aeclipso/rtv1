/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:16:42 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/16 22:06:11 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*arr2;

	i = 0;
	if (!dst && !src)
		return (NULL);
	arr = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	while (arr2[i] != '\0' && (i < n))
	{
		arr[i] = arr2[i];
		i++;
	}
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
	return (dst);
}
