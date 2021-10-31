/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 02:53:19 by engooh            #+#    #+#             */
/*   Updated: 2021/10/31 13:18:21 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

#ifndef GET_NEXT_LINEH
# define GET_NEXT_LINEH
char	*ft_get_next_line(int fd);
int	ft_strlen(char *str, int m);
int	ft_cpy(char *dst, char *src);
long	*ft_strchr(char *str, long c, long *n);
void	ft_cat(char *dst, char *src, long l, long size);
#endif
