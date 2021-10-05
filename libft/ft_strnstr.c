/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:30:33 by engooh            #+#    #+#             */
/*   Updated: 2021/09/25 14:00:44 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		n;

	if (!*little)
		return ((char *)big);
	n = ft_strlen(little);
	while (len-- && *big)
		if (!ft_strncmp(big++, little, n))
			return ((char *)--big);
	return (NULL);
}
