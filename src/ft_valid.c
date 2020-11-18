/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:14:18 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/07 15:49:05 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_valid_name(char *s)
{
	if (ft_strequ(s, "cam:"))
		return (1);
	if (ft_strequ(s, "light:"))
		return (1);
	if (ft_strequ(s, "cone:"))
		return (1);
	if (ft_strequ(s, "sphere:"))
		return (1);
	if (ft_strequ(s, "plane:"))
		return (1);
	if (ft_strequ(s, "cylinder:"))
		return (1);
	return (0);
}

int	ft_count_box(char **box)
{
	int		i;
	char	**t;

	i = 0;
	t = box;
	while (t[i])
		i++;
	return (i);
}

int	ft_valid(char **box)
{
	int i;

	if (!(ft_valid_name(box[0])))
		ft_put_error("Wrong name");
	i = ft_count_box(box);
	if (ft_strequ(box[0], "cam:") && i == 7)
		return (i);
	if ((ft_strequ(box[0], "light:") || \
		ft_strequ(box[0], "sphere:")) && i == 9)
		return (i);
	if ((ft_strequ(box[0], "cone:") || \
		ft_strequ(box[0], "cylinder:")) && i == 12)
		return (i);
	if (ft_strequ(box[0], "plane:") && i == 11)
		return (i);
	ft_clear_box(box, i);
	ft_put_error("wrong input");
	return (0);
}
