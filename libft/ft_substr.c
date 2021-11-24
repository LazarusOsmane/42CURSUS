/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:45:46 by engooh            #+#    #+#             */
/*   Updated: 2021/11/24 18:46:35 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <libc.h>

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

/*
int main(void)
{
    char *p;

    p = NULL;
    p = ft_substr("hello le monde", 5, 10);
    printf("%s", p);
    return (0);
}*/
