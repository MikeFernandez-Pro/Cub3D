/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:59:14 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/16 11:35:34 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*cpy_s1;
	unsigned char		*cpy_s2;

	i = 0;
	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cpy_s1[i] != cpy_s2[i])
			return ((int)(cpy_s1[i] - cpy_s2[i]));
		i++;
	}
	return (0);
}
