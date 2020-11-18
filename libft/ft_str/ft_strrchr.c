/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:44:45 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:39:26 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*arr;
	size_t	i;

	arr = (char *)s;
	i = ft_strlen(arr);
	if (i == 0 && (char)c == '\0')
		return (arr);
	while (i > 0)
	{
		if (arr[i] == (char)c)
			return (&arr[i]);
		i--;
	}
	if (i == 0 && arr[i] != (char)c)
		return (NULL);
	return (&arr[i]);
}
