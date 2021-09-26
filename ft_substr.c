/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:45:46 by engooh            #+#    #+#             */
/*   Updated: 2021/09/26 18:45:42 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (len)
		p = ft_memcpy(p, s + start, len);
	p[len] = '\0';
	return (p);
}
