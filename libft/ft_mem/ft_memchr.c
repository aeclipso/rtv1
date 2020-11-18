/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:43:07 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:15:55 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	if (!n)
		return (NULL);
	i = 0;
	arr = (unsigned char*)s;
	while (i < n)
	{
		if (arr[i] == (unsigned char)c)
		{
			return (arr + i);
		}
		i++;
	}
	return (NULL);
}
