/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:50:59 by engooh            #+#    #+#             */
/*   Updated: 2021/11/23 17:30:07 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_skip_charset(char const *s, char c)
{
	while (*s && !ft_memcmp(s, &c, 1))
		s++;
	while (*s && ft_memcmp(s, &c, 1))
		s++;
	return ((char *)s);
}

int	ft_cntword(char const *s, char c, int n)
{
	while (*s)
	{
		while (*s && !ft_memcmp(s, &c, 1))
			s++;
		if (*s && ft_memcmp(s++, &c, 1))
			n++;
		while (*s && ft_memcmp(s, &c, 1))
			s++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int	l;
	int	n;
	char	**p;

	l = ft_cntword(s, c, 0) + 1;
	p = malloc(l * sizeof(char *));
	if (!p)
		return (NULL);
	n = 0;
	while (n < l)
	{
		p[n++] = ft_strtrim(s, &c);
		s = ft_skip_charset(s, c);
	}
	p[n] = 0;
	return (p);
}
