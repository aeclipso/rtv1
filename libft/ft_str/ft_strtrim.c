/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:39:59 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/24 18:01:31 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_be(const char *s)
{
	int			i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
	}
	return (i);
}

static	int		ft_en(const char *s)
{
	int			i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char		*arr;
	int			begin;
	int			end;
	size_t		i;

	if (!s)
		return (NULL);
	begin = ft_be(s);
	end = ft_en(s);
	if (begin == 0 && end == (int)ft_strlen(s))
		return ((char*)s);
	if (begin == (int)ft_strlen(s))
		return (ft_strnew(0));
	if (!(arr = ft_strnew(end - begin + 1)))
		return (NULL);
	i = 0;
	while (begin <= end)
	{
		arr[i] = s[begin];
		i++;
		begin++;
	}
	arr[i] = '\0';
	return (arr);
}
