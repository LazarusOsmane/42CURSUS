/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 23:12:49 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 18:42:03 by engooh           ###   ########.fr       */
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
	while (n - 1 && *p1++ == *p2++)
		n--;
	return (*--p1 - *--p2);
}
