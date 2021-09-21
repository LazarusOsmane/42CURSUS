/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 03:09:31 by engooh            #+#    #+#             */
/*   Updated: 2021/09/20 03:39:11 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	i = -1;
	if (size == 0)
		return (ft_strlen(src));
	while (src[++i] && size--)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
