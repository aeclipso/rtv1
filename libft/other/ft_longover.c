/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longover.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:06:47 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/14 12:34:33 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_longover(const char *str, int sign)
{
	int		i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		i++;
	}
	if (i > 20 && sign == -1)
	{
		return (0);
	}
	else if (i > 20 && sign == 1)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
