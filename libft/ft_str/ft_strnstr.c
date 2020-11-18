/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:13:09 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:38:45 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_tozero(size_t *i, size_t *j, size_t *z)
{
	*i = 0;
	*j = 0;
	*z = 0;
}

char				*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			k;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	ft_tozero(&i, &j, &k);
	while (s1[i])
	{
		while (s1[i] && i < len)
		{
			while (s1[i] == s2[j] && i < len)
			{
				i++;
				j++;
				if (j == ft_strlen((const char *)s2))
					return ((char *)(s1 + i - j));
			}
			j = 0;
			i++;
		}
		i = ++k;
	}
	return (NULL);
}
