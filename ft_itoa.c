/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:53:17 by engooh            #+#    #+#             */
/*   Updated: 2021/09/28 16:34:02 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_intlen(long n, long l)
{
	if (n < 0)
	{
		l++;
		n = -n;
	}
	while (l++ < n)
		n /= 10;
	return (l);
}

char	*ft_itoa(int n)
{
	long	l;
	long	m;
	char	*p;

	m = n;
	l = ft_intlen(n, 1);
	p = malloc(l * sizeof(char));
	if (!p)
		return (NULL);
	if (m < 0)
	{
		m = -m;
		p[0] = '-';
	}
	p[--l] = '\0';
	while (l)
	{
		if (p[--l] == '-')
			break ;	
		p[l] = '0' + (m % 10);
		m /= 10;
	}
	return (p);
}
