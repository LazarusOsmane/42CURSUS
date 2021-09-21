/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:34:00 by engooh            #+#    #+#             */
/*   Updated: 2021/09/16 02:10:56 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		while (n--)
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	else
		while (n--)
			*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (dest);
}
