/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:06:34 by ale-naou          #+#    #+#             */
/*   Updated: 2016/01/04 14:06:38 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	(void)argc;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	return (0);
}
