/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:13:47 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/16 23:43:33 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_sphere(char **box, t_rt *r)
{
	r->obj[r->count].center.x = (double)(ft_atoi(box[1]));
	r->obj[r->count].center.y = (double)(ft_atoi(box[2]));
	r->obj[r->count].center.z = (double)(ft_atoi(box[3]));
	r->obj[r->count].radius = (double)(ft_atoi(box[4]));
	if (r->obj[r->count].radius < 0.1 || ft_atoi(box[5]) < 0 ||\
	ft_atoi(box[6]) < 0 || ft_atoi(box[7]) < 0)
	{
		ft_clear_box(box, 9);
		ft_put_error("Wrong input for sphere\n");
	}
	r->obj[r->count].color[0] = (unsigned char)(ft_atoi(box[5]));
	r->obj[r->count].color[1] = (unsigned char)(ft_atoi(box[6]));
	r->obj[r->count].color[2] = (unsigned char)(ft_atoi(box[7]));
	r->obj[r->count].specular = (double)(ft_atoi(box[8]));
	r->obj[r->count].name = "sphere";
	r->count++;
	ft_clear_box(box, 9);
}

double	ft_get_t(double k1, double k2, double k3)
{
	double	t[2];
	double	discriminant;

	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
		return (INFINITY);
	else
	{
		t[0] = (-k2 + sqrt(discriminant)) / (2 * k1);
		t[1] = (-k2 - sqrt(discriminant)) / (2 * k1);
		if ((t[0] < t[1] && t[0] > 0.0001) || (t[1] < 0 && t[0] > 0.00001))
			return (t[0]);
		else
			return (t[1]);
	}
}

double	ray_sphere(t_raydata vew, t_obj obj)
{
	double	r1;
	double	k1;
	double	k2;
	double	k3;
	t_vec	oc;

	oc = vec_sub(obj.center, vew.point);
	r1 = obj.radius;
	k1 = vec_dot(vew.direction, vew.direction);
	k2 = 2.0 * vec_dot(oc, vew.direction);
	k3 = vec_dot(oc, oc) - r1 * r1;
	return (ft_get_t(k1, k2, k3));
}
