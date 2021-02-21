/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:05:36 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/21 11:17:52 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const	char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dst == NULL || src == NULL)
		return (0);
	while (src[count] != '\0')
		++count;
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
