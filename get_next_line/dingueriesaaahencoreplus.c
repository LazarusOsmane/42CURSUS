#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int	ft_strchr(char *str, char *str1)
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
	char	*line;
	int		len;
	int		back_slash_n;

	len = 1;
	line = str;
	len_max = 0;
	back_slash_n = 0;
	while (!ft_strchr(str + (len_max - len), str + len_max, &back_slash_n) && len)
	{
		len = read(fd, str + len_max, BUFFER_SIZE);
		len_max += len;
	}
	str += back_slash_n + len_max - len + 1;
	*str++ = '\0';
	return (line);
}


int main(void)
{
	int	fd;

	fd = open("bible.txt", O_RDONLY);
	if (!fd)
		return (NULL);
	printf("%s", get_next_line(fd));
	return (0);
}
