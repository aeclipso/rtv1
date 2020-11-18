/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 07:40:41 by ksean             #+#    #+#             */
/*   Updated: 2020/04/18 07:54:02 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sym_count(unsigned long long a, unsigned int base)
{
	int i;

	i = 0;
	while (a >= base)
	{
		a = a / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned long long a, unsigned int base)
{
	int		k;
	int		i;
	char	*dest;

	i = sym_count(a, base);
	if (!(dest = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	dest[i + 1] = '\0';
	while (a >= base)
	{
		k = a - ((a / base) * base);
		a /= base;
		dest[i] = (k > 9 ? k + 87 : k + 48);
		i--;
	}
	dest[i] = (a > 9 ? a + 87 : a + 48);
	return (dest);
}
