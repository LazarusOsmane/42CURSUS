/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:08:55 by engooh            #+#    #+#             */
/*   Updated: 2021/12/07 18:44:16 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_free(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	p = malloc((nmemb + 1) * size);
	if (!p)
		return (NULL);
	*p = '\0';
	return (p);
}

char	*ft_read(int fd, char **cache, size_t max, long ret)
{
	char	*buffer;
	char	*line;
	size_t	n;

	n = 0;
	buffer = ft_calloc(BUFFER_SIZE, 4);
	while (!ft_strchr(*cache, '\n', &n) && ret)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret <= 0)
			return (ft_free(buffer, *cache));
		buffer[ret] = '\0';
		//printf("BUFF : %s--\n\n", buffer);
		max += ret;
		*cache = ft_strjoin(*cache, buffer);
		
	}
	printf("--CACHE2:%s--\n", *cache);
	printf("--BUFFER:%s--\n", buffer);
	free(buffer);
	line = ft_strdup(*cache);
	//printf("LINE : %s", line);
	*cache = ft_substr(*cache, n + 1, ft_strlen(*cache + n));
	printf("--CACHE3:%s--", *cache);
	//printf("Sortie du read : %s", line);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cache;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!cache)
		cache = ft_calloc(1, 4);
	printf("--CACHE1:%s--\n", cache);
	line = ft_read(fd, &cache, ft_strlen(cache), 1);
	return (line);
}


int main(void)
{
	int 	fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	/*printf("LINE = %s", str = get_next_line(fd));
	free(str);
	printf("LINE = %s", str = get_next_line(fd));
	free(str);*/


	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	printf("%s", str);
	return (0);
}
