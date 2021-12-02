/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:54 by engooh            #+#    #+#             */
/*   Updated: 2021/12/01 19:27:01 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(char *str, int c, int *n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
		{
			*n = --i;
			return (str);
		}
	}
	return (NULL);
}

char	*ft_strjoin(char *dst, char *src, char size)
{
	char	*new;
	char	*c;

	if (!dst)
	{
		dst = (char *)malloc(sizeof(char) * 1);
		if (!dst)
			return (NULL);
		*dst = '\0';
	}
	new = malloc(sizeof(char) * (size + 1));
	if (!new || !src)
		return (NULL);
	c = new;
	while (*dst)
		*new++ = *dst++;
	while (*src)
		*new++ = *src++;
	*new = '\0'; 
	return (c);
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

char	*ft_read(char *memory, int fd, int *n)
{
	char	buffer[BUFFER_SIZE];
	int		l_buf;
	int		l_max;

	l_buf = 1;
	l_max = 0;
	while (ft_strchr(buffer, '\0', n) && l_buf)
	{
		l_buf = read(fd, buffer, BUFFER_SIZE);
		l_max += l_buf;
		buffer[l_buf] = '\0';
		memory = ft_strjoin(memory, buffer, l_max);
	}
	printf("%s", memory);
	return (ft_check_read(memory, l_buf));
}

char	*get_next_line(int fd)
{
	static char	*memory[1024];
	int			n;

	n = 0;
	memory[fd] = ft_read(memory[fd], fd, &n);
	printf("%s", memory[fd]);
	return (NULL);
	//return (ft_strjoin("HELLO", memory[fd], 8));
}

int	main(void)
{
	char	*n;
	char	*l = "helllooooooo";

	printf("%s", get_next_line(0));
	return (0);
}
