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
	fd = open("test.c", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if (!line && i > 20)
			break;
		printf("line [%i]: %s", i, line);
		i++;
		if (i == 7)
			close(fd);
		if (i == 8)
		{
			fd = open("test.c", O_RDONLY);
			printf("\n");
		}
		free (line);
	}
}
