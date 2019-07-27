#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

static int		simple_test(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		result;

	if (argc != 3)
	{
		printf("usage ./tester simple [filename]\n");
		return (0);
	}
	line = NULL;
	result = 0;
	if ((fd = open(argv[2], O_RDONLY)) <= 0)
	{
		printf("Open %s error!\n", argv[2]);
		return (-1);
	}
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("%s$\n", line);
		free(line);
	}
	printf("Reading finished with %s\n", (result == 0) ? "ZERO" : "ERROR");
	close(fd);
	return (0);
}

static int		silence_test(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		result;

	if (argc != 3)
	{
		printf("usage ./tester silence [filename]\n");
		return (0);
	}
	line = NULL;
	result = 0;
	if ((fd = open(argv[2], O_RDONLY)) <= 0)
	{
		printf("Open %s error!\n", argv[2]);
		return (-1);
	}
	while ((result = get_next_line(fd, &line)) > 0)
		free(line);
	printf("Reading finished with %s\n", (result == 0) ? "ZERO" : "ERROR");
	close(fd);
	return (0);
}

static int		multi_test(int argc, char **argv)
{
	int		fd[2];
	char	*line[2];
	int		result[2];

	if (argc != 3)
	{
		printf("usage ./tester multi [filename]\n");
		return (0);
	}
	memset(fd, 0, sizeof(fd));
	memset(line, 0, sizeof(line));
	memset(result, 0, sizeof(result));
	if ((fd[0] = open(argv[2], O_RDONLY)) <= 0)
	{
		printf("Open %s error!\n", argv[2]);
		return (-1);
	}
	if ((fd[1] = open(argv[2], O_RDONLY)) <= 0)
	{
		close(fd[0]);
		printf("Open %s error!\n", argv[2]);
		return (-1);
	}
	while (1)
	{
		result[0] = get_next_line(fd[0], &(line[0]));
		result[1] = get_next_line(fd[1], &(line[1]));
		if (result[0] <= 0 || result[1] <= 0)
			break ;
		if (strcmp(line[0], line[1]) != 0)
			printf("---\n%s\n%s\n---", line[0], line[1]);
		free(line[0]);
		free(line[1]);
	}
	printf("Reading[0] finished with %s\n", (result[0] == 0) ? "ZERO" : "ERROR");
	printf("Reading[1] finished with %s\n", (result[1] == 0) ? "ZERO" : "ERROR");
	close(fd[0]);
	close(fd[1]);
	return (0);
}

static int		mod_select(char *mod, int argc, char **argv)
{
	if (strcmp(mod, "simple") == 0)
		return (simple_test(argc, argv));
	else if (strcmp(mod, "silence") == 0)
		return (silence_test(argc, argv));
	else if (strcmp(mod, "multi") == 0)
		return (multi_test(argc, argv));
	printf("usage ./tester [simple|silence|multi] [filename]\n");
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
		printf("usage ./tester [simple|multi] [filename]\n");
	else
		return (mod_select(argv[1], argc, argv));
	return (0);
}