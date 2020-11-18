/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 03:04:16 by ksean             #+#    #+#             */
/*   Updated: 2020/08/08 22:31:30 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_rounded(char **str, int n)
{
	char		*start;
	char		*ret;
	int64_t		i;
	uint32_t	j;

	start = NULL;
	if (n == 0)
		return (ft_round_zero(str));
	ret = ft_strdup(*str);
	ft_strdel(str);
	i = ft_strchrn(ret, '.') + n;
	j = i;
	if (ft_strchrn("56789", ret[i + 1]) >= 0)
	{
		ret[j + 1] = 0;
		if (ret[i] >= '0' && ret[i] <= '8')
			ret[i]++;
		else if (ret[i] == '9')
		{
			start = ft_nine(ret, start, &i);
			return (start);
		}
	}
	ret[j + 1] = 0;
	return (ret);
}

char			*add_oct(char *str)
{
	char *tmp;

	if (ft_strchrn(str, '.') == -1)
	{
		tmp = ft_strdup(str);
		str = ft_strjoin(tmp, ".");
		free(tmp);
	}
	return (str);
}

static	void	additional(t_print *data, char **str2, long double b)
{
	if (data->plus && b >= 0.0)
		*str2 = plus(*str2);
	if (data->space == 1 && b >= 0.0)
		*str2 = space(*str2);
	if (data->octotorp)
		*str2 = add_oct(*str2);
}

static	void	make_cool(t_print *data, long double b, char **str2)
{
	if (data->blank)
		data->zero = data->blank;
	if ((data->space || data->plus) && b > 0.0)
		data->zero--;
	*str2 = add_zero(*str2, data);
}

void			manage_f(t_print *data)
{
	long double	b;
	char		*str;
	char		*str2;
	int			precision_len;

	b = (data->type.bl == 1) ?
	va_arg(data->ap, long double) : (long double)va_arg(data->ap, double);
	precision_len = data->precision > -1 ? data->precision : 6;
	ft_boat(b, &str);
	if (!ft_strequ(str, "inf") && !ft_strequ(str, "-inf")
	&& !ft_strequ(str, "nan"))
		str2 = ft_rounded(&str, precision_len);
	else
		str2 = ft_strdup(str);
	if (data->precision > -1 &&
	((data->blank && data->zero == -1) || data->zero))
		make_cool(data, b, &str2);
	additional(data, &str2, b);
	str2 = add_blank(str2, data);
	add_to_buff(str2, data);
	free(str);
	ft_strdel(&str2);
}
