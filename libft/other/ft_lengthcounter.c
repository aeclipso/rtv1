/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengthcounter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:05:25 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/24 18:52:35 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_lengthcounter(char const *s, char c)
{
	size_t			length;
	static size_t	iter_letter;

	length = 0;
	if (!s)
		return (0);
	while (s[iter_letter] == c)
		iter_letter++;
	while (s[iter_letter] && s[iter_letter] != c)
	{
		length++;
		iter_letter++;
	}
	return (length);
}
