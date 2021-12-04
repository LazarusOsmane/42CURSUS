/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:54 by engooh            #+#    #+#             */
/*   Updated: 2021/12/04 11:50:18 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_check_read(char *str, int err)
{
	if (err == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}


size_t	ft_strchr(char *str, size_t *n)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	printf("ok1.0\n");
	while (str[i] && str[i] != '\n')
		i++;
	printf("ok1.1\n");
	if (str[i] == '\n')
		*n = i;
	else 
		n = 0;
	return (*n);
}

char	*ft_strdup(char	*str, int size)
{
	int	i;
	char	*new;

	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i] && i < size)
		new[i] = str[i];
	*new = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2, char size)
{
	char	*new_line;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	new_line = malloc(sizeof(char) * (size + 1));
	if (!new_line)
		return (NULL);
	while (*s1)
		*new_line++ = *s1++;
	free(s1);
	while (*s2)
		*new_line++ = *s2++;
	*new_line = '\0';
	return (new_line);
}

char	*ft_read(char **memory, int fd)
{
	char	*buffer;
	int	l_buf;
	int	l_max;
	char	*line;
	size_t	n;

	n = 0;
	l_max = 0;
	l_buf = 0;
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("ok1\n");
	while (!ft_strchr(*memory + (l_max - l_buf), &n) && l_buf + 1)
	{
		l_buf = read(fd, buffer, BUFFER_SIZE);
		l_max += l_buf;
		buffer[l_buf + 1] = '\0';
		printf("ok2\n");
		if (n)
			line = ft_strjoin(line, buffer, (l_max - l_buf) + n);
		else 
			line = ft_strjoin(line, buffer, l_max);
		l_buf--;
	}
	if (l_buf)
		*memory = ft_strdup(*memory, l_max - n);
	return (ft_check_read(line, l_buf));
}

char	*get_next_line(int fd)
{
	static char	*memory[1024];
	char		*line;

	printf("ok\n");
	line = ft_read(&memory[fd], fd);
	//printf("%s", line);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	get_next_line(fd);
	//printf("\n%s", get_next_line(fd));
	return (0);
}
