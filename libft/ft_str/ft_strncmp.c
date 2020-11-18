/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:42:26 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/23 21:41:33 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	if (len == 0)
	{
		return (0);
	}
	i = 0;
	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	while ((arr[i] == arr2[i]) && arr[i] && arr2[i] && i < len)
	{
		if (i + 1 == len)
			break ;
		i++;
	}
	return (arr[i] - arr2[i]);
}
