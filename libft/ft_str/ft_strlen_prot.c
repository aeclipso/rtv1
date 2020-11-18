/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_prot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:57:49 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/25 22:19:26 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlen_prot(const char *str)
{
	size_t			i;
	unsigned char	*arr;

	if (str == NULL)
		return (0);
	i = 0;
	arr = (unsigned char*)str;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}
