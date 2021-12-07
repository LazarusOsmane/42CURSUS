/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:03:32 by engooh            #+#    #+#             */
/*   Updated: 2021/12/07 17:13:17 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(const char *s);
size_t	ft_strchr(const char *s, long c, size_t *n);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_free(char *s1, char *s2);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_read(int fd, char **cache, size_t max, long ret);
char	*get_next_line(int fd);

#endif
