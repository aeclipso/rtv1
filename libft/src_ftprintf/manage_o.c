/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:14:10 by ksean             #+#    #+#             */
/*   Updated: 2020/09/24 14:05:37 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_o(char *s)
{
	char *dest;

	if (!s)
		return (NULL);
	if (ft_strcmp(s, "0") == 0)
		return (s);
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2))))
		return (NULL);
	dest[0] = '0';
	dest[1] = '\0';
	dest = ft_strcat(dest, s);
	free(s);
	return (dest);
}

void	manage_o(t_print *data)
{
	long long	i;
	char		*s;

	i = (long long)va_arg(data->ap, void *);
	if (data->type.h == 1)
		i = (unsigned short)i;
	else if (data->type.hh == 1)
		i = (unsigned char)i;
	else if (data->type.l == 1)
		i = (unsigned long)i;
	else if (data->type.ll == 1)
		i = (unsigned long long)i;
	else
		i = va_arg(data->ap, unsigned int);
	s = ft_itoa_base(i, 8);
	if (data->octotorp)
		s = add_o(s);
	s = add_zero(s, data);
	if (data->octotorp == 0 || (data->octotorp && data->precision > 0))
		s = add_precision(s, data);
	s = add_blank(s, data);
	add_to_buff(s, data);
	free(s);
}
