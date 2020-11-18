/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:19:21 by ksean             #+#    #+#             */
/*   Updated: 2020/09/24 15:15:56 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	conversions(t_print *data)
{
	if (*data->str == '%')
		manage_percent(data);
	else if (*data->str == 'c')
		manage_c(data);
	else if (*data->str == 's')
		manage_s(data);
	else if (*data->str == 'd' || *data->str == 'i')
		manage_d(data);
	else if (*data->str == 'p')
		manage_p(data);
	else if (*data->str == 'u')
		manage_u(data);
	else if (*data->str == 'o')
		manage_o(data);
	else if (*data->str == 'f')
		manage_f(data);
	else if (*data->str == 'x' || *data->str == 'X')
		data->octotorp == 0 ? manage_x(data) : manage_p(data);
	if (*data->str || *data->str != '\0')
		data->str++;
}

int		parse(t_print *data)
{
	if (data->str == NULL)
	{
		ft_putstr("(null)");
		return (-1);
	}
	while (*data->str)
	{
		if (*data->str == '%')
		{
			reinit(data);
			data->str++;
			handle_flags(data);
			blank(data);
			precision(data);
			handle_types(data);
			conversions(data);
		}
		if (*data->str != '%' && *data->str)
		{
			add_sym(*data->str, data);
			data->str++;
		}
	}
	return (data->res);
}

int		ft_printf(const char *format, ...)
{
	t_print	*data;
	int		res;

	if (!(data = (t_print *)malloc(sizeof(t_print))))
		return (-1);
	ft_bzero((void*)data, sizeof(t_print));
	va_start(data->ap, format);
	data->str = format;
	res = parse(data);
	va_end(data->ap);
	write(1, data->buf.buf, data->buf.i);
	free(data);
	return (res);
}
