#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"

int     main(int ac, char **av)
{
	//int	c;
	int	fd;
	char	*buf;

	(void)ac;
	(void)av;
	fd = 0;
	buf = malloc(sizeof(char));
	if (!buf)
		return (0);
	buf[0] = '\0';
	while (buf)
	{
		buf = ft_get_next_line(fd);
		printf("%s", buf);
	}
	free(buf);
	return (0);
}
