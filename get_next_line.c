/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:03:39 by ale-naou          #+#    #+#             */
/*   Updated: 2016/01/04 14:03:45 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char	*tmp;
	int			ret;
	char		buf[BUFF_SIZE + 1];


	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (tmp == NULL)
		tmp = ft_strnew(0);
	while (!ft_strchr(tmp, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	if (!ft_strchr(tmp, '\n'))
	{
		*line = ft_strdup(tmp);
		tmp = ft_strsub(tmp, ft_strlen(*line),
			ft_strlen(tmp));
	}
	else if (ft_strchr(tmp, '\n'))
	{
		*line = ft_strsub(tmp, 0, ft_strchr(tmp, '\n') - tmp);
		tmp = ft_strsub(tmp, ((ft_strchr(tmp, '\n') - tmp) + 1),
				ft_strlen(tmp));
		return (1);
	}
	return (0);
}
