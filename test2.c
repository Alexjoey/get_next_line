#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*line;

	line = get_next_line(1);
	printf("stdin: %s\n", line);

	free (line);
}

