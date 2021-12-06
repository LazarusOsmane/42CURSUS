/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:54 by engooh            #+#    #+#             */
/*   Updated: 2021/12/06 15:12:07 by engooh           ###   ########.fr       */
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

char	*ft_check_read(char *str, char *buffer, int err)
{
	if (err && str)
	{
		free(buffer);
		return (str);
	}
	if (err < 1)
	{
		free(str);
		free(buffer);
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

	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		new[i] = str[i];
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2, size_t start, size_t size)
{
	char	*new_line;
	char	*c;
	size_t	i;

	if (!s1)
		s1 = ft_strdup("", 0);
	new_line = malloc(sizeof(char) * (size + 1));
	if (!new_line || !s2)
		return (NULL);
	c = new_line;
	i = start;
	while (s1[++i])
		*new_line++ = s1[i];
	free (s1);
	i = -1;
	while (s2[++i])
		*new_line++ = s2[i];
	*new_line = '\0';
	return (c);
}

char	*ft_read(char *memory, int fd, size_t l_max, size_t l_buf)
{
	char	*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	char	*line;
	size_t	n;

	if (!buffer)
		return (NULL);
	n = 0;
	*buffer = '\0';
	while (!ft_strchr(memory, (l_max - l_buf), &n) && l_buf)
	{
		l_buf = read(fd, buffer, BUFFER_SIZE);
		if (l_buf < 1 && !*memory)
			return (ft_check_read(memory, buffer, l_buf));
		if (!l_max)
			l_max = ft_strlen(memory);
		l_max += l_buf;
		buffer[l_buf] = '\0';
		if (n)
			memory = ft_strjoin(memory, buffer, 0, (l_max - l_buf) + n);
		else 
			memory = ft_strjoin(memory, buffer, 0, l_max);
	}
	if (n)
		line = ft_strdup(memory, (l_max - l_buf) + n);
	else
		line = ft_strdup(memory, l_max);
	memory = ft_strjoin(memory, memory, (l_max - l_buf) + n, l_max - n);
	return (ft_check_read(line, buffer, l_buf));
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!memory)
		memory = ft_strdup("", 0);
	line = ft_read(memory, fd, 0, 1);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*str;


	(void)argc;
	(void)argv;
	fd = open("bible.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	str = malloc(sizeof(char) * 1);
	*str = '\0';
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (str)
			free(str);
	}
	close(fd);
	return (0);
}
