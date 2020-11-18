/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:48:25 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/24 13:49:43 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_INT_H
# define BIG_INT_H

# include <stdint.h>
# include <string.h>
# include "ft_printf.h"

# define MAX_SIZE_T 18446744073709551615ULL
# define BASE 1000000000000000000ULL
# define N_EL 2000U
# define ST_LD 64
# define ST_DB 52
# define ST_FL 23
# define STD_MASK 0x8000000000000000

typedef struct		s_bi
{
	int8_t			sign;
	uint16_t		q_i;
	uint16_t		q_f;
	uint64_t		big_dig[N_EL];
	uint64_t		bd_frac[N_EL];
	uint16_t		one_fl;
	uint16_t		z_fl;
}					t_bi;

typedef union		u_ld
{
	long double		digit;
	struct			s_long_double
	{
		uint64_t	mant : 64;
		uint16_t	exp : 15;
		uint8_t		sign : 1;
	}				ld;
}					t_ld;

typedef struct		s_cntr
{
	uint64_t		mask;
	int64_t			i;
	uint64_t		mant;
}					t_cntr;

typedef struct		s_ijkm
{
	int32_t			i;
	int32_t			j;
	int32_t			k;
	uint64_t		m;
	int32_t			first_iter;
}					t_ijkm;

t_bi				*cr_arrf(void);
void				ft_tozero2_u16(uint16_t *i, uint16_t *j);
void				ft_crt2(t_bi *d);
void				ft_crt5(t_bi *d);
void				ft_crt_n(t_bi *d, uint16_t n);

void				ft_howmanyel(t_bi *n);
uint32_t			ft_hmfe(t_bi *t_f);
uint32_t			ft_whatismybigdig(t_bi *n);
char				*swap_str(char *s);

void				addictive_int(t_bi *summand, t_bi *addend);
void				addictive_frac(t_bi *summand, t_bi *addend);
void				mult2(t_bi *d);
void				mult5(t_bi *d);
void				mult10(t_bi *d);

void				pow_bd2(t_bi *d1, uint16_t d2);
void				pow_bd5(t_bi *d1, uint16_t d2);

void				fl_oint(int32_t rate, t_bi *t_f, t_ld n);
void				f_iaf_i(int32_t *r, t_bi *t_f, t_bi *tmp, t_cntr *cn);
void				f_iaf_f(int32_t *r, t_bi *t_f, t_bi *tmp, t_cntr *cn);
void				f_intandfrac(int32_t rate, t_bi *t_f, t_ld n);

void				f_iaf_f2(int32_t *r, t_bi *t_f, t_bi *tmp, t_cntr *cn);
void				fl_frac(int32_t rate, t_bi *t_f, t_ld n);
int					fl_crit(long double n, char **str);
void				counter_float(long double n, t_bi *t_f);
char				*ft_rounded(char **str, int n);

void				str_jnfr(char **str, char *temp);
char				*ldtoa_int(t_bi *dig, char *str);
char				*create_strfl(char *intg, char *frac);
const char			*create_minus(const char *s_dig);

void				first_iteration(t_ijkm *a, char **temp, t_bi *dig);
void				other_iteration(t_ijkm *a, char **temp, t_bi *dig);
char				*ldtoa_frac(t_bi *dig, char *str);
char				*ldtoa(t_bi *dig);
void				ft_boat(long double n, char **str);
char				*ft_round_zero(char **str);
char				*ft_nine(char *ret, char *start, int64_t *i);

#endif
