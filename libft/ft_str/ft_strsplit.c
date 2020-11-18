/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:20:34 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/24 18:15:25 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_counterwords(char const *s, char c)
{
	size_t				quantity_words;
	size_t				iter_letter;

	quantity_words = 0;
	iter_letter = 0;
	if (!s)
		return (0);
	while (s[iter_letter])
	{
		if (s[iter_letter] != c && (s[iter_letter + 1] == c
		|| s[iter_letter + 1] == 0))
			quantity_words++;
		iter_letter++;
	}
	return (quantity_words);
}

static void				*ft_deleter(size_t iter_words, char **result_arr)
{
	iter_words--;
	while (iter_words > 0)
	{
		free(result_arr[iter_words]);
		result_arr[iter_words] = NULL;
		iter_words--;
	}
	free(result_arr);
	result_arr = NULL;
	return (NULL);
}

static size_t			ft_finddelim(char const *s, char c)
{
	size_t				i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

char					**ft_strsplit(char const *s, char c)
{
	size_t				quantity_words;
	size_t				quantity_letter;
	size_t				iter_words;
	char				**result_arr;

	iter_words = 0;
	quantity_words = ft_counterwords(s, c);
	if (!quantity_words
	|| !(result_arr = (char **)malloc(sizeof(char *) * (quantity_words + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		quantity_letter = ft_finddelim(s, c);
		if (!(result_arr[iter_words++] = ft_strsub(s, 0, quantity_letter)))
			return (ft_deleter(quantity_words, result_arr));
		s += quantity_letter;
	}
	result_arr[iter_words] = NULL;
	return (result_arr);
}
