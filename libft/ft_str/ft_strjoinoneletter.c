/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinoneletter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:51:33 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/16 13:10:03 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinoneletter(char const *s1, char const *s2)
{
	char		*arr;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + 1;
	if (!(arr = ft_strnew(i)))
		return (NULL);
	j = 0;
	while (j < (i - 1))
	{
		arr[j] = s1[j];
		j++;
	}
	arr[j] = s2[0];
	j++;
	arr[j] = '\0';
	return (arr);
}
