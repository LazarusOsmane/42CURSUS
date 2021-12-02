/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:54 by engooh            #+#    #+#             */
/*   Updated: 2021/12/02 17:03:56 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != c)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char *dst, char *src, char size)
{
	char	*new;
	char	*c;

	if (!dst)
	{
		dst = (char *)malloc(sizeof(char));
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

char	*ft_read(char **memory, int fd, int *n)
{
	char	buffer[BUFFER_SIZE];
	int	l_buf;
	int	l_max;
	char	line;


	l_buf = 1;
	l_max = 0;
	while (!ft_strchr(buffer, '\n') && l_buf)
	{
		l_buf = read(fd, buffer, BUFFER_SIZE);
		l_max += l_buf;
		buffer[l_buf] = '\0';
		//printf("%s", buffer);
		*memory = ft_strjoin(*memory, buffer, l_max);
		//printf("%s", memory);
	}
	//printf("%s", memory);
	//printf("%s", memory);
	return (ft_check_read(*memory, l_buf));
}

char	*get_next_line(int fd)
{
	static char	*memory[1024];

	ft_read(&memory[fd], fd, &n);
	printf("##%d %s##", n, memory[fd] + n);
	return (memory[fd]);
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
	printf("\n%s", get_next_line(fd));
	return (0);
}

/*char	*ft_strjoin(line, buffer + n, memory, start)
{
	tmp = malloc(start)
	while (buffer != '\n')
		*tmp++ = *buffer++;
		start++;
	//memory = malloc( start - buffer + n - line )
	memory = buffer;
	tmp2 = buffer
	if (buffer != \0)
		*memory++ = *buffer++
	free(line)
	return (tmp)
}*/

while (buffer)
{
	if (buffer - 1 == '\n')
		line = line->next

			
	line = memory;

	memory++ != '\n'

	*memory = '\n' = n
	memory++
	*memory = \0
	memory++

}

