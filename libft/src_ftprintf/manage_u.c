/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:00:10 by ksean             #+#    #+#             */
/*   Updated: 2020/04/18 08:27:15 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_u(t_print *data)
{
	long long	i;
	char		*s;

	if (data->type.h == 1)
		i = (unsigned short)va_arg(data->ap, unsigned int);
	else if (data->type.hh == 1)
		i = (unsigned char)va_arg(data->ap, unsigned int);
	else if (data->type.l == 1)
		i = va_arg(data->ap, unsigned long);
	else if (data->type.ll == 1)
		i = va_arg(data->ap, unsigned long long);
	else
		i = va_arg(data->ap, unsigned int);
	s = add_zero(ft_itoa_base(i, 10), data);
	s = add_precision(s, data);
	s = add_blank(s, data);
	add_to_buff(s, data);
	free(s);
}
