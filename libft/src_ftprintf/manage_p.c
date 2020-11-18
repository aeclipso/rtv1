/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:21:53 by ksean             #+#    #+#             */
/*   Updated: 2020/09/22 02:57:40 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_ox(char *s, t_print *data)
{
	char *dest;

	if (!s || !(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 3))))
		return (NULL);
	dest[0] = '0';
	dest[1] = 'x';
	dest[2] = '\0';
	ft_strcat(dest, s);
	free(s);
	if (ft_strcmp(dest, "0x") == 0 && *data->str != 'p')
	{
		free(dest);
		return (ft_strdup(""));
	}
	return (dest);
}

void	manage_p(t_print *data)
{
	char					*s;
	unsigned long long		a;

	a = va_arg(data->ap, unsigned long long);
	s = ft_itoa_base(a, 16);
	s = add_zero(s, data);
	s = add_precision(s, data);
	if ((ft_strchr("xX", *data->str) && a > 0) || *data->str == 'p')
		s = add_ox(s, data);
	if (s && ft_strcmp(s, "0x0") == 0 && ft_strchr("xX", *data->str))
	{
		free(s);
		s = add_blank(ft_strdup("0"), data);
		add_to_buff(s, data);
		free(s);
		return ;
	}
	if (*data->str == 'X')
		s = ft_strtoupper(s);
	s = add_blank(s, data);
	add_to_buff(s, data);
	free(s);
}
