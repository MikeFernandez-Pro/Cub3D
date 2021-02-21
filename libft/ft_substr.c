/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:12:20 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/22 12:11:17 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	j = 0;
	if (s)
	{
		while (i < start)
			i++;
	}
	if (start >= (size_t)ft_strlen((char*)s))
		len = 0;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s && j < len && s[i])
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
