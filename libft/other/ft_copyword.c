/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:06:41 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/24 18:07:05 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_copyword(char **word, char const *s, char c)
{
	static size_t	next_word;
	size_t			i;

	i = 0;
	while (s[next_word] == c)
		next_word++;
	while (s[next_word] != c && s[next_word] != 0)
	{
		(*word)[i] = s[next_word];
		i++;
		next_word++;
	}
	(*word)[i] = 0;
}
