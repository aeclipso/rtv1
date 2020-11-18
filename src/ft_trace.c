/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:14:04 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/18 17:37:06 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		closest_func(t_rt *r, t_raydata vew, double t_max, int i)
{
	double t;

	if (ft_strequ(r->obj[i].name, "sphere"))
		t = ray_sphere(vew, r->obj[i]);
	else if (ft_strequ(r->obj[i].name, "plane"))
	{
		t = ft_ray_plane(vew, r->obj[i]);
	}
	else if (ft_strequ(r->obj[i].name, "cone"))
	{
		t = ft_ray_con(vew, &r->obj[i]);
		r->obj[i].t = t;
	}
	else
	{
		t = ft_ray_cylinder(vew, &r->obj[i]);
		r->obj[i].t = t;
	}
	if (t >= 0.000001 && t <= t_max && t < r->closest_t)
	{
		r->closest_t = t;
		r->clos = i;
	}
	return (r->closest_t);
}

t_vec		ft_traceray(t_raydata ray, t_rt *r)
{
	t_vec	s;
	t_vec	s1;

	r->i = 0;
	s1.x = 0;
	s1.y = 0;
	s1.z = 0;
	r->closest_t = INFINITY;
	r->clos = -1;
	while (r->i < r->amount_obj)
	{
		r->closest_t = closest_func(r, ray, INFINITY, r->i);
		r->i++;
	}
	if (r->clos == -1)
	{
		s = s1;
		return (s);
	}
	s = ft_lighting1(r, ray);
	return (s);
}

t_vec		get_direction(t_vector camera, int x, int y)
{
	t_vec		direction;
	t_vec		point;

	point = (t_vec){x - (WIDTH / 2), (HEIGHT / 2) - y, DIST};
	point = rot(point, camera.roter);
	direction = vec_norm(vec_sub(camera.point, point));
	return (direction);
}

t_raydata	creat_ray(double max_len, t_vec point, t_vec direction)
{
	t_raydata	ray;

	ray.t_max = max_len;
	ray.point = point;
	ray.direction = direction;
	return (ray);
}

void		ft_render(t_rt *r)
{
	int			i;
	int			j;
	t_vec		color;
	t_raydata	ray;

	i = 0;
	r->cam.roter = matr_rot(r->cam);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			r->cam.direct = get_direction(r->cam, i, j);
			ray = creat_ray(INFINITY, r->cam.point, r->cam.direct);
			color = ft_traceray(ray, r);
			SDL_SetRenderDrawColor(r->ren, color.x, color.y, color.z, 100);
			SDL_RenderDrawPoint(r->ren, i, j);
			j++;
		}
		i++;
	}
}
