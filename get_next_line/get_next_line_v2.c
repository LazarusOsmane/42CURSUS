/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:52:35 by engooh            #+#    #+#             */
/*   Updated: 2021/11/02 06:15:41 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

void ft_strlcpy(char *dst, char *src, long l)
{
	int i;

	if (!src)
		return ;
	i = -1;
	while (src[++i] && i < l)
		dst[i] = src[i];
	dst[i] ='\0';
}

void ft_strlcat(char *dst, char *src, long l, long max)
{
	int	i;

	if (!src)
		return ;
	i = -1;
	while (src[++i] && l + i < max)
	{
		dst[l + i] = src[i];
		if (dst[l + i] == '\n' && i++)
			break ;
	}
	dst[l + i] = '\0';
}

int	ft_strchr(char *str, int c, char **i)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str++ == c)
		{
			*i = str - 1;
			return (1);
		}
	}
	return (0);
}

char *ft_strjoin(char *dst, char *src, int l, int max)
{
	char	*new;

	if (!*src)
		return (NULL);
	if (!dst)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\n';
	}
	new = malloc(sizeof(char) * (max + 1));
	if (!new)
		return (NULL);
	new[0] = '\0';
	ft_strlcpy(new, dst, max - l);
	ft_strlcat(new, src, max - l, max);
	free(dst);
	return (new);
}

char *ft_strdup(char *str, int max)
{
	char *new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (max + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, str, max);
	return (new);
}

char	*ft_read(int fd, int l, int max)
{
	char	*i;
	char	*line;
	char	buf[BUFFER_SIZE];

	i = NULL;
	line = NULL;
	buf[0] = '\0';
	while (l && !ft_strchr(buf, '\n', &i))
	{	
		line = ft_strjoin(line, buf, l, max);
		l = read(fd, buf, BUFFER_SIZE);
		buf[l] = '\0';
		max += l;
	}
	if (i)
		line = ft_strjoin(line, buf, l + 1, max + 1);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	long	l;
	long	max;
	char	*line;
	//char	*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	l = 0; 
	max = l;
	line = ft_read(fd, l + 1, max);
	return (line);
}

#include <stdio.h>

int	main(void)
{
	//int	c;
	int	fd;
	char	*buf;

	//c = 0;
	buf = ""; 
	fd = open("main.c", O_RDONLY);
       	while (buf)
	{
		buf = ft_get_next_line(fd);
		printf("%s", buf);
		if (buf)
			free(buf);

	}
	return (0);
}
