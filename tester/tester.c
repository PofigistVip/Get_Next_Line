#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

#define FT_GNL_FILE_SIMPLE "tests/simple.txt"

int		main(void)
{
	int		fd;
	char	*line;
	int		result;

	line = NULL;
	result = 0;
	if ((fd = open(FT_GNL_FILE_SIMPLE, O_RDONLY)) <= 0)
	{
		printf("Open %s error!\n", FT_GNL_FILE_SIMPLE);
		return (-1);
	}
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("Reading finished with %s\n", (result == 0) ? "ZERO" : "ERROR");
	return (0);
}