/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:26:21 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/26 15:46:55 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	int		n_lines;
	char	*line;

	n_lines = atoi(argv[2]);
	if (argc != 3)
	{
		printf("usage: %s 'PATH TO FILE' 'NUMBER OF LINES TO OUTPUT'\n", argv[0]);
		return (1);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
		return (1);
	while (n_lines > 0 || get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		n_lines--;
	}
	if (!(close(fd)))
		return (1);
	return (0);
}
