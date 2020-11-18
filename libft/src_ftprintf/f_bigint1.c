/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_bigint1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:22:06 by aeclipso          #+#    #+#             */
/*   Updated: 2020/08/03 23:12:41 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

void			addictive_int(t_bi *summand, t_bi *addend)
{
	uint16_t	i;
	uint64_t	carry;

	i = 0;
	carry = 0;
	while (i < N_EL)
	{
		summand->big_dig[i] = summand->big_dig[i] + addend->big_dig[i] + carry;
		if (summand->big_dig[i] >= BASE)
		{
			summand->big_dig[i] = summand->big_dig[i] - BASE;
			carry = 1;
		}
		else
			carry = 0;
		i++;
	}
}

void			addictive_frac(t_bi *summand, t_bi *addend)
{
	uint16_t	i;
	uint64_t	carry;

	i = 0;
	carry = 0;
	while (i < N_EL)
	{
		summand->bd_frac[i] = summand->bd_frac[i] + addend->bd_frac[i] + carry;
		if (summand->bd_frac[i] >= BASE)
		{
			summand->bd_frac[i] = summand->bd_frac[i] - BASE;
			carry = 1;
		}
		else
			carry = 0;
		i++;
	}
}

void			mult2(t_bi *d)
{
	uint16_t	i;
	uint64_t	carry;

	i = 0;
	carry = 0;
	while (i < N_EL)
	{
		d->big_dig[i] = d->big_dig[i] * 2 + carry;
		if (d->big_dig[i] >= BASE)
		{
			carry = d->big_dig[i] / BASE;
			d->big_dig[i] = d->big_dig[i] % BASE;
		}
		else
			carry = 0;
		i++;
	}
}

void			mult5(t_bi *d)
{
	uint16_t	i;
	uint64_t	carry;

	i = 0;
	carry = 0;
	while (i < N_EL)
	{
		d->bd_frac[i] = d->bd_frac[i] * 5 + carry;
		if (d->bd_frac[i] >= BASE)
		{
			carry = d->bd_frac[i] / BASE;
			d->bd_frac[i] = d->bd_frac[i] % BASE;
		}
		else
			carry = 0;
		i++;
	}
}

void			mult10(t_bi *d)
{
	uint16_t	i;
	uint64_t	carry;

	i = 0;
	carry = 0;
	while (i < N_EL)
	{
		d->bd_frac[i] = d->bd_frac[i] * 10 + carry;
		if (d->bd_frac[i] >= BASE)
		{
			carry = d->bd_frac[i] / BASE;
			d->bd_frac[i] = d->bd_frac[i] % BASE;
		}
		else
			carry = 0;
		i++;
	}
}
