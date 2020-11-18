/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:17:35 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:29:08 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	arr = (unsigned char *)dst;
	arr2 = (unsigned char *)src;
	i = 0;
	while (arr2[i] != '\0')
	{
		arr[i] = arr2[i];
		i++;
	}
	arr[i] = '\0';
	return (dst);
}
