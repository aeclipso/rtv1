/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_counter2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:10:43 by aeclipso          #+#    #+#             */
/*   Updated: 2020/08/07 02:49:21 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

void			f_iaf_f2(int32_t *r, t_bi *t_f, t_bi *tmp, t_cntr *cn)
{
	if (cn->mask & cn->mant)
	{
		pow_bd5(tmp, *r - cn->i);
		addictive_frac(t_f, tmp);
	}
	mult10(t_f);
}

void			fl_frac(int32_t rate, t_bi *t_f, t_ld n)
{
	t_cntr		cn;
	t_bi		*temp;
	int64_t		a_rate;

	cn.i = -1;
	a_rate = -rate;
	cn.mask = STD_MASK;
	cn.mant = n.ld.mant;
	temp = cr_arrf();
	if (a_rate > 1)
	{
		t_f->bd_frac[0] = 1;
		t_f->one_fl = 1;
		t_f->z_fl = 1;
		while (--a_rate >= 1)
			mult10(t_f);
	}
	while (++cn.i < 64)
	{
		ft_crt_n(temp, 5);
		f_iaf_f2(&rate, t_f, temp, &cn);
		cn.mask = cn.mask >> 1;
	}
	free(temp);
}

int				fl_crit(long double n, char **str)
{
	if (n == 1.0 / 0.0)
	{
		*str = ft_strdup("inf");
		return (1);
	}
	else if (n == -1.0 / 0.0)
	{
		*str = ft_strdup("-inf");
		return (1);
	}
	else if (n != n)
	{
		*str = ft_strdup("nan");
		return (1);
	}
	else
		return (0);
}

void			counter_float(long double n, t_bi *t_f)
{
	t_ld		ld_dig;
	int32_t		rate;

	ld_dig.digit = n;
	if (ld_dig.ld.sign == 1)
		t_f->sign = -1;
	rate = ld_dig.ld.exp - 16383;
	if (rate >= 64)
		fl_oint(rate, t_f, ld_dig);
	else if (rate < 64 && rate >= 0)
		f_intandfrac(rate, t_f, ld_dig);
	else
		fl_frac(rate, t_f, ld_dig);
	ft_howmanyel(t_f);
}
