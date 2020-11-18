/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:27:00 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/23 20:17:36 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char			*ft_swap(char *s)
{
	char				buf;
	int					i;
	int					j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		buf = s[i];
		s[i] = s[j];
		s[j] = buf;
		i++;
		j--;
	}
	return (&s[0]);
}

static	int				ft_sign(long long int nbr)
{
	int					sign;

	if (nbr < 0)
		sign = -1;
	else
		sign = 1;
	return (sign);
}

char					*ft_itoa(int n)
{
	char				*arr;
	size_t				i;
	int					sign;
	long long int		nbr;

	if (!(arr = ft_strnew(ft_whatismyint(n))))
		return (NULL);
	nbr = (long long int)n;
	i = 0;
	if ((sign = ft_sign(nbr)) == -1)
		nbr = -nbr;
	while (nbr / 10)
	{
		arr[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	arr[i] = nbr + '0';
	i++;
	if (sign < 0)
	{
		arr[i] = '-';
	}
	arr = ft_swap(arr);
	return (arr);
}
