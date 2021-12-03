/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:54 by engooh            #+#    #+#             */
/*   Updated: 2021/12/03 19:44:54 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>





int	ft_strchr(char *str, int *n)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		*n = i;
	else 
		n = 0;
	return (n);
}


char	*ft_strjoin(char *dst, char *new, char size)
{
	char	*new_line;
	size_t	i;

	if (!buffer)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	new_line = malloc(sizeof(char) * (size));
	if (!new_line)
		return (NULL);
	while (*buffer && buffer != '\n')
		*new_line++  = *buffer++;
	if (*buffer == '\n')
		*memory = buffer;
	free(line);
	return (new_line);
}

char	*ft_check_read(char *memory, int err)
{
	if (err == -1)
	{
		free(memory);
		return (NULL);
	}
	return (memory);
}

char	*ft_read(char **memory, int fd)
{
	char	*buffer;
	int		l_buf;
	int		l_max;
	char	*line;
	int		n;

	n = 0;
	l_buf = 1;
	l_max = 0;
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(memory + (l_max - l_buf), &n) && l_buf)
	{
		l_buf = read(fd, buffer, BUFFER_SIZE);
		if (l_max == 0)
			l_max += ft_strlen(memory);
		l_max += l_buf;
		buffer[l_buf + 1] = '\0';
		if (n)
			*memory = ft_strjoin(*memory, buffer, (l_max - l_buf) + n);
		else
			*memory = ft_strjoin(*memory, buffer, l_max);

	}
	line = ft_strdup(memory, l_max - n);
	return (ft_check_read(*memory, l_buf));
}

char	*get_next_line(int fd)
{
	static char	*memory[1024];
	char		*line;

	//printf("ok1");
	line = ft_read(&memory[fd], fd);
	return (line);
}

int	main(int argc, char **argv)
{
	//char	*n;
	//char	*l = "h";
	//char	*t = "l";
	int	fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	//printf("ok");
	get_next_line(fd);
	//printf("\n%s", get_next_line(fd));
	return (0);
}
