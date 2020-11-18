/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:36:34 by ksean             #+#    #+#             */
/*   Updated: 2020/04/18 08:27:39 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_x(t_print *data)
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
	s = add_zero(ft_itoa_base(i, 16), data);
	s = add_precision(s, data);
	s = add_blank(s, data);
	if (*data->str == 'X')
		s = ft_strtoupper(s);
	add_to_buff(s, data);
	free(s);
}
