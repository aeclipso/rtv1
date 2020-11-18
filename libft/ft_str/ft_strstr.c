/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:22:39 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:39:46 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_tozero(size_t *i, size_t *j, size_t *z)
{
	*i = 0;
	*j = 0;
	*z = 0;
}

char			*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	z;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	ft_tozero(&i, &j, &z);
	while (big[i])
	{
		if (big[i])
		{
			while (big[i] == little[j])
			{
				i++;
				j++;
				if (j == ft_strlen(little))
					return ((char*)&big[i - j]);
			}
			i++;
			j = 0;
		}
		i = ++z;
	}
	return (NULL);
}
