/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 08:08:18 by ksean             #+#    #+#             */
/*   Updated: 2020/05/26 16:16:44 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sym(char s, t_print *data)
{
	if (data->buf.i != BUFF - 1)
		data->buf.buf[data->buf.i] = s;
	else
	{
		write(1, &data->buf.buf[0], data->buf.i);
		data->buf.i = 0;
		data->buf.buf[data->buf.i] = s;
	}
	data->buf.i += 1;
	data->res++;
}

void	add_to_buff(char *s, t_print *data)
{
	if (!s)
		return ;
	while (data->buf.i != BUFF && *s != '\0')
	{
		data->buf.buf[data->buf.i] = *s;
		s++;
		data->res++;
		data->buf.i += 1;
		if (data->buf.i == BUFF)
		{
			write(1, data->buf.buf, data->buf.i);
			data->buf.i = 0;
		}
	}
}
