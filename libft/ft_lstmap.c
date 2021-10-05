/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:43:01 by engooh            #+#    #+#             */
/*   Updated: 2021/10/05 00:22:47 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************* */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*n;

	p = NULL;
	n = NULL;
	while (lst)
	{
		n = ft_lstnew(f(lst->content));
		if (!n)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, n);
		lst = lst->next;
	}
	return (lst);
}
