/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:42:49 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/24 11:59:35 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	cpt;

	if (!lst)
		return (0);
	cpt = 0;
	while (lst)
	{
		lst = lst->next;
		cpt++;
	}
	return (cpt);
}
