/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 23:12:49 by engooh            #+#    #+#             */
/*   Updated: 2021/09/27 13:15:58 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*p1;
	unsigned const char	*p2;

	if (n == 0)
		return (0);
	p1 = s1;
	p2 = s2;
	while (n-- && *p1 && *p2 && *p1++ == *p2++)
	{
	}
	return (*--p1 - *--p2);
}
