/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:12:39 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/18 19:23:16 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_clone(t_rt *r, char **box)
{
	r->clone[r->count].center.x = (double)(ft_atoi(box[1]));
	r->clone[r->count].center.y = (double)(ft_atoi(box[2]));
	r->clone[r->count].center.z = (double)(ft_atoi(box[3]));
	r->clone[r->count].radius = (double)(ft_atoi(box[4])) / 10 + 0.1;
	r->clone[r->count].rot.x = (double)(ft_atoi(box[5]));
	r->clone[r->count].rot.y = (double)(ft_atoi(box[6]));
	r->clone[r->count].rot.z = (double)(ft_atoi(box[7]));
	r->clone[r->count].color[0] = (unsigned char)(ft_atoi(box[8]));
	r->clone[r->count].color[1] = (unsigned char)(ft_atoi(box[9]));
	r->clone[r->count].color[2] = (unsigned char)(ft_atoi(box[10]));
	r->clone[r->count].specular = (double)(ft_atoi(box[11]));
	r->clone[r->count].name = "cylinder";
}

void	ft_cylinder(t_rt *r, char **box)
{
	r->obj[r->count].center.x = (double)(ft_atoi(box[1]));
	r->obj[r->count].center.y = (double)(ft_atoi(box[2]));
	r->obj[r->count].center.z = (double)(ft_atoi(box[3]));
	r->obj[r->count].radius = (double)(ft_atoi(box[4])) / 10;
	r->obj[r->count].rot.x = (double)(ft_atoi(box[5]));
	r->obj[r->count].rot.y = (double)(ft_atoi(box[6]));
	r->obj[r->count].rot.z = (double)(ft_atoi(box[7]));
	if (r->obj[r->count].radius < 0.1 || ft_atoi(box[8]) < 0 ||\
		ft_atoi(box[9]) < 0 || ft_atoi(box[10]) < 0)
	{
		ft_clear_box(box, 12);
		ft_put_error("Wrong input for cylinder");
	}
	r->obj[r->count].color[0] = (unsigned char)(ft_atoi(box[8]));
	r->obj[r->count].color[1] = (unsigned char)(ft_atoi(box[9]));
	r->obj[r->count].color[2] = (unsigned char)(ft_atoi(box[10]));
	r->obj[r->count].specular = (double)(ft_atoi(box[11]));
	r->obj[r->count].name = "cylinder";
	r->obj[r->count].nbr = r->count;
	r->count++;
	ft_clear_box(box, 12);
}

double	ft_ray_cylinder(t_raydata ray, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	t_vec	x;

	x = vec_sub(obj->center, ray.point);
	a = vec_dot(ray.direction, ray.direction) - \
		pow(vec_dot(ray.direction, obj->rot), 2);
	b = 2 * (vec_dot(ray.direction, x) - \
		(vec_dot(ray.direction, obj->rot) * vec_dot(x, obj->rot)));
	c = vec_dot(x, x) - pow(vec_dot(x, obj->rot), 2) - pow(obj->radius, 2);
	return (ft_get_t(a, b, c));
}
