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
#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
<<<<<<< HEAD
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
=======
	char	*c;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	c = p;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0'; 
	return (c);
>>>>>>> fd35b7e5ce88d5ed592ae18a58362b4141107cd2
}

/*int main()
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);

	if (!strcmp(res, "my favorite animal is the nyancat"))
		printf("TEST_SUCCESS");
	else
		printf("TEST_FAILED");

	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *tmp = ft_strjoin(s1, s2);
	char *res = ft_strjoin(tmp, s3);

	free(tmp);
	if (!strcmp(res, "my favorite animal is the nyancat"))
	{
		free(res);
		printf("TEST_SUCCESS");
	}
	else
	{
		free(res);
		printf("TEST_FAILED");
	}

	return (0);
}*/
