/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:41:22 by engooh            #+#    #+#             */
/*   Updated: 2021/11/25 11:31:20 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*p;
    char	*c;

    if (!s1 || !s2)
		    return (NULL);
    p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!p)
	  return (0);
    c = p;
    while (*s1)
	  *p++ = *s1++;
    while (*s2)
	  *p++ = *s2++;
    *p = '\0';
    return (c);
}
