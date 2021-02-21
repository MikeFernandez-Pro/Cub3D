/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:45:50 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/24 11:39:34 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*cpy_dst;
	const char	*cpy_src;
	size_t		free_space_dest;
	size_t		size_dst;

	cpy_dst = dst;
	cpy_src = src;
	free_space_dest = dstsize;
	while (free_space_dest-- != 0 && *cpy_dst != '\0')
		cpy_dst++;
	size_dst = cpy_dst - dst;
	free_space_dest = dstsize - size_dst;
	if (free_space_dest == 0)
		return (size_dst + ft_strlen((char *)cpy_src));
	while (*cpy_src != '\0')
	{
		if (free_space_dest != 1)
		{
			*cpy_dst++ = *cpy_src;
			free_space_dest--;
		}
		cpy_src++;
	}
	*cpy_dst = '\0';
	return (size_dst + (cpy_src - src));
}
