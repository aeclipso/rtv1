/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:37:37 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/16 18:41:09 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matr			matr_mol(t_matr a, t_matr b)
{
	t_matr	res;

	res.l = a.l * b.l -
			(a.vec.x * b.vec.x + a.vec.y * b.vec.y + a.vec.z * b.vec.z);
	res.vec.x = a.l * b.vec.x + b.l * a.vec.x +
				a.vec.y * b.vec.z - b.vec.y * a.vec.z;
	res.vec.y = a.l * b.vec.y + b.l * a.vec.y +
				a.vec.z * b.vec.x - b.vec.z * a.vec.x;
	res.vec.z = a.l * b.vec.z + b.l * a.vec.z +
				a.vec.x * b.vec.y - b.vec.x * a.vec.y;
	return (res);
}

t_vec			rot(t_vec vector, t_matr rotor)
{
	t_matr	tmp;

	tmp = matr_mol(rotor, (t_matr){0.0, vector});
	rotor.vec = vec_scale(rotor.vec, -1);
	matr_normal(&rotor);
	tmp = matr_mol(tmp, rotor);
	vector.x = tmp.vec.x;
	vector.y = tmp.vec.y;
	vector.z = tmp.vec.z;
	return (vector);
}

static t_matr	rot1(t_matr m, double angle)
{
	t_matr	ax;
	double	a;

	a = angle * M_PI / 360.0;
	ax.l = m.l * cos(a);
	ax.vec.x = m.vec.x * sin(a);
	ax.vec.y = m.vec.y * sin(a);
	ax.vec.z = m.vec.z * sin(a);
	return (ax);
}

t_matr			matr_rot(t_vector cam)
{
	t_matr	roter;
	t_matr	ax_x;
	t_matr	ax_y;
	t_matr	ax_z;

	roter = (t_matr){1, (t_vec){0, 0, 0}};
	ax_x = rot1((t_matr){1, (t_vec){0, 1, 0}}, cam.angles.x);
	ax_y = rot1((t_matr){1, (t_vec){1, 0, 0}}, cam.angles.y);
	ax_z = rot1((t_matr){1, (t_vec){0, 0, 1}}, cam.angles.z);
	roter = matr_mol(roter, ax_x);
	roter = matr_mol(roter, ax_y);
	roter = matr_mol(roter, ax_z);
	return (roter);
}
