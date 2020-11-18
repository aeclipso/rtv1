/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:13:36 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/16 17:11:18 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_plane(t_rt *r, char **box)
{
	r->obj[r->count].center.x = (double)(ft_atoi(box[1]));
	r->obj[r->count].center.y = (double)(ft_atoi(box[2]));
	r->obj[r->count].center.z = (double)(ft_atoi(box[3]));
	r->obj[r->count].rot.x = (double)(ft_atoi(box[4]));
	r->obj[r->count].rot.y = (double)(ft_atoi(box[5]));
	r->obj[r->count].rot.z = (double)(ft_atoi(box[6]));
	if (ft_atoi(box[7]) < 0 || ft_atoi(box[8]) < 0 || ft_atoi(box[9]) < 0)
	{
		ft_clear_box(box, 11);
		ft_put_error("Wrong input for plane");
	}
	r->obj[r->count].color[0] = (unsigned char)(ft_atoi(box[7]));
	r->obj[r->count].color[1] = (unsigned char)(ft_atoi(box[8]));
	r->obj[r->count].color[2] = (unsigned char)(ft_atoi(box[9]));
	r->obj[r->count].specular = (double)(ft_atoi(box[10]));
	r->obj[r->count].name = "plane";
	r->count++;
	ft_clear_box(box, 11);
}

double	ft_ray_plane(t_raydata ray, t_obj obj)
{
	double		t;
	double		v_r;
	double		o_r;
	t_vec		x;

	x = vec_sub(obj.center, ray.point);
	o_r = vec_dot(x, obj.rot);
	v_r = vec_dot(ray.direction, obj.rot);
	t = (-o_r) / v_r;
	if ((t > 0.0001 && t < ray.t_max))
		return (t);
	return (INFINITY);
}
