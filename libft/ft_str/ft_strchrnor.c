/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:13:25 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/23 11:56:55 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrnor(char *s, int c1, int c2)
{
	int			i;
	char		*arr;

	arr = (char *)s;
	i = 0;
	while (arr[i])
	{
		if (arr[i] == (char)c1 || arr[i] == c2)
			return (i);
		i++;
	}
	if (c1 == '\0' || c2 == '\0')
		return (i);
	return (-1);
}
