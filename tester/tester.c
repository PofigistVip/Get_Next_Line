#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		result;

	if (argc != 2)
	{
		printf("usage ./tester [filename]\n");
		return (0);
	}
	line = NULL;
	result = 0;
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
	{
		printf("Open %s error!\n", argv[1]);
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