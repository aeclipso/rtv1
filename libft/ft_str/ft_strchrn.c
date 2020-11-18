/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:26:20 by aeclipso          #+#    #+#             */
/*   Updated: 2019/10/23 11:56:44 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchrn(const char *s, int c)
{
	int			i;
	char		*arr;

	arr = (char *)s;
	i = 0;
	while (arr[i])
	{
		if (arr[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}
