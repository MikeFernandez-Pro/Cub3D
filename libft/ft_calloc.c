/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:24:36 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/24 12:02:06 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*mem;
	unsigned int	cpt;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(mem = malloc(size * count)))
		return (NULL);
	cpt = (size * count);
	while (cpt > 0)
	{
		cpt--;
		mem[cpt] = '\0';
	}
	return (mem);
}
