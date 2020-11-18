/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:54:30 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:24:45 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	unsigned char	*arr;
	int				i;

	if (!s)
		return ;
	i = 0;
	arr = (unsigned char*)s;
	while (arr[i])
	{
		ft_putchar(arr[i]);
		i++;
	}
}
