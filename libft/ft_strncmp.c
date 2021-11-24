/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:55:52 by engooh            #+#    #+#             */
/*   Updated: 2021/11/24 13:50:17 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (!n)
	    return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n && *p1++ == *p2++ && *p1 && *p2)
	    n--;
	return (*--p1 - *--p2);
}
