/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_bigint2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:24:49 by aeclipso          #+#    #+#             */
/*   Updated: 2020/02/28 21:11:42 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

void		pow_bd2(t_bi *d1, uint16_t d2)
{
	uint16_t	i;

	i = 1;
	if (d2 == 1)
		return ;
	if (d2 == 0)
	{
		d1->big_dig[0] = 1;
		while (i < N_EL)
		{
			d1->big_dig[i] = 0;
			i++;
		}
		return ;
	}
	while (i < d2)
	{
		mult2(d1);
		i++;
	}
}

void		pow_bd5(t_bi *d1, uint16_t d2)
{
	uint16_t	i;

	d2 = -d2;
	i = 1;
	if (d2 == 1)
		return ;
	if (d2 == 0)
	{
		d1->bd_frac[0] = 1;
		while (i < N_EL)
		{
			d1->bd_frac[i] = 0;
			i++;
		}
		return ;
	}
	while (i < d2)
	{
		mult5(d1);
		i++;
	}
}
