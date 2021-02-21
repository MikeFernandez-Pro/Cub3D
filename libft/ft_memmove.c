/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:01:01 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/21 11:14:59 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cpy;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	cpy = (char*)dst;
	i = 0;
	if (cpy > (char*)src)
	{
		while (i < len)
		{
			cpy[len - 1] = ((char*)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return ((void*)dst);
}
