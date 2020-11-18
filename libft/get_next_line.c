/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:23:08 by aeclipso          #+#    #+#             */
/*   Updated: 2020/02/15 20:44:47 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			butore(char **buf, char **line, int byte, int fd)
{
	int				l;
	char			*tmp;
	char			*tmp1;

	tmp = NULL;
	if (byte < 0)
		return (-1);
	l = ft_strchrnor(buf[fd], '\n', '\0');
	if (buf[fd][l] != '\0')
		tmp = ft_strdup_prot(buf[fd] + l + 1);
	else
		tmp = ft_strnew(0);
	*line = ft_strsub(buf[fd], 0, l);
	tmp1 = buf[fd];
	buf[fd] = tmp;
	free(tmp1);
	if ((buf[fd])[0] == 0)
		ft_strdel(&buf[fd]);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				byte;
	char			temp[BUFF_SIZE + 1];
	static	char	*buf[10240];
	char			*liq;

	if (fd < 0 || fd > 10240 || !line || BUFF_SIZE < 0)
		return (-1);
	while ((byte = read(fd, temp, BUFF_SIZE)) > 0)
	{
		if (byte < 0)
			return (-1);
		temp[byte] = 0;
		if (buf[fd] == NULL)
			buf[fd] = ft_strdup(temp);
		else
		{
			liq = ft_strjoin(buf[fd], temp);
			free((void*)buf[fd]);
			buf[fd] = liq;
		}
		if (ft_strchrn(buf[fd], '\n') >= 0)
			break ;
	}
	return ((buf[fd] == NULL && byte == 0) ? 0 : butore(buf, line, byte, fd));
}
