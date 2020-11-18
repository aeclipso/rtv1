/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_counter1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:28:21 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/24 18:54:36 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

void			fl_oint(int32_t rate, t_bi *t_f, t_ld n)
{
	uint64_t	mask;
	uint16_t	i;
	t_bi		*temp;

	i = 0;
	mask = STD_MASK;
	temp = cr_arrf();
	while (i < 64)
	{
		ft_crt_n(temp, 2);
		if (mask & n.ld.mant)
		{
			pow_bd2(temp, rate - i);
			addictive_int(t_f, temp);
		}
		mask = mask >> 1;
		i++;
	}
	free(temp);
}

void			f_iaf_i(int32_t *r, t_bi *t_f, t_bi *tmp, t_cntr *cn)
{
	if (cn->mask & cn->mant)
	{
		pow_bd2(tmp, *r - cn->i);
		addictive_int(t_f, tmp);
	}
}

void			f_iaf_f(int32_t *r, t_bi *t_f, t_bi *tmp, t_cntr *cn)
{
	if (cn->mask & cn->mant)
	{
		pow_bd5(tmp, *r - cn->i);
		addictive_frac(t_f, tmp);
	}
	if (ft_hmfe(t_f) == 0)
	{
		t_f->bd_frac[0] = 1;
		t_f->one_fl = 1;
	}
	mult10(t_f);
}

void			f_intandfrac(int32_t rate, t_bi *t_f, t_ld n)
{
	t_cntr			cn;
	t_bi			*temp;

	cn.i = -1;
	cn.mask = STD_MASK;
	cn.mant = n.ld.mant;
	temp = cr_arrf();
	while (++cn.i < 64)
	{
		ft_crt_n(temp, 25);
		if ((rate - cn.i) >= 0)
		{
			f_iaf_i(&rate, t_f, temp, &cn);
		}
		else
		{
			f_iaf_f(&rate, t_f, temp, &cn);
		}
		cn.mask = cn.mask >> 1;
	}
	ft_memdel((void *)&temp);
}
