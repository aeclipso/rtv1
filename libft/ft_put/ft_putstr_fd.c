/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:32:36 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:24:28 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned char	*arr;
	int				i;

	if (!s || !fd)
		return ;
	i = 0;
	arr = (unsigned char*)s;
	while (arr[i])
	{
		ft_putchar_fd(arr[i], fd);
		i++;
	}
}
