/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 08:00:43 by ksean             #+#    #+#             */
/*   Updated: 2020/08/08 21:06:10 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	minus(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (s[i] == '-')
		{
			s[0] = '-';
			s[i] = '0';
			return ;
		}
		i++;
	}
	return ;
}

char		*add_precision(char *s, t_print *data)
{
	char	*dest;
	int		lens;

	if (!(lens = ft_strlen(s)))
		return (NULL);
	if (data->precision == 0 && ft_strcmp(s, "0") == 0)
	{
		free(s);
		return (ft_strdup(""));
	}
	if (data->precision < lens)
		return (s);
	if (s[0] == '-')
		data->precision++;
	if (!(dest = (char *)malloc(sizeof(char) * (data->precision + 1))))
		return (NULL);
	ft_memset(dest, '0', data->precision - lens);
	dest[data->precision - lens] = '\0';
	ft_strcat(dest, s);
	minus(dest);
	free(s);
	return (dest);
}

char		*add_zero(char *s, t_print *data)
{
	char	*dest;
	int		lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (data->plus && s[0] != '-' && ft_strchr("di", *data->str))
		data->zero--;
	if (ft_strchr("xXp", *data->str) && data->octotorp && !ft_strequ("0", s))
		data->zero -= 2;
	if (data->zero <= lens || data->minus)
		return (s);
	if (!(dest = (char *)malloc(sizeof(char) * (data->zero + 1))))
		return (NULL);
	ft_memset(dest, '0', data->zero - lens);
	dest[data->zero - lens] = '\0';
	ft_strcat(dest, s);
	minus(dest);
	free(s);
	return (dest);
}

char		*add_blank(char *s, t_print *data)
{
	char	*dest;
	int		lens;

	lens = ft_strlen(s);
	if (data->zero > 0)
		data->blank = data->zero;
	if (data->blank < lens)
		return (s);
	if (!s || !(dest = (char*)malloc(sizeof(char) * (data->blank + 1))))
		return (NULL);
	if (data->minus)
	{
		ft_strcpy(dest, s);
		ft_memset(&dest[lens], ' ', data->blank - lens);
		dest[data->blank] = '\0';
	}
	else
	{
		ft_memset(dest, ' ', data->blank - lens);
		dest[data->blank - lens] = '\0';
		ft_strcat(dest, s);
	}
	free(s);
	return (dest);
}

void		reinit(t_print *data)
{
	data->precision = -1;
	data->blank = 0;
	data->octotorp = 0;
	data->plus = 0;
	data->minus = 0;
	data->space = 0;
	data->zero = 0;
	ft_bzero(&data->type, sizeof(t_types));
}
