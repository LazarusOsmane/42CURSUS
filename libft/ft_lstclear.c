/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:14:57 by engooh            #+#    #+#             */
/*   Updated: 2021/11/26 15:36:02 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	recursion(t_list *lst, void (*del)(void *))
{
    if (lst)
	  recursion(lst->next, (*del));
    ft_lstdelone(lst, (*del));
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    if (!lst || !*lst)
	  return ;
    recursion(*lst, (*del));
    *lst = NULL;
}
