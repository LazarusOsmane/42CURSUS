/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 03:47:08 by engooh            #+#    #+#             */
/*   Updated: 2021/11/24 12:02:52 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	d;

	d = 0;
	while (d < n && (dest || src))
		*((unsigned char *)(dest + d++)) = *((unsigned char *)src++);
	return (dest);
}
