/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tochar1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:42:52 by aeclipso          #+#    #+#             */
/*   Updated: 2020/08/07 03:30:56 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		str_jnfr(char **str, char *temp)
{
	char *tmp;

	temp = swap_str(temp);
	tmp = ft_strdup(*str);
	ft_strdel(str);
	*str = ft_strjoin(tmp, temp);
	ft_strdel(&tmp);
	ft_strdel(&temp);
}

char		*ldtoa_int(t_bi *dig, char *str)
{
	int64_t		d;
	int16_t		i;
	uint16_t	j;
	char		*temp;

	i = dig->q_i;
	if (i == 0)
	{
		free(str);
		str = ft_strdup("0");
	}
	while (--i >= 0)
	{
		j = 0;
		temp = ft_strnew(19);
		d = dig->big_dig[i];
		while (d / 10)
		{
			temp[j++] = d % 10 + '0';
			d = d / 10;
		}
		temp[j] = d + '0';
		str_jnfr(&str, temp);
	}
	return (str);
}

char		*create_strfl(char *intg, char *frac)
{
	char	*dot;
	char	*ret;
	char	*res;

	dot = ft_strdup(".");
	ret = ft_strjoin(intg, dot);
	res = ft_strjoin(ret, frac);
	free(dot);
	ft_strdel(&ret);
	return (res);
}

const char	*create_minus(const char *s_dig)
{
	const char	*t1;

	t1 = s_dig;
	s_dig = ft_strjoin("-", s_dig);
	free((void*)t1);
	return (s_dig);
}
