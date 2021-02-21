/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:19:08 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/28 11:51:48 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_free(char *str, size_t n)
{
	unsigned int	i;
	char			*dst;

	if (!str)
		return (NULL);
	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
