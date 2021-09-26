/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:41:22 by engooh            #+#    #+#             */
/*   Updated: 2021/09/26 11:59:57 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*p;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = malloc((l1 + l2 + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, l1);
	ft_strlcat(p, s2, l1 + l2 + 1);
	return (p);
}
