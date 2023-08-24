/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:24:03 by osarsar           #+#    #+#             */
/*   Updated: 2022/10/29 23:24:09 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*debut;

	if (!lst)
		return (0);
	debut = NULL;
	while (lst != NULL)
	{
		p = ft_lstnew(f(lst->content));
		if (!p)
		{
			ft_lstclear(&debut, del);
			return (0);
		}
		ft_lstadd_back(&debut, p);
		lst = lst->next;
	}
	return (debut);
}
