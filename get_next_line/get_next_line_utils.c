/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 02:38:30 by engooh            #+#    #+#             */
/*   Updated: 2021/10/31 13:41:27 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str, int m)
{
	int	n;

	n = 0;
	if (m == 0)
		while (str && str[n] && str[n] != '\n')
			n++;
	else if (str++)
		while (str && str[n])
			n++;
	return (n);
}

int	ft_cpy(char *dst, char *src)
{
	long	n;

	if (!src || !dst)
		return (0);
	n = -1;
	while (src[++n])
		dst[n] = src[n];
	dst[n] = '\0';
	return (1);
}

void	ft_cat(char *dst, char *src, long l, long size)
{
	int	i;

	if (!src || !dst)
		return ;
	i = -1;
	while (src[++i] && l + i < size)
	{
		dst[l + i] = src[i];
		if (dst[l + i] == '\n')
		{
			dst[++l + i] = '\0';
			return ;
		}
	}
	if (dst[l + i])
		dst[l + i] = '\0';
}

long	*ft_strchr(char *str, long c, long *n)
{
	int	m;

	if (!(str) && !*(str))
		return (NULL);
	m = -1;
	while (str[++m])
	{
		if (str[m] == c)
		{
			*n = m;
			return (n);
		}
	}
	return (NULL);
}
