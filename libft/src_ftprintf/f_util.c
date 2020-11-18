/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_util.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:10:40 by aeclipso          #+#    #+#             */
/*   Updated: 2020/08/07 03:31:40 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

/*
**  create array big int for safe float/ double/
**  long double. Coef is multiplextor for digit
*/

t_bi			*cr_arrf(void)
{
	t_bi	*big_dig;

	big_dig = (t_bi*)ft_memalloc(sizeof(t_bi));
	return (big_dig);
}

void			ft_tozero2_u16(uint16_t *i, uint16_t *j)
{
	*i = 0;
	*j = 0;
}

void			ft_crt2(t_bi *d)
{
	ft_bzero(d, sizeof(t_bi));
	d->big_dig[0] = 2;
}

void			ft_crt5(t_bi *d)
{
	ft_bzero(d, sizeof(t_bi));
	d->bd_frac[0] = 5;
}

void			ft_crt_n(t_bi *d, uint16_t n)
{
	if (n == 5)
	{
		ft_bzero(d, sizeof(t_bi));
		d->bd_frac[0] = n;
	}
	if (n == 2)
	{
		ft_bzero(d, sizeof(t_bi));
		d->big_dig[0] = 2;
	}
	if (n == 25)
	{
		ft_bzero(d, sizeof(t_bi));
		d->big_dig[0] = 2;
		d->bd_frac[0] = 5;
	}
}
