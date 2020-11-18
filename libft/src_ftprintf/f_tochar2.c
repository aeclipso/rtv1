/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tochar2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:01:24 by aeclipso          #+#    #+#             */
/*   Updated: 2020/08/04 22:28:16 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

void			first_iteration(t_ijkm *a, char **temp, t_bi *dig)
{
	uint64_t	d;

	*temp = ft_strnew(19);
	d = dig->bd_frac[a->i];
	while (d / 10)
	{
		(*temp)[a->j] = d % 10 + '0';
		d = d / 10;
		a->j++;
	}
	if (dig->one_fl)
	{
		if (d == 1)
			(*temp)[a->j] = '0';
		else
			(*temp)[a->j] = '0' + d - 1;
	}
	else
	{
		(*temp)[a->j] = d + '0';
		dig->one_fl = 0;
	}
}

void			other_iteration(t_ijkm *a, char **temp, t_bi *dig)
{
	uint64_t	d;

	*temp = ft_strnew(19);
	d = dig->bd_frac[a->i];
	while ((a->m /= 10))
	{
		if (d)
		{
			(*temp)[a->j] = d % 10 + '0';
			d = d / 10;
		}
		else
			(*temp)[a->j] = '0';
		a->j++;
	}
}

char			*ldtoa_frac(t_bi *dig, char *str)
{
	t_ijkm		a;
	char		*temp;
	char		*tmp;

	ft_bzero(&a, sizeof(t_ijkm));
	a.i = dig->q_f - 1;
	a.m = BASE;
	while (a.i >= 0)
	{
		a.j = 0;
		if (a.first_iter++ == 0)
			first_iteration(&a, &temp, dig);
		else
			other_iteration(&a, &temp, dig);
		temp = swap_str(temp);
		tmp = str;
		str = ft_strjoin(tmp, temp);
		ft_strdel(&tmp);
		ft_memdel((void *)&temp);
		a.i--;
		a.m = BASE;
	}
	return (str);
}

char			*ldtoa(t_bi *dig)
{
	uint32_t	i;
	char		*res;
	char		*res_frac;
	char		*str;

	i = ft_whatismybigdig(dig);
	res = (char *)ft_memalloc(sizeof(char) * i);
	res = ldtoa_int(dig, res);
	res_frac = (char *)ft_memalloc(sizeof(char) * i);
	res_frac = ldtoa_frac(dig, res_frac);
	str = create_strfl(res, res_frac);
	ft_strdel(&res);
	ft_strdel(&res_frac);
	if (dig->sign == -1)
		str = (char *)create_minus(str);
	return (str);
}

void			ft_boat(long double n, char **str)
{
	t_bi	dig;

	ft_bzero(&dig, sizeof(t_bi));
	if (fl_crit(n, str))
		return ;
	counter_float(n, &dig);
	*str = ldtoa(&dig);
}
