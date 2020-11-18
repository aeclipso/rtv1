/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:36:32 by ksean             #+#    #+#             */
/*   Updated: 2020/08/08 20:37:53 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*plus(char *s)
{
	char *d;

	if (!s || !(d = (char*)malloc(sizeof(char) * (ft_strlen(s) + 2))))
		return (NULL);
	d[0] = '+';
	ft_strcpy(&d[1], s);
	free(s);
	return (d);
}

char	*space(char *s)
{
	char *d;

	if (!s || !(d = (char*)malloc(sizeof(char) * (ft_strlen(s) + 2))))
		return (NULL);
	d[0] = ' ';
	ft_strcpy(&d[1], s);
	free(s);
	return (d);
}

void	manage_d(t_print *data)
{
	char	*s;
	int64_t	i;

	if (data->type.h == 1)
		i = (short)va_arg(data->ap, int);
	else if (data->type.hh == 1)
		i = (char)va_arg(data->ap, int);
	else if (data->type.l == 1)
		i = (long)va_arg(data->ap, long);
	else if (data->type.ll == 1)
		i = (long long)va_arg(data->ap, long long);
	else
		i = va_arg(data->ap, int);
	s = ft_itoa(i);
	if (data->space && i >= 0)
		data->zero--;
	s = add_zero(s, data);
	s = add_precision(s, data);
	if (data->plus && i >= 0)
		s = plus(s);
	if (data->space == 1 && i >= 0)
		s = space(s);
	s = add_blank(s, data);
	add_to_buff(s, data);
	free(s);
}
