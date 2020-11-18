/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:11:55 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/16 17:20:02 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_con(t_rt *r, char **box)
{
	r->obj[r->count].center.x = (double)(ft_atoi(box[1]));
	r->obj[r->count].center.y = (double)(ft_atoi(box[2]));
	r->obj[r->count].center.z = (double)(ft_atoi(box[3]));
	r->obj[r->count].radius = (double)(ft_atoi(box[4]));
	r->obj[r->count].rot.x = (double)(ft_atoi(box[5]));
	r->obj[r->count].rot.y = (double)(ft_atoi(box[6]));
	r->obj[r->count].rot.z = (double)(ft_atoi(box[7]));
	r->obj[r->count].rot = vec_norm(r->obj[r->count].rot);
	if (r->obj[r->count].radius < 0.1 || ft_atoi(box[8]) < 0\
		|| ft_atoi(box[9]) < 0 || ft_atoi(box[10]) < 0)
	{
		ft_clear_box(box, 12);
		ft_put_error("Wrong input for cone");
	}
	r->obj[r->count].color[0] = (unsigned char)(ft_atoi(box[8]));
	r->obj[r->count].color[1] = (unsigned char)(ft_atoi(box[9]));
	r->obj[r->count].color[2] = (unsigned char)(ft_atoi(box[10]));
	r->obj[r->count].specular = (double)(ft_atoi(box[11]));
	r->obj[r->count].name = "cone";
	r->count++;
	ft_clear_box(box, 12);
}

double	ft_ray_con(t_raydata ray, t_obj *obj)
{
	double	dot_ov_r;
	double	k;
	double	a;
	double	b;
	double	c;

	ray.st_cent = vec_sub(obj->center, ray.point);
	dot_ov_r = vec_dot(ray.direction, obj->rot);
	k = tan(0.5 * (obj->radius * M_PI / 180));
	k = k * k + 1.0;
	a = vec_dot(ray.direction, ray.direction) - k * pow(dot_ov_r, 2.0);
	b = 2.0 * (vec_dot(ray.direction, ray.st_cent)\
		- k * vec_dot(ray.st_cent, obj->rot) * dot_ov_r);
	c = vec_dot(ray.st_cent, ray.st_cent) - \
		k * pow(vec_dot(ray.st_cent, obj->rot), 2.0);
	return (ft_get_t(a, b, c));
}
