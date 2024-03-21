/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:30:50 by amylle            #+#    #+#             */
/*   Updated: 2024/03/11 17:43:20 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	fd = open("a.out", O_RDONLY);

	while (1)
	{
		line = NULL;
		line = get_next_line(fd);
		if (!line && i > 20)
			break;
		printf("line [%i]: %s", i, line);
		i++;
		if (i == 1)
			close(fd);
		if (i == 2)
		{
			fd = open("a.out", O_RDONLY);
			printf("\n");
			printf("input anything rly\n");
			line = get_next_line(1);
			printf("stdin : %s\n", line);
			free (line);
			line = get_next_line(1);
		}
		free (line);
	}
}
