/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:00:33 by engooh            #+#    #+#             */
/*   Updated: 2021/09/26 18:48:04 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	char	*p;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	l = 0;
	while (*s1 && !ft_strchr(set, s1[l]))
		l++;
	p = ft_substr(s1, 0, l);
	return (p);
}
