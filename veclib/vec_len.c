/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:15:43 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/06 20:15:43 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "veclib.h"

double	vec_len(t_vec v1)
{
	return (sqrt(vec_dot(v1, v1)));
}
