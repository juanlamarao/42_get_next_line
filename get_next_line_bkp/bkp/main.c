/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:26:21 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/28 18:55:05 by juolivei         ###   ########.fr       */
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
		printf("usage: %s 'PATH TO FILE' 'NUMBER OF LINES TO OUTPUT'\n", argv[0]);
		return (1);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
		return (1);
	while (n_lines > 0 && ret > 0)
	{
		line = (char *)malloc(100 * sizeof(char));
		ret = get_next_line(fd, &line);
		printf("Retorno: %d, linha do arquivo: %s\n", ret, line);
		n_lines--;
	}
	if (!(close(fd)))
		return (1);
	return (0);
}
