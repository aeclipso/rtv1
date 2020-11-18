/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:37:22 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/25 13:35:02 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	while ((arr[i] == arr2[i]) && arr[i] && arr2[i] && i < n)
	{
		if (i + 1 == n)
			break ;
		++i;
	}
	if (arr[i] == arr2[i])
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
