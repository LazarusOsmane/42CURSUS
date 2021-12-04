/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:54 by engooh            #+#    #+#             */
/*   Updated: 2021/12/04 16:39:44 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_check_read(char *str, char	*buf, int err)
{
	if (err < 1)
	{
		free(str);
		free(buf);
		return (NULL);
	}
	return (str);
}


size_t	ft_strchr(char *str, long start, size_t *n)
{
	if (!str)
		return (0); 
	if (start == -1)
		start++;
	while (str[start] && str[start] != '\n')
		start++;
	if (str[start] == '\n')
		*n = start;
	else 
		*n = 0;
	return (*n);
}

char	*ft_strdup(char	*str, size_t size)
{
	size_t	i;
	char	*new;

	if (*str)
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2, char size)
{
	char	*new_line;
	char	*c;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	new_line = malloc(sizeof(char) * (size + 1));
	if (!new_line || !s2)
		return (NULL);
	c = new_line;
	i = -1;
	while (s1[++i])
		*new_line++ = s1[i];
	i = -1;
	while (s2[++i])
		*new_line++ = s2[i];
	free(s1);
	*new_line = '\0';
	return (c);
}

char	*ft_read(char **memory, int fd, size_t l_max, size_t l_buf)
{
	char	*buffer;
	char	*line;
	size_t	n;

	n = 0;
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(*memory, (l_max - l_buf), &n) && l_buf)
	{
		l_buf = read(fd, buffer, BUFFER_SIZE);
		if (!l_max)
			l_max = ft_strlen(*memory);
		l_max += l_buf;
		buffer[l_buf] = '\0';
		if (n)
			*memory = ft_strjoin(*memory, buffer, (l_max - l_buf) + n);
		else 
			*memory = ft_strjoin(*memory, buffer, l_max);
	}
	if (n)
		line = ft_strdup(*memory, (l_max - l_buf) + n);
	else
		line = ft_strdup(*memory, l_max);
	*memory = ft_strdup(*memory + (n + 1), l_max - n);
	return (ft_check_read(line, buffer, l_buf));
}

char	*get_next_line(int fd)
{
	static char	*memory[1024];
	char		*line;

	line = ft_read(&memory[fd], fd, 0, 1);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	//get_next_line(fd);
	while 
	return (0);
}
