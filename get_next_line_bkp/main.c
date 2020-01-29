/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:26:21 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/29 08:10:35 by juolivei         ###   ########.fr       */
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
	int		ret;

	ret = 1;
	n_lines = atoi(argv[2]);
	if (argc != 3)
	{
		printf("usage eg: %s 'PATH TO FILE' 'NUMBER OF LINES TO OUTPUT'\n", argv[0]);
		printf("usage eg: %s 'PATH TO FILE' '-1' -> to show all lines\n", argv[0]);
		return (1);
	}
	if (n_lines < 0)
		n_lines = 1000000;
	if (!(fd = open(argv[1], O_RDONLY)))
		return (1);
	line = (char *)malloc(100 * sizeof(char));
	while ((ret = get_next_line(fd, &line) > 0) && (n_lines > 0))
	{
		printf("Retorno: %d, linha do arquivo: %s\n", ret, line);
		n_lines--;
	}
	if (!(close(fd)))
		return (1);
	return (0);
}
