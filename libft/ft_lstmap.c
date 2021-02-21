/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:03:06 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/24 11:57:37 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *map;

	map = NULL;
	if (!lst || !f || !del)
		return (NULL);
	if (!(map = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&map, del);
		return (NULL);
	}
	map->next = ft_lstmap(lst->next, f, del);
	return (map);
}
