/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:15:53 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:32:12 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_tozero(size_t *i, size_t *j, size_t *z)
{
	*i = 0;
	*j = 0;
	*z = 0;
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		z;

	ft_tozero(&i, &j, &z);
	while (dst[i] && i < size)
	{
		i++;
	}
	z = i;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src) + z);
}
