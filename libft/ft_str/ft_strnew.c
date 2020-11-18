/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:38:43 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 13:36:16 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	i;

	if (size == MAX_SIZE_T)
		return (NULL);
	i = 0;
	arr = (char*)malloc(size + 1);
	if (!(arr))
		return (NULL);
	while (i < size + 1)
	{
		arr[i] = 0;
		i++;
	}
	return (&arr[0]);
}
