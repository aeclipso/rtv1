/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:11:32 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/18 17:47:18 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_cam(char **box, t_rt *r)
{
	r->cam.point.x = ft_atoi(box[1]);
	r->cam.point.y = ft_atoi(box[2]);
	r->cam.point.z = ft_atoi(box[3]);
	r->cam.angles.x = (double)ft_atoi(box[4]);
	r->cam.angles.y = (double)ft_atoi(box[5]);
	r->cam.angles.z = ft_atoi(box[6]);
	r->cam.insert = 0;
	ft_clear_box(box, 7);
}

void	ft_light1(char **box, t_rt *r)
{
	t_light	*begin;

	begin = r->light;
	r->light = (t_light *)malloc(sizeof(t_light));
	r->light->next = begin;
	r->light->type = ft_strdup(box[1]);
	r->light->intensity = ((double)ft_atoi(box[2])) / 100;
	r->light->position.x = ft_atoi(box[3]);
	r->light->position.y = ft_atoi(box[4]);
	r->light->position.z = ft_atoi(box[5]);
	r->light->direction.x = ft_atoi(box[6]);
	r->light->direction.y = ft_atoi(box[7]);
	r->light->direction.z = ft_atoi(box[8]);
	r->light->insert = 0;
}

void	ft_light(char **box, t_rt *r)
{
	if (r->light == NULL)
	{
		r->light = (t_light *)malloc(sizeof(t_light));
		r->light->type = ft_strdup(box[1]);
		r->light->intensity = ((double)ft_atoi(box[2])) / 100;
		r->light->position.x = ft_atoi(box[3]);
		r->light->position.y = ft_atoi(box[4]);
		r->light->position.z = ft_atoi(box[5]);
		r->light->direction.x = ft_atoi(box[6]);
		r->light->direction.y = ft_atoi(box[7]);
		r->light->direction.z = ft_atoi(box[8]);
		r->light->next = NULL;
	}
	else
		ft_light1(box, r);
	ft_clear_box(box, 9);
}
