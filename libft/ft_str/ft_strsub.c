/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:50:02 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/24 19:17:53 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	size_t			i;
	size_t			j;

	if (!s || !(arr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	j = start;
	while (i < len && s[j])
	{
		arr[i] = s[j];
		i++;
		j++;
	}
	arr[i] = 0;
	return (arr);
}
