/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischeck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:07:47 by engooh            #+#    #+#             */
/*   Updated: 2021/09/21 01:11:43 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>

int	ft_cmp(int c1, int c2)
{
	return (c1 - c2);
}

void	ft_ischeck(int (*f)(int c), int (*p)(int c), char *name)
{
	int		test_a[383];
	int		test_b[383];
	int		i;
	int		j;

	j = 0;
	i = -128;
	while (i++ < 255)
	{
		test_a[j] = f(i);
		test_b[j++] = p(i);
	}
	i = 0;
	while (i++ < 255)
	{
		if (ft_cmp(test_a[i], test_b[i]) != 0)
		{
			printf("%s KO: value cmp:%d *---* ft_function:%d *---* lib_function:%d\n", name, ft_cmp(test_a[i], test_b[i]), test_a[i], test_b[i]);
			return ;
		}
	}
	printf("%s OK\n", name);
}
/*
void	ft_memcheck(void)
{
	int		i; 
	int		j;
	char	test_a[32]; 
	char	test_b[32];
	int	test_c[32];
	int	test_d[32];

	i = -1;
	while (++i < 32)
	{
		test_a[i] = 0;
		test_b[i] = 0;
		test_c[i] = 0;
		test_d[i] = 0;
	}
	i = -1;
	while (++i < 32)
	{
		memset(test_a, i, i);
		ft_memset(test_b, i, i);
		memset(test_c, i, i*4);
		ft_memset(test_d, i, i*4);
		j = -1;
		while (++j < 32)
		{
			if ((ft_cmp(test_a[j], test_b[j]) != 0) || (ft_cmp(test_c[j], test_d[j]) != 0))
			{

				printf("ft_memset KO: char value test:%c lib_function:%c ft_function:%c\n", i, test_a[j], test_b[j]);
				printf("ft_memset KO: int value test:%d lib_function:%d ft_function:%d\n", i, test_c[j], test_d[j]);
				return ;
			}
		}
	}
	printf("ft_memset OK\n");
}


void	ft_bzerocheck(void)
{
	int	i;
	int	j;
	char 	test_a[32];
	char	test_b[32];
	int	test_c[32];
	int	test_d[32];

	i = 0;
	while (i < 32)
	{
		test_a[i] = 1;
		test_b[i] = 1;
		test_c[i] = 1;
		test_d[i++] = 1;
	}
	i = -1;
	while (++i < 32)
	{
		ft_bzero(test_a, i);
		bzero(test_b, i);
		ft_bzero(test_c, i);
		bzero(test_d, i);
		j = -1;
		while (++j < 32)
		{
			if ((ft_cmp(test_a[j], test_b[j]) != 0) || (ft_cmp(test_c[j], test_d[j]) != 0))
			{

				printf("ft_memset KO: char value test:%c lib_function:%c ft_function:%c\n", i, test_a[j], test_b[j]);
				printf("ft_memset KO: int value test:%d lib_function:%d ft_function:%d\n", i, test_c[j], test_d[j]);
				return ;			
			}
		}
	}
	printf("ft_bzero OK\n");
}


void	ft_memcpycheck(void)
{
	int		i; 
	int		j;
	int		x;
	int		y;
	char	src_a[32]; 
	char	dst_a[32];
	char	src_b[32];
	char	dst_b[32];

	int	src_c[32]; 
	int	dst_c[32];
	int	src_d[32];
	int	dst_d[32];

	i = -1;
	while (++i < 32)
	{
		src_a[i] = 0;
		dst_a[i] = 0;
		src_b[i] = 0;
		dst_b[i] = 0;


		src_c[i] = 0;
		dst_c[i] = 0;
		src_d[i] = 0;
		dst_d[i] = 0;
	}

	i = -1;
	while (++i < 32)
	{
		y = -1;
		x = 97;
		while (++y < i)
		{
			src_a[y] = x;
			src_b[y] = x;
			src_c[y] = x;
			src_d[y] = x++;
		}
		memcpy(dst_a, (const char*)src_a, i);
		ft_memcpy(dst_b, (const char*)src_b, i);
		memcpy(dst_c, (const int*)src_c, i*4);
		ft_memcpy(dst_d, (const int*)src_d, i*4);
		j = -1;
		while (++j < 32)
		{
			if ((ft_cmp(dst_a[j], dst_b[j]) != 0) || (ft_cmp(dst_c[j], dst_d[j]) != 0))
			{

				printf("ft_memcpy KO: char value test:%s lib_function:%s ft_function:%s\n", src_a, dst_a, dst_b);
				printf("ft_memcpy KO: int value test:%s  lib_function:%s ft_function:%s\n", (char *)src_c, (char *)dst_c, (char *)dst_d);
				return ;
			}
		}
	}
	printf("ft_memcpy OK\n");
}

void ft_memmovecheck(void)
{
	int	i;
	int	j;
	int	x;
	int	y;

	char	src_a[6];
	char	src_b[6];
	int	src_c[6];
	int	src_d[6];

	i = -1;
	j = 97;
	while (++i < 6)
	{
		if  (i == 5)
			j = '\0';
		src_a[i] = j;
		src_b[i] = j;
		src_c[i] = j;
		src_d[i] = j++;
	}
	i = -1;
	j = 1;
	while (++i < 5 && ++j < 5)
	{
		memmove(src_a+i, src_a+j, i);
		ft_memmove(src_b+i, src_b+j, i);
		x = -1;
		while (++x < 5)
		{
			if ((ft_cmp(src_a[x], src_b[x]) != 0) || (ft_cmp(src_c[x], src_d[x]) != 0))
			{
				printf("ft_memmove KO: char value test:%s lib_function:%s ft_function:%s\n", src_a, src_a, src_b);
				printf("ft_memmove KO: int value test:%s  lib_function:%s ft_function:%s\n", (char *)src_c, (char *)src_c, (char *)src_d);
				return ;
			}
		}
		x = -1;
		y = 97;
		while (++x < 6)
		{
			if  (x == 5)
				y= '\0';
			src_a[x] = y;
			src_b[x] = y;
			src_c[x] = y;
			src_d[x] = y++;
		}
	}
	printf("ft_memove OK\n");
}

void ft_checkstrlcat(void)
{
	char    src_a[12] = "hello";
	char    src_b[12] = "hello";
	char    dst_a[12] = "qwertyu";
	char    dst_b[12] = "qwertyu";
	int     i;
	int     p;
	int     r;

	i = -1;
	while (++i < 12)
	{
		if ((r = ft_strlcat(dst_a, src_a, i))  != (p = strlcat(dst_b, src_b, i)))
		{
			printf("ft_strlcat KO: return valu error --- index:%d ft_function:%d  lib_function:%d\n", i, r, p);
			printf("%s000%s", dst_a, dst_b);
			return ;
		}
		r = -1;
		while (dst_b[++r])
		{
			if (ft_cmp(dst_b[r], dst_a[r]) != 0)
			{
				printf("KO: return valu error --- index:%d ft_function:%d  lib_function:%d\n", i, r, p);
				printf("%s000%s", dst_a, dst_b);
				return ;
			}
		}
	}
	printf("ft_strlcat OK\n");
}

void ft_checkstrlcpy(void)
{
	char    src_a[12] = "hello";
	char    src_b[12] = "hello";
	char    dst_a[12] = "qwertyu";
	char    dst_b[12] = "qwertyu";
	int     i;
	int     p;
	int     r;

	i = -1;
	while (++i < 14)
	{
		if ((r = ft_strlcpy(dst_a, src_a, i))  != (p = strlcpy(dst_b, src_b, i)))
		{
			printf("ft_strlcpy KO: return valu error --- index:%d ft_function:%d  lib_function:%d\n", i, r, p);
			printf("%s000%s", dst_a, dst_b);
			return ;
		}
		r = -1;
		while (dst_b[++r])
		{
			if (ft_cmp(dst_b[r], dst_a[r]) != 0)
			{
				printf("ft_strlcpy KO: return valu error --- index:%d ft_function:%d  lib_function:%d\n", i, r, p);
				printf("%s000%s", dst_a, dst_b);
				return ;
			}
		}
	}
	printf("ft_strlcpy OK\n");
}
*/

