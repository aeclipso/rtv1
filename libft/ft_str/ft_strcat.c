/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:29:42 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:43:01 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcat(char *dst, const char *src)
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
	while (arr2[j])
	{
		arr[i] = arr2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return ((char *)arr);
}
