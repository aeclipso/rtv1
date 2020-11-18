/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:59:25 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:17:47 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*arr;
	unsigned char	*arr2;

	i = 0;
	j = 0;
	arr = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	while (i < n)
	{
		if (arr[i] == arr2[i])
		{
			i++;
		}
		else
		{
			j = arr[i] - arr2[i];
			break ;
		}
	}
	return (j);
}
