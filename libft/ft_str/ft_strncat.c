/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:55:55 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:34:32 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;
	size_t			j;

	if (!dst && !src)
		return (NULL);
	arr = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	i = 0;
	j = 0;
	while (arr[i])
	{
		i++;
	}
	while (arr2[j] && j < n)
	{
		arr[i] = arr2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return ((char *)arr);
}
