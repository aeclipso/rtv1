/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:39:05 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/24 13:50:32 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	size_t			nbr;
	int				sign;

	sign = 1;
	nbr = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v'
	|| *nptr == '\f' || *nptr == '\r' || *nptr == '\n')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign == -1 && nbr > 2147483648)
		return (0);
	else if (sign == 1 && nbr > 2147483647)
		return (-1);
	else
		return (sign * nbr);
}
