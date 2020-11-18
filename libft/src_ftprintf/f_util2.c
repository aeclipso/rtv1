/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_util2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:12:22 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/25 17:30:59 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"

void				ft_howmanyel(t_bi *n)
{
	uint16_t		i;
	uint16_t		j;
	uint16_t		k;

	k = 0;
	ft_tozero2_u16(&i, &j);
	while (i < N_EL / 2)
	{
		if (n->big_dig[i])
			j = i + 1;
		i++;
	}
	n->q_i = j;
	j = 0;
	while (k < N_EL / 2)
	{
		if (n->bd_frac[k])
			j = k + 1;
		k++;
	}
	n->q_f = j;
}

uint32_t			ft_hmfe(t_bi *t_f)
{
	uint32_t		i;
	uint32_t		j;

	i = 0;
	j = 0;
	while (i < N_EL)
	{
		if (t_f->bd_frac[i])
			j = i + 1;
		i++;
	}
	return (j);
}

uint32_t			ft_whatismybigdig(t_bi *n)
{
	int64_t			i;
	uint64_t		d;

	i = 0;
	d = n->big_dig[n->q_i - 1];
	while (d > 0)
	{
		i++;
		d = d / 10;
	}
	if (n->q_i > 1)
		i = (n->q_i - 1) * 18 + i;
	d = n->bd_frac[n->q_f - 1];
	while (d > 0)
	{
		i++;
		d = d / 10;
	}
	if (n->q_f > 1)
		i = (n->q_f - 1) * 18 + i;
	return (i);
}

char				*swap_str(char *s)
{
	char			buf;
	int				i;
	int				j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		buf = s[i];
		s[i] = s[j];
		s[j] = buf;
		i++;
		j--;
	}
	return (&s[0]);
}
