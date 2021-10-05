/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:24:16 by engooh            #+#    #+#             */
/*   Updated: 2021/10/04 23:28:04 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst)
	{
		if ((*alst)->next)
			ft_lstadd_back(&((*alst)->next), new);
		else
			(*alst)->next = new;
	}
	else
		*alst = new;
}
