/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:53:17 by engooh            #+#    #+#             */
/*   Updated: 2021/11/25 19:37:48 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_intlen(long n, long l)
{
    if (n < 0)
	  n = -n;
    while (n)
    {
	  l++;
	  n /= 10;
    }
    return (l);
}

char	*ft_itoa(int n)
{
    long	l;
    long	m;
    char	*p;

    m = n;
    l = ft_intlen(n, 0);
   //printf("%ld\n", l);
    if (n && l == 0)
	  l++;
    p = malloc((l + 1 ) * sizeof(char));
    if (!p)
	  return (NULL);
    if (m < 0)
    {
	  m = -m;
	  p[0] = '-';
    }
    p[l] = '\0';
    while (l--)
    {
	  if (p[l] == '-')
		break ;
	  p[l] = '0' + (m % 10);
	  m /= 10;
    }
    return (p);
}
/*
int main(void)
{
    printf("%s", ft_itoa(156));
    return (0);
}*/
