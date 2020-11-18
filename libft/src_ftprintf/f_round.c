/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_round.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:56:08 by aeclipso          #+#    #+#             */
/*   Updated: 2020/08/07 03:26:55 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

char			*ft_nine(char *ret, char *start, int64_t *i)
{
	if (ret == NULL)
		return (NULL);
	while (((ret)[*i] == '9' || (ret)[*i] == '.') && (*i) >= 0)
	{
		if ((ret)[*i] == '9')
			(ret)[*i] = '0';
		(*i)--;
	}
	(ret)[*i]++;
	if ((*i) == -1)
	{
		start = ft_strjoin("1", ret);
		free(ret);
		return (start);
	}
	return (ret);
}

static int		check_round_int(char *int_part)
{
	size_t		len;
	size_t		howmanyfn;
	size_t		i;

	len = ft_strlen(int_part);
	i = 0;
	howmanyfn = 0;
	if (int_part[0] == '9')
		while (i < len)
		{
			if (int_part[i] == '9')
				howmanyfn++;
			i++;
		}
	if (howmanyfn == len)
		return (1);
	else
		return (0);
}

static void		round_int_toten(char **int_part)
{
	size_t		i;

	i = ft_strlen(*int_part);
	(*int_part)[0] = '1';
	while (i > 0)
	{
		(*int_part)[i] = '0';
		i--;
	}
}

static void		round_int_toplus(char **int_part)
{
	size_t		i;

	i = ft_strlen(*int_part) - 1;
	(*int_part)[i]++;
}

char			*ft_round_zero(char **str)
{
	char		*ret;
	char		*integer_part;
	char		*float_part;
	uint64_t	i;

	i = 0;
	ret = ft_strdup(*str);
	while (ret[i] != '.')
		i++;
	integer_part = ft_memalloc(i + 2);
	float_part = ft_strnew(1);
	i = -1;
	while (ret[++i] != '.')
		integer_part[i] = ret[i];
	float_part[0] = ret[i + 1];
	if (ft_strchrn("56789", float_part[0]) >= 0)
	{
		if (check_round_int(integer_part))
			round_int_toten(&integer_part);
		else
			round_int_toplus(&integer_part);
	}
	free(ret);
	free(float_part);
	return (integer_part);
}
