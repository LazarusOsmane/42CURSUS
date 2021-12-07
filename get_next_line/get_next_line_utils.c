/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:52:19 by engooh            #+#    #+#             */
/*   Updated: 2021/12/07 17:03:10 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strchr(const char *s, long c, size_t *n)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			*n = i;
			return (*n);
		}
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*p;
	size_t	l;

	if (!s)
		return (NULL);
	//printf("CACHE : %s", s);
	l = 0;
	while (s[l] && s[l] != '\n')
		l++;
	if (s[l] == '\n')
		l++;
	//printf("Len : %ld\n", l);
	p = ft_calloc(l + 1, 4);
	l = -1;
	while (s[++l] && s[l] != '\n')
		p[l] = s[l];
	if (s[l] == '\n')
		p[l++] = '\n';
	p[l] = '\0';
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	p = ft_calloc(len + 1, 4);
	i = -1;
	while (s[++i + start])
		p[i] = s[i + start];
	free(s);
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*c;
	char	*p;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(ft_strlen(s1), 4);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	c = p;
	i = -1;
	while (s1[++i])
		*p++ = s1[i];
	i = -1;
	while (s2[++i])
		*p++ = s2[i];
	free(s1);
	*p = '\0';
	return (c);
}
