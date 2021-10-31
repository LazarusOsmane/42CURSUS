/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 02:37:21 by engooh            #+#    #+#             */
/*   Updated: 2021/10/31 13:22:35 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_check_read(char *line, char *tmp, int l)
{
	if (l < 1)
	{
		if (line)
			free(line);
		if (tmp)
			free(tmp);
		return (NULL);
	}
	return (line);
}

char	*ft_strjoin(char *dst, char *src, long stt, long size)
{
	char	*new;

	if (!dst)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	new = malloc(sizeof(char) * (size + 1));
	if (!new || !src)
		return (NULL);
	ft_cpy(new, dst);
	ft_cat(new, src, stt, size + 1);
	free(dst);
	return (new);
}

char	*ft_strdup(char *dst, long stt, long size)
{
	char	*new;

	if (!size)
		return (NULL);
	new = malloc(sizeof(char) * (size + 1));
	if (!new || !dst)
		return (NULL);
	ft_cpy(new, dst + stt);
	return (new);
}

char	*ft_get_next_line(int fd)
{
	long		l;
	long		max;
	char		*line;
	static char	*tmp;
	char		buf[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	buf[0] = '\0';
	l = ft_strlen(tmp, 0);
	max = ft_strlen(tmp + l, 1);
	line = ft_strjoin(line, tmp, 0, l + 1);
	tmp = ft_strdup(tmp, l + (max / max), max);
	if (line && line[l] == '\n')
		return (line);
	max = l;
	while (!ft_strchr(buf, '\n', &max))
	{
		l = read(fd, buf, BUFFER_SIZE);
		if (l < 1)
			break ;
		max += l;
		buf[l] = '\0';
		line = ft_strjoin(line, buf, max - l, max + 1);
	}
	tmp = ft_strdup(buf, max + ((l - max) / (l - max)), l - max);
	return (ft_check_read(line, tmp, l));
}
