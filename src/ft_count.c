/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:12:23 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/07 12:56:51 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_put_error(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	exit(1);
}

void	ft_error(t_rt *r, int i, int j)
{
	if (j != 1)
		ft_put_error("There is not camera");
	if (i == 0)
		ft_put_error("There is not light");
	if (r->amount_obj < 1)
		ft_put_error("There are not objects");
}

void	ft_clear_box(char **box, int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_strdel(&box[i]);
		i++;
	}
	free(box);
	box = NULL;
}

void	ft_count_obj(t_rt *r, char *arg)
{
	int		fd;
	char	*line;
	int		i;
	char	**box;
	int		k;

	i = 0;
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_put_error("Can't open the file");
	while (get_next_line(fd, &line))
	{
		box = ft_strsplit(line, ' ');
		if (!(ft_strequ(box[0], "light:") || (ft_strequ(box[0], "cam:"))))
			r->amount_obj++;
		if (ft_strequ(box[0], "light:"))
			r->s++;
		if (ft_strequ(box[0], "cam:"))
			i++;
		k = ft_valid(box);
		ft_strdel(&line);
		ft_clear_box(box, k);
	}
	ft_error(r, r->s, i);
	ft_strdel(&line);
	close(fd);
}
