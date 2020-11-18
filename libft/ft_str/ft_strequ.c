/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:17:53 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:31:06 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	if (!s1 || !s2)
	{
		return (0);
	}
	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	while ((arr[i] == arr2[i]) && arr[i] && arr2[i])
	{
		i++;
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
