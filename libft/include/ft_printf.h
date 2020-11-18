/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:19:51 by ksean             #+#    #+#             */
/*   Updated: 2020/10/24 13:49:30 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "big_int.h"
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF 64
# define FLAGS "#-+ 0"

typedef struct	s_flags
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			bl;
}				t_types;

typedef struct	s_buffer
{
	char	buf[BUFF];
	int		i;
}				t_buf;

typedef struct	s_print
{
	const char	*str;
	int			res;
	int			precision;
	int			blank;
	int			octotorp;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	va_list		ap;
	t_types		type;
	t_buf		buf;
}				t_print;

int				parse(t_print *data);
void			handle_flags(t_print *data);
void			handle_types(t_print *data);
void			precision(t_print *data);
void			blank(t_print *data);
void			zero(t_print *data);
void			conversions(t_print *data);

void			manage_p(t_print *data);
void			manage_d(t_print *data);
void			manage_u(t_print *data);
void			manage_o(t_print *data);
void			manage_x(t_print *data);
void			manage_s(t_print *data);
void			manage_c(t_print *data);
void			manage_f(t_print *data);
void			manage_percent(t_print *data);

char			*add_precision(char *s, t_print *data);
char			*add_blank(char *s, t_print *data);
char			*add_zero(char *s, t_print *data);
char			*plus(char *s);
char			*space(char *s);

char			*ft_strtoupper(char *c);
void			add_to_buff(char *s, t_print *data);
void			add_sym(char s, t_print *data);
void			reinit(t_print *data);

int				ft_printf(const char *format, ...);

#endif
