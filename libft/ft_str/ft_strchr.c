/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:12:40 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/08 16:00:46 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		*arr;

	arr = (char *)s;
	i = -1;
	while (arr[++i])
	{
		if (arr[i] == (char)c)
			return (&arr[i]);
	}
	if (c == '\0')
		return (&arr[i]);
	return (NULL);
}
