/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 03:47:08 by engooh            #+#    #+#             */
/*   Updated: 2021/09/09 22:21:12 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stddef.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	  while (n--)
		    *((unsigned char *)dest++) = *((unsigned char *)src++);
	  return (dest);
}
