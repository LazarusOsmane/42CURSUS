/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:50:59 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 15:48:05 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <libc.h>

int	ft_cntword(char const *s, char c, int n)
{
    while (*s)
    {
	  while (*s && *s == c)
		s++;
	  if (*s && *s != c)
		n++;
	  while (*s && *s != c)
		s++;
    }
    return (n);
}

char	**ft_split(char const *s, char c)
{
    int	l;
    int	i;
    char	**p;
    char	**q;

    if (!s)
	  return (NULL);
    l = ft_cntword(s, c, 0);
    p = malloc((l + 1) * sizeof(char *));
    if (!p)
	  return (NULL);
    p[l] = 0;
    q = p;
    while (l--)
    { 
	  while (*s && *s == c)
		s++;
	  i = 0;
	  while (s[i] && s[i] != c)
		i++;
	  *p++ = ft_substr(s, 0, i);
	  while (*s && *s != c)
		s++;
    }
    return (q);
}

/*
int main()
{
    int	n;
    char	**p;
    char	*s1;
    char	*s2;
    char	*s3;

    p = NULL;
    s1 = "\0aa\0bbb\0";
    p = ft_split(s1, '\0');
    printf("test 1\n");
    n = -1;
    while (++n <= 5)
	  printf("%s", p[n]);

    printf("\ntest 2");
    s2 = "                  olol";
    p = ft_split(s2, ' ');
    //while (**p)
    //  printf("%s", *p++);

    printf("\ntest 3");
    s3 = "olol                 ";
    p = ft_split(s3, ' ');
    //while (**p)
    //  printf("%s", *p++);
    return (0);
}*/
