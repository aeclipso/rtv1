/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:17:46 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/06 20:17:46 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLIB_H
# define VECLIB_H

# include <math.h>
# define DTR(a)	((double)a * (M_PI / 180))

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

t_vec			vec_sum(t_vec v1, t_vec v2);
double			vec_dot(t_vec v1, t_vec v2);
double			vec_len(t_vec v1);
t_vec			vec_scale(t_vec v1, double t);
t_vec			vec_norm(t_vec v1);
t_vec			vec_sub(t_vec v1, t_vec v2);
t_vec			vec_rot(t_vec d, t_vec r);
t_vec			vec_rotx(t_vec d, double a);
t_vec			vec_roty(t_vec d, double a);
t_vec			vec_rotz(t_vec d, double a);
#endif
