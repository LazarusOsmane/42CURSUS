#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int	ft_strchr(char *str, int *n, char *str1)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*n = i;
		ok = 1;
	}
	while (str1 != str + i && ok)
	{
		*str1 + 1 = *str1;
		str1--;
	}
	if (ok)
		str1 + 1 = '\0';
	return (ok)
}

char get_next_line(int fd)
{
	static char	*str = malloc(sizeof(char) * (10000000 + 1)); 
	int		len_max;
	char		*line;
	int		len;
	int		back_slash_n;

	len = 1;
	line = str;
	len_max = 0;
	back_slash_n = 0;
	while (!ft_strchr(str + (len_max - len), '\n', &back_slash_n, str + len_max) && len)
	{
		len = read(fd, str + len_max, BUFFER_SIZE);
		len_max += len;
	}
	str += back_slash_n + len_max - len + 1);
	*str++ = '\0';
	return (line);
}


int main(void)
{
	static char	*str;
	int	n;
	int	fd = open("panda", O_RDONLY);

	n = 0;
	str = calloc(sizeof(char) * (BUFFER_SIZE * 2));
	n = read(fd, str + n, BUFFER_SIZE);
	printf("%s\n", str);
	*(str + n) = '\0';
	int b = n;
	char	*line = str;
	n += read(fd, str + n + 1, BUFFER_SIZE);
	printf("%s\n", line);
	printf("str 2 = %s", str + b + 1);
	return (0);
}
