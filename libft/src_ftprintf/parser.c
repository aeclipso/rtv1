/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 08:17:44 by ksean             #+#    #+#             */
/*   Updated: 2020/09/24 15:52:09 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_types(t_print *data)
{
	if (*data->str == 'h')
	{
		data->str++;
		if (*data->str == 'h')
			data->type.hh = 1;
		else
			data->type.h = 1;
	}
	else if (*data->str == 'l')
	{
		data->str++;
		if (*data->str == 'l')
			data->type.ll = 1;
		else
			data->type.l = 1;
	}
	else if (*data->str == 'L')
		data->type.bl = 1;
	while (*data->str == 'l' || *data->str == 'h' || *data->str == 'L')
		data->str++;
	return ;
}

void	precision(t_print *data)
{
	if (*data->str != '.')
		return ;
	data->precision = 0;
	while (*data->str == '.')
		data->str++;
	while (*data->str >= 48 && *data->str <= 57)
	{
		data->precision *= 10;
		data->precision += (*data->str - 48);
		data->str++;
	}
	if (data->precision && data->zero)
	{
		data->blank = data->zero;
		data->zero = -1;
	}
	return ;
}

void	blank(t_print *data)
{
	if (!(*data->str >= 48 && *data->str <= 57))
		return ;
	while (*data->str >= 48 && *data->str <= 57)
	{
		data->blank *= 10;
		data->blank += (*data->str - 48);
		data->str++;
	}
	if (data->zero > 0 && data->blank > 0)
	{
		data->blank = data->zero;
		data->zero = 0;
	}
	return ;
}

void	zero(t_print *data)
{
	if (*data->str != '0')
		return ;
	while (*data->str >= 48 && *data->str <= 57)
	{
		data->zero *= 10;
		data->zero += (*data->str - 48);
		data->str++;
		if (*data->str == '#' || *data->str == '-' || *data->str == '+'
		|| *data->str == ' ')
			handle_flags(data);
	}
	return ;
}

void	handle_flags(t_print *data)
{
	while (ft_strchr(FLAGS, *data->str) && *data->str)
	{
		if (*data->str == '#')
			data->octotorp = 1;
		else if (*data->str == ' ' && data->plus == 0)
			data->space = 1;
		else if (*data->str == '+')
		{
			data->space = 0;
			data->plus = 1;
		}
		else if (*data->str == '0' && data->minus == 0)
		{
			zero(data);
			return ;
		}
		else if (*data->str == '-')
		{
			data->zero = 0;
			data->minus = 1;
		}
		data->str++;
	}
}
