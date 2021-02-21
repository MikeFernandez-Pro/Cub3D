/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:42:29 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/23 15:11:35 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if ((unsigned char*)dst == (unsigned char*)src)
		return ((void*)dst);
	while ((i < n))
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
