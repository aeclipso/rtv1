/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:43:54 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/25 12:51:25 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strreverse(char *s)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	if (!s || !(arr = (char *)malloc(sizeof(ft_strlen(s)) + 1)))
		return (NULL);
	while (i <= j)
	{
		arr[i] = s[j];
		i++;
		j--;
	}
	return (arr);
}
