/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:20:23 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 18:22:54 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		p[len] = '\0';
		return (p);
	}
	ft_memcpy(p, s + start, len);
	p[len] = '\0';
	return (p);
}
