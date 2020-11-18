/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:11:32 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/23 14:47:28 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_free1(char **s1, char *s2)
{
	char		*arr;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(arr = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		arr[i] = *s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	ft_strdel((char**)&s1);
	return (arr);
}

char			*ft_strjoin_free2(char *s1, char **s2)
{
	char		*arr;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(arr = ft_strnew(ft_strlen(s1) + ft_strlen(*s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i + j] = *s2[j];
		j++;
	}
	arr[i + j] = '\0';
	ft_strdel((char**)&s2);
	return (arr);
}
