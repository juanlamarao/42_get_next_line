/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:13:24 by juolivei          #+#    #+#             */
/*   Updated: 2020/01/30 09:25:29 by juolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	int fd;
	char *line;

	if (argc == 1)
		fd = open("arquivo", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Valor de FD: %i\n", fd);
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
		printf("%s", line);
	return (0);
}
