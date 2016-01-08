/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:03:39 by ale-naou          #+#    #+#             */
/*   Updated: 2016/01/08 16:35:13 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_ret_line(char **line, char **tmp, int fd)
{
	char	*del;

	if (!ft_strchr(tmp[fd], '\n'))
	{
		*line = ft_strdup(tmp[fd]);
		ft_strdel(&tmp[fd]);
	}
	else
	{
		del = tmp[fd];
		*line = ft_strsub(tmp[fd], 0, ft_strchr(tmp[fd], '\n') - tmp[fd]);
		tmp[fd] = ft_strsub(tmp[fd], ((ft_strchr(tmp[fd], '\n') - tmp[fd]) + 1),
				ft_strlen(tmp[fd]));
		ft_strdel(&del);
	}
}

int		get_next_line(int const fd, char **line)
{
	static char	*tmp[2147483648];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*del;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (tmp[fd] == NULL)
		tmp[fd] = ft_strnew(1);
	while (!ft_strchr(tmp[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		del = tmp[fd];
		buf[ret] = '\0';
		if (!(tmp[fd] = ft_strjoin(tmp[fd], buf)))
		{
			ft_strdel(&del);
			return (-1);
		}
		ft_strdel(&del);
	}
	if (ret == -1)
		return (-1);
	ft_ret_line(line, tmp, fd);
	return (!tmp[fd] && ft_strlen(*line) == 0 ? 0 : 1);
}
