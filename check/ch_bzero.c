/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:26:24 by engooh            #+#    #+#             */
/*   Updated: 2021/09/09 14:59:37 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <libft.h>

int ft_cmp(unsigned char c1, unsigned char c2)
{
	  return (c1 - c2);
}

void ft_checkbzero(int size, int n)
{
	  char	test1[size];
	  char	test2[size];

	  int		test3[size];
	  int		test4[size];
	  int		i;

	  i = 0;
	  printf("Test for ft_bzero\n");
	  while (i < n)
	  {
		    printf("size test:%d *---* value test:%d *---* ft_function:%s *---* lib_function:%s\n", (char *)ft_bzero(test1, i), (char *)bzero(test2, i));
		    i++;
	  }

	  i = 0;
	  while (i < size)
	  {
		    if (ft_cmp(test1[i], test2[i]) != 0)
		    {
				printf("KO");
				return ;
		    }	    
		    i++;
	  }
	  printf("OK");
}

int main(int ac, char **av)
{
	  ft_checkbzero(atoi(av[1]),atoi(av[2]);
	  return (0);
}