void	ft_checktou(char *name)
{
	int		test_a[383];
	int		test_b[383];
	int		i;
	int		j;

	j = 0;
	i = -128;
	while (i++ < 255)
	{
		test_a[j] = ft_toupper(i);
		test_b[j++] = toupper(i);
	}
	i = 0;
	while (i++ < 255)
	{
		if (ft_cmp(test_a[i], test_b[i]) != 0)
		{
			printf("%s KO: value cmp:%d *---* ft_function:%d *---* lib_function:%d\n", name, ft_cmp(test_a[i], test_b[i]), test_a[i], test_b[i]);
			return ;
		}
	}
	printf("%s OK\n", name);
}

void	ft_checktol(char *name)
{
	int		test_a[383];
	int		test_b[383];
	int		i;
	int		j;

	j = 0;
	i = -128;
	while (i++ < 255)
	{
		test_a[j] = ft_tolower(i);
		test_b[j++] = tolower(i);
	}
	i = 0;
	while (i++ < 255)
	{
		if (ft_cmp(test_a[i], test_b[i]) != 0)
		{
			printf("%s KO: value cmp:%d *---* ft_function:%d *---* lib_function:%d\n", name, ft_cmp(test_a[i], test_b[i]), test_a[i], test_b[i]);
			return ;
		}
	}
	printf("%s OK\n", name);
}

int	main(void)
{
	/*ft_ischeck(ft_isalpha, isalpha, "ft_isalpha");
	ft_ischeck(ft_isdigit, isdigit, "ft_isdigit");
	ft_ischeck(ft_isalnum, isalnum, "ft_isalnum");
	ft_ischeck(ft_isascii, isascii, "ft_isascii");
	ft_ischeck(ft_isprint, isprint, "ft_isprint");
	ft_memcheck();
	ft_bzerocheck();
	ft_memcpycheck();
	ft_checkstrlcat();
	ft_checkstrlcpy();*/
	ft_checktou("ft_toupper");
	ft_checktol("ft_tolower");
	printf("ok");
	return (0);
}
